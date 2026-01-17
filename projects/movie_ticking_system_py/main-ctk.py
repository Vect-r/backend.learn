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

def switch_event():
    if switch_var.get()=="on":
        customtkinter.set_appearance_mode("Dark")
    else:
        customtkinter.set_appearance_mode("Light")
    print("switch toggled, current value:", switch_var.get())


def movie_choose():
    app=getWindow(300,600)
    title_bar = customtkinter.CTkFrame(master=app, height=60, corner_radius=0,fg_color="#03A9F4")
    title_bar.pack(side="top", fill="x")
    title_bar.grid_columnconfigure(1, weight=1)
    customtkinter.CTkLabel(title_bar,text=f"Hello, {name.get()}",text_color="white",height=40,font=("Segoe UI Bold",14)).grid(row=0,column=0,padx=10,sticky="w")
    switch = customtkinter.CTkSwitch(title_bar, text="Switch Theme", command=switch_event,variable=switch_var, onvalue="on", offvalue="off")
    switch.grid(row=0,column=1,sticky="e")

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
switch_var = customtkinter.StringVar(value="off")
name = customtkinter.StringVar()
app.title(gl_state['title'])
app.geometry("400x100")
app.grid_columnconfigure(0, weight=1)

entry = customtkinter.CTkEntry(app, placeholder_text="Enter Name")
entry.grid(row=0,column=0,pady=20,padx=20,sticky="ew")
entry.bind("<Return>", checkName)

button = customtkinter.CTkButton(app, text="Submit",command=checkName,corner_radius=32,hover_color="#4158D0")
button.grid(row=1, column=0)

app.mainloop()

