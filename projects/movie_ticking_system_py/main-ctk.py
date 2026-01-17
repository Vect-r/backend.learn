import customtkinter
# from customtkinter import messagebox
from tkinter import messagebox
from PIL import Image, ImageTk
import json
from pathlib import Path

gl_state={'title':'Movie Ticketing Software'}



movies={
    "Dhurandhar":{"poster":"posters/Dhurandhar.jpeg"},
    "Happy Patel":{"poster":"posters/Happy Patel.jpeg"},
    "Avatar":{"poster":"posters/Avatar.jpeg"}
}

def loadFonts():
    fp=Path('fonts')
    # print([entry for entry in fp.iterdir()])
    for f in fp.iterdir():
        customtkinter.FontManager.load_font(str(f))



def getWindow(height,width,resize=True):
    app=customtkinter.CTk()
    app.title(gl_state['title'])
    app.geometry(f"{width}x{height}")
    app.resizable(resize,resize)
    return app

def switch_event():
    if switch_var.get()=="on":
        customtkinter.set_appearance_mode("Dark")
        switch_text.set("Light")
        
    else:
        customtkinter.set_appearance_mode("Light")
        switch_text.set("Dark")
    print("switch toggled, current value:", switch_var.get())
    print(switch_text.get())

def select_venue():
    pass


def movie_choose():
    app=getWindow(600,800)
    title_bar = customtkinter.CTkFrame(master=app, height=60, corner_radius=0,fg_color="#03A9F4")
    title_bar.pack(side="top", fill="x")
    title_bar.grid_columnconfigure(1, weight=1)
    customtkinter.CTkLabel(title_bar,text=f"Hello, {name.get()}",text_color="white",height=40,font=("Product Sans Medium",22)).grid(row=0,column=0,padx=10,sticky="w")
    switch = customtkinter.CTkSwitch(title_bar, textvariable=switch_var, font=('Regular Sans Light',14),command=switch_event,variable=switch_var, onvalue="on", offvalue="off")
    switch.grid(row=0,column=1,sticky="e",padx=2,pady=10)

    body= customtkinter.CTkFrame(master=app)
    body.pack(fill="both",side="top",expand=True)
    # body.grid_columnconfigure(1, weight=1)

    customtkinter.CTkLabel(body,text="Movies Available to watch",justify="left",font=("Product Sans Light",20)).grid(row=0,column=0,padx=10,pady=10)
    
    for c,movie in enumerate(movies.keys()):
        # i=Image.open(movies[movie]['poster']).resize((200, 300))
        poster = customtkinter.CTkImage(dark_image=Image.open(movies[movie]['poster']),light_image=Image.open(movies[movie]['poster']),size=(200,300))
        customtkinter.CTkButton(body,image=poster,text="",width=0,height=0,corner_radius=0,fg_color="transparent",hover=False).grid(row=1,column=c,padx=2,pady=2)

    app.mainloop()


customtkinter.set_appearance_mode("Light")
customtkinter.set_default_color_theme("blue")

def checkName(event=None):
    if entry.get()=="":
        messagebox.showerror("Error","Name Can't be empty")
    else:
        name.set(entry.get())
        app.destroy()
        movie_choose()



app=customtkinter.CTk()
loadFonts()
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

