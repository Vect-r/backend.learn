import customtkinter
# from customtkinter import messagebox
from tkinter import messagebox

gl_state={'title':'Movie Ticketing Software'}

movies=["Dhurandhar","Ikkis","Raja Saab"]

def getWindow(height,width,resize=True):
    app=customtkinter.CTk()
    app.title(gl_state['title'])
    app.geometry(f"{width}x{height}")
    app.resizable(resize,resize)
    return app


def movie_choose():
    app=getWindow(300,200)
    title_bar = customtkinter.CTkFrame(master=app, height=40, corner_radius=0)
    title_bar.pack(side="top", fill="x")
    app.mainloop()


customtkinter.set_appearance_mode("Light")
customtkinter.set_default_color_theme("blue")

def checkName():
    name = entry.get()
    if name=="":
        messagebox.showerror("Error","Name Can't be empty")
    else:
        app.destroy()
        movie_choose()

app=customtkinter.CTk()
app.title(gl_state['title'])
app.geometry("400x100")
app.grid_columnconfigure(0, weight=1)

entry = customtkinter.CTkEntry(app, placeholder_text="Enter Name")
entry.grid(row=0,column=0,pady=20,padx=20,sticky="ew")

button = customtkinter.CTkButton(app, text="Submit",command=checkName,corner_radius=32,hover_color="#4158D0")
button.grid(row=1, column=0)

app.mainloop()

