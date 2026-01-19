import customtkinter
from tkinter import messagebox
from PIL import Image
import os

# Set global appearance
customtkinter.set_appearance_mode("Dark")
customtkinter.set_default_color_theme("blue")

class MovieApp(customtkinter.CTk):
    def __init__(self):
        super().__init__()

        self.title("CineReserve | Movie Ticketing")
        self.geometry("900x700")
        
        # Data
        self.movies = {
            "Dhurandhar": {"poster": "posters/Dhurandhar.jpeg", "genre": "Action / Drama"},
            "Happy Patel": {"poster": "posters/Happy Patel.jpeg", "genre": "Comedy"},
            "Avatar": {"poster": "posters/Avatar.jpeg", "genre": "Sci-Fi / Adventure"}
        }

        # App State
        self.user_name = customtkinter.StringVar(value="")
        self.appearance_mode = "Dark"

        # Show Login Screen initially
        self.show_login_screen()

    def clear_screen(self):
        for child in self.winfo_children():
            child.destroy()

    def toggle_theme(self):
        if self.appearance_mode == "Dark":
            customtkinter.set_appearance_mode("Light")
            self.appearance_mode = "Light"
        else:
            customtkinter.set_appearance_mode("Dark")
            self.appearance_mode = "Dark"

    # --- SCREENS ---

    def show_login_screen(self):
        self.clear_screen()
        self.grid_columnconfigure(0, weight=1)
        self.grid_rowconfigure(0, weight=1)

        # Login Card
        login_frame = customtkinter.CTkFrame(self, corner_radius=20, width=400, height=300)
        login_frame.grid(row=0, column=0, padx=20, pady=20)
        login_frame.grid_propagate(False)

        customtkinter.CTkLabel(login_frame, text="Welcome to CineReserve", 
                               font=("Product Sans", 24, "bold")).pack(pady=(40, 10))
        
        customtkinter.CTkLabel(login_frame, text="Please enter your name to continue", 
                               font=("Product Sans", 14)).pack(pady=5)

        self.name_entry = customtkinter.CTkEntry(login_frame, placeholder_text="Full Name", 
                                                width=250, height=40, corner_radius=10)
        self.name_entry.pack(pady=20)
        self.name_entry.bind("<Return>", lambda e: self.check_login())

        submit_btn = customtkinter.CTkButton(login_frame, text="Get Started", 
                                             command=self.check_login, 
                                             corner_radius=10, height=40, width=250,
                                             fg_color="#1f538d", hover_color="#14375e")
        submit_btn.pack(pady=10)

    def check_login(self):
        name = self.name_entry.get()
        if name.strip() == "":
            messagebox.showerror("Error", "Please enter your name")
        else:
            self.user_name.set(name)
            self.show_movie_selection()

    def show_movie_selection(self):
        self.clear_screen()
        
        # --- TOP NAV BAR ---
        nav_bar = customtkinter.CTkFrame(self, height=70, corner_radius=0, fg_color=("white", "#1a1a1a"))
        nav_bar.pack(side="top", fill="x")

        welcome_lbl = customtkinter.CTkLabel(nav_bar, text=f"Hello, {self.user_name.get()}!", 
                                            font=("Product Sans", 20, "bold"))
        welcome_lbl.pack(side="left", padx=30, pady=15)

        theme_switch = customtkinter.CTkSwitch(nav_bar, text="Dark Mode", command=self.toggle_theme)
        theme_switch.select() # Default to dark
        theme_switch.pack(side="right", padx=30)

        # --- CONTENT ---
        container = customtkinter.CTkScrollableFrame(self, fg_color="transparent")
        container.pack(fill="both", expand=True, padx=20, pady=10)

        customtkinter.CTkLabel(container, text="Recommended Movies", 
                               font=("Product Sans", 24, "bold")).pack(anchor="w", padx=10, pady=(20, 10))

        # Grid for Movie Cards
        movies_grid = customtkinter.CTkFrame(container, fg_color="transparent")
        movies_grid.pack(fill="both", expand=True)

        for i, (title, info) in enumerate(self.movies.items()):
            self.create_movie_card(movies_grid, title, info, i)

    def create_movie_card(self, master, title, info, index):
        # Movie Card Frame
        card = customtkinter.CTkFrame(master, corner_radius=15, width=220)
        card.grid(row=0, column=index, padx=15, pady=15)

        # Image Handling (Fallback to colored box if image fails)
        try:
            img_data = Image.open(info['poster'])
            poster_img = customtkinter.CTkImage(light_image=img_data, dark_image=img_data, size=(200, 280))
            img_lbl = customtkinter.CTkLabel(card, image=poster_img, text="")
            img_lbl.pack(pady=10, padx=10)
        except Exception:
            placeholder = customtkinter.CTkFrame(card, width=200, height=280, fg_color="gray")
            placeholder.pack(pady=10, padx=10)

        # Labels
        customtkinter.CTkLabel(card, text=title, font=("Product Sans", 16, "bold")).pack(padx=10)
        customtkinter.CTkLabel(card, text=info['genre'], font=("Product Sans", 12), text_color="gray").pack(padx=10, pady=(0, 10))

        # Select Button
        btn = customtkinter.CTkButton(card, text="Book Now", 
                                      command=lambda t=title: self.open_booking(t),
                                      corner_radius=8, height=32, width=180)
        btn.pack(pady=(0, 15), padx=10)

    def open_booking(self, movie_title):
        # Toplevel window for booking
        popup = customtkinter.CTkToplevel(self)
        popup.title(f"Booking: {movie_title}")
        popup.geometry("400x500")
        popup.attributes("-topmost", True) # Keep on top

        customtkinter.CTkLabel(popup, text=f"Select Venue for {movie_title}", 
                               font=("Product Sans", 18, "bold")).pack(pady=20)
        
        venues = ["PVR: Icon", "Cinepolis", "INOX: Insignia", "Drive-in Cinema"]
        for v in venues:
            customtkinter.CTkButton(popup, text=v, width=300, height=45, 
                                    fg_color="transparent", border_width=2).pack(pady=10)

if __name__ == "__main__":
    app = MovieApp()
    app.mainloop()