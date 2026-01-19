import customtkinter
from tkinter import messagebox
from PIL import Image, ImageDraw
from pathlib import Path

gl_state={'title':'Movie Ticketing Software'}



movies = {
            "Dhurandhar": {"poster": "posters/Dhurandhar.jpeg", "genre": "Action / Drama"},
            "Happy Patel": {"poster": "posters/Happy Patel.jpeg", "genre": "Comedy"},
            "Avatar": {"poster": "posters/Avatar.jpeg", "genre": "Sci-Fi / Adventure"}
        }

def loadFonts():
    fp=Path('fonts')
    # print([entry for entry in fp.iterdir()])
    for f in fp.iterdir():
        customtkinter.FontManager.load_font(str(f))

def add_rounded_corners(image_path, radius):
    """
    Applies rounded corners to an image.

    Args:
        image_path (str): The file path to the input image.
        radius (int): The radius of the rounded corners in pixels.

    Returns:
        Image: A new Pillow Image object with rounded corners.
    """
    im = Image.open(image_path).convert("RGBA")
    width, height = im.size

    # Create a new image for the alpha mask with mode 'L' (grayscale)
    mask = Image.new("L", (width, height), 255)
    draw = ImageDraw.Draw(mask)

    # Draw black rounded rectangles on the corners of the mask
    # This leaves the center white (opaque) and corners black (transparent)
    draw.rounded_rectangle([0, 0, width, height], radius, fill=0)

    # Use Image.composite to combine the original image with the mask
    # The mask parameter of the paste method could also be used
    rounded_im = Image.composite(im, Image.new("RGBA", (width, height), (0, 0, 0, 0)), mask)

    return rounded_im

def selectVenueTimeFrame(root,movie:str):
    pass


def getWindow(height,width,resize=True,title=gl_state['title']):
    app=customtkinter.CTk()
    app.title(title)
    app.geometry(f"{width}x{height}")
    app.resizable(resize,resize)
    return app

# def switch_event():
#     if switch_var.get()=="on":
#         customtkinter.set_appearance_mode("Dark")
#         switch_text.set("Light")
        
#     else:
#         customtkinter.set_appearance_mode("Light")
#         switch_text.set("Dark")
#     print("switch toggled, current value:", switch_var.get())
#     print(switch_text.get())

def select_venue(movie:str):
    # app=getWindow(600,800,title=f"{movie} ")
    # app.mainloop()
    p=customtkinter.CTkToplevel(app)
    p.geometry("400x400")
    p.title(movie)
    topAppBarFrame(p,movie)

def topAppBarFrame(root,title:str):
    title_bar = customtkinter.CTkFrame(master=root, height=60, corner_radius=0,fg_color="#03A9F4")
    title_bar.pack(side="top", fill="x")
    title_bar.grid_columnconfigure(1, weight=1)
    customtkinter.CTkLabel(title_bar,text=title,text_color="white",height=40,font=("Product Sans Medium",22)).grid(row=0,column=0,padx=10,sticky="w")
    # switch = customtkinter.CTkSwitch(title_bar, textvariable=switch_text, font=('Regular Sans Light',14),command=switch_event,variable=switch_var, onvalue="on", offvalue="off")
    switch = customtkinter.CTkSwitch(
        title_bar, textvariable=switch_text, font=('Regular Sans Light', 14),
        command=switch_event, variable=switch_var, onvalue="on", offvalue="off"
    )
    switch.grid(row=0,column=1,sticky="e",padx=2,pady=10)

def movieCard(body,movie:str,column):
    card = customtkinter.CTkFrame(body, corner_radius=15, width=220)
    card.grid(row=1, column=column, padx=15, pady=15)

    # Image Handling (Fallback to colored box if image fails)
    try:
        img_data = Image.open(movies[movie]['poster'])
        # img_data=add_rounded_corners(movies[movie]['poster'],radius=0)
        poster_img = customtkinter.CTkImage(light_image=img_data, dark_image=img_data, size=(200, 280))
        img_lbl = customtkinter.CTkLabel(card, image=poster_img, text="")
        img_lbl.pack(pady=10, padx=10)
    except Exception:
        placeholder = customtkinter.CTkFrame(card, width=200, height=280, fg_color="gray")
        placeholder.pack(pady=10, padx=10)

    # Labels
    customtkinter.CTkLabel(card, text=movie, font=("Product Sans", 16, "bold")).pack(padx=10)
    customtkinter.CTkLabel(card, text=movies[movie]['genre'], font=("Product Sans", 12), text_color="gray").pack(padx=10, pady=(0, 10))

    # Select Button
    btn = customtkinter.CTkButton(card, text="Book Now", 
                                    command=lambda t=movie: select_venue(movie),
                                    corner_radius=8, height=32, width=180)
    btn.pack(pady=(0, 15), padx=10)


def movie_choose(app):
    #app=getWindow(600,800)
    for w in app.winfo_children():
        w.destroy()
    app.geometry("800x600")
    app.title(gl_state['title'])
    topAppBarFrame(app,title=f"Hello, {name.get()}")
    
    body = customtkinter.CTkFrame(master=app)
    body.pack(fill="both",side="top",expand=True)
    # body.grid_columnconfigure(1, weight=1)
    customtkinter.CTkLabel(body,text="Recommended Movies",justify="left",font=("Product Sans Light",20)).grid(row=0,column=0,padx=10,pady=10)
    
    for c,movie in enumerate(movies.keys()):
        # i=Image.open(movies[movie]['poster']).resize((200, 300))
        #poster = customtkinter.CTkImage(dark_image=Image.open(movies[movie]['poster']),light_image=Image.open(movies[movie]['poster']),size=(200,300))
        #customtkinter.CTkButton(body,image=poster,text="",width=0,height=0,corner_radius=0,fg_color="transparent",hover=False,command=lambda idx=movie: select_venue(idx)).grid(row=1,column=c,padx=2,pady=2)
        movieCard(body,movie,c)
        
    app.mainloop()

def switch_event():
    if switch_var.get() == "on":
        customtkinter.set_appearance_mode("Dark")
        switch_text.set("Light")
    else:
        customtkinter.set_appearance_mode("Light")
        switch_text.set("Dark")


customtkinter.set_appearance_mode("Light")
customtkinter.set_default_color_theme("blue")

def checkName(event=None):
    if entry.get()=="":
        messagebox.showerror("Error","Name Can't be empty")
    else:
        name.set(entry.get())
        # app.destroy()
        movie_choose(app)



app=customtkinter.CTk()
loadFonts()
# switch_var = customtkinter.StringVar(value="off")
# switch_text = customtkinter.StringVar(value="Dark")
switch_var = customtkinter.StringVar(value="off")
switch_text = customtkinter.StringVar(value="Dark")
name = customtkinter.StringVar()
app.title(gl_state['title'])
app.geometry("400x100")
app.grid_columnconfigure(0, weight=1)

# customtkinter.FontManager.load_font("fonts\\ProductSans-Regular.ttf")

entry = customtkinter.CTkEntry(app, placeholder_text="Enter Name")
entry.grid(row=0,column=0,pady=20,padx=20,sticky="ew")
entry.bind("<Return>", checkName)

button = customtkinter.CTkButton(app, text="Submit",command=checkName,corner_radius=32,hover_color="#4158D0")
button.grid(row=1, column=0)

app.mainloop()

