import customtkinter
from tkinter import messagebox
from PIL import Image
from pathlib import Path

gl_state = {'title': 'Movie Ticketing Software'}

# Movie data: keep paths here
movies = {
    "Dhurandhar": {"poster": "posters/Dhurandhar.jpeg"},
    "Happy Patel": {"poster": "posters/Happy Patel.jpeg"},
    "Avatar": {"poster": "posters/Avatar.jpeg"}
}

def loadFonts():
    fp = Path('fonts')
    if fp.exists() and fp.is_dir():
        for f in fp.iterdir():
            try:
                customtkinter.FontManager.load_font(str(f))
            except Exception:
                pass

def select_venue(movie: str):
    # open a Toplevel (not a second CTk) to avoid multiple mainloops
    win = customtkinter.CTkToplevel()
    win.title(f"{movie} - Venues")
    win.geometry("600x400")
    lbl = customtkinter.CTkLabel(win, text=f"Select venue for {movie}", font=("Product Sans Light", 18))
    lbl.pack(padx=20, pady=20)
    # Add your venue UI here

def create_ctk_image(pil_img, size):
    # Return CTkImage created from PIL image (both dark & light)
    return customtkinter.CTkImage(dark_image=pil_img, light_image=pil_img, size=size)

def show_movie_choose(root):
    # Remove all existing children from root and build the movie chooser UI
    for w in root.winfo_children():
        w.destroy()

    root.title(f"{gl_state['title']} - Movies")
    root.geometry("900x700")
    root.grid_rowconfigure(1, weight=1)
    root.grid_columnconfigure(0, weight=1)

    # Title bar
    title_bar = customtkinter.CTkFrame(master=root, height=60, corner_radius=0, fg_color="#03A9F4")
    title_bar.grid(row=0, column=0, sticky="ew")
    title_bar.grid_columnconfigure(0, weight=1)
    title_bar.grid_columnconfigure(1, weight=0)

    customtkinter.CTkLabel(
        title_bar,
        text=f"Hello, {name.get()}",
        text_color="white",
        height=40,
        font=("Product Sans Medium", 22)
    ).grid(row=0, column=0, padx=10, sticky="w")

    switch = customtkinter.CTkSwitch(
        title_bar, textvariable=switch_text, font=('Regular Sans Light', 14),
        command=switch_event, variable=switch_var, onvalue="on", offvalue="off"
    )
    switch.grid(row=0, column=1, sticky="e", padx=12, pady=10)

    # Main body (scrollable)
    body = customtkinter.CTkFrame(master=root)
    body.grid(row=1, column=0, sticky="nsew")
    body.grid_rowconfigure(1, weight=1)
    body.grid_columnconfigure(0, weight=1)

    # Heading
    customtkinter.CTkLabel(body, text="Recommended Movies", justify="left", font=("Product Sans Light", 20))\
        .grid(row=0, column=0, padx=10, pady=10, sticky="w")

    # Scrollable area for posters
    scroll = customtkinter.CTkScrollableFrame(master=body, corner_radius=0)
    scroll.grid(row=1, column=0, sticky="nsew", padx=6, pady=(0, 6))
    scroll.grid_rowconfigure(0, weight=1)
    scroll.grid_columnconfigure(0, weight=1)

    container = customtkinter.CTkFrame(master=scroll)
    container.grid(row=0, column=0, sticky="nw", padx=6, pady=6)

    # Load PIL images (keep originals)
    movie_items = []
    for title, meta in movies.items():
        path = meta.get("poster", "")
        pil_img = None
        try:
            pil_img = Image.open(path).convert("RGBA")
        except Exception:
            # fallback: create a blank image if poster missing
            pil_img = Image.new("RGBA", (200, 300), (200, 200, 200, 255))
        movie_items.append({"title": title, "pil": pil_img, "ctk_img": None, "btn": None})

    # Button factory: create CTkButtons and keep references
    poster_min_w, poster_max_w = 120, 360
    poster_aspect = 1.5  # height = width * aspect
    pad_x = 8
    pad_y = 8

    # create placeholder buttons (images will be set later)
    for i, m in enumerate(movie_items):
        btn = customtkinter.CTkButton(container, text="", width=0, height=0, corner_radius=6,
                                     fg_color="transparent", hover=False,
                                     command=lambda t=m["title"]: select_venue(t))
        btn.grid(row=0, column=i)  # temporary grid; will be rearranged
        m["btn"] = btn

    # Debounced resize handler to compute columns & sizes
    resize_after_id = {"id": None}

    def arrange_posters(event=None):
        if resize_after_id["id"]:
            root.after_cancel(resize_after_id["id"])
            resize_after_id["id"] = None
        # schedule the arrangement so geometry is settled
        resize_after_id["id"] = root.after(80, _arrange_posters)

    def _arrange_posters():
        resize_after_id["id"] = None
        # available width inside scroll container
        avail = scroll.winfo_width()
        if avail <= 1:
            avail = root.winfo_width()
        if avail <= 1:
            avail = 800

        # compute number of columns that fit respecting min width
        # include padding between items
        # try to fit poster_min_w...poster_max_w sized tiles
        max_columns = max(1, avail // (poster_min_w + pad_x))
        # compute actual columns by checking poster width within allowed bounds
        columns = max(1, max_columns)
        # compute width per poster
        total_pad = pad_x * (columns + 1)
        raw_width = (avail - total_pad) // columns
        poster_w = max(poster_min_w, min(poster_max_w, raw_width))
        poster_h = int(poster_w * poster_aspect)

        # place posters into grid
        for widget in container.winfo_children():
            widget.grid_forget()

        for idx, m in enumerate(movie_items):
            col = idx % columns
            row = idx // columns

            # create resized CTkImage for this size (must keep reference)
            try:
                resized = m["pil"].resize((poster_w, poster_h), Image.Resampling.LANCZOS)
            except Exception:
                resized = m["pil"].resize((poster_w, poster_h))
            ctk_img = create_ctk_image(resized, size=(poster_w, poster_h))
            m["ctk_img"] = ctk_img
            m["btn"].configure(image=ctk_img, width=poster_w, height=poster_h)
            m["btn"].grid(row=row, column=col, padx=pad_x, pady=pad_y, sticky="n")

        # set container grid columns weights so items align left to right
        for c in range(columns):
            container.grid_columnconfigure(c, weight=1)

    # bind resizing
    root.bind("<Configure>", arrange_posters)
    scroll.bind("<Configure>", arrange_posters)
    container.bind("<Configure>", arrange_posters)

    # First arrangement after idle so geometry is ready
    root.after(100, arrange_posters)


# theme and defaults
customtkinter.set_appearance_mode("Light")
customtkinter.set_default_color_theme("blue")

def switch_event():
    if switch_var.get() == "on":
        customtkinter.set_appearance_mode("Dark")
        switch_text.set("Light")
    else:
        customtkinter.set_appearance_mode("Light")
        switch_text.set("Dark")
    # debug prints (optional)
    # print("switch toggled, current value:", switch_var.get())
    # print(switch_text.get())

def checkName(event=None):
    if entry.get().strip() == "":
        messagebox.showerror("Error", "Name can't be empty")
    else:
        name.set(entry.get().strip())
        show_movie_choose(app)


# --- App start (single CTk window) ---
app = customtkinter.CTk()
loadFonts()
switch_var = customtkinter.StringVar(value="off")
switch_text = customtkinter.StringVar(value="Dark")
name = customtkinter.StringVar()

app.title(gl_state['title'])
app.geometry("420x140")
app.grid_columnconfigure(0, weight=1)
app.grid_rowconfigure(0, weight=1)

# Initial login UI (simple and centered)
frame = customtkinter.CTkFrame(master=app, corner_radius=8)
frame.grid(row=0, column=0, padx=20, pady=20, sticky="nsew")
frame.grid_columnconfigure(0, weight=1)

entry = customtkinter.CTkEntry(frame, placeholder_text="Enter Name")
entry.grid(row=0, column=0, pady=(6, 12), padx=6, sticky="ew")
entry.bind("<Return>", checkName)

button = customtkinter.CTkButton(frame, text="Submit", command=checkName, corner_radius=16, hover_color="#4158D0")
button.grid(row=1, column=0, pady=(0, 6))

app.mainloop()
