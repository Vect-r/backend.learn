import tkinter as tk
from tkinter import messagebox

gl_state={'title':'Movie Ticketing Software'}

movies=["Dhurandhar","Ikkis","Raja Saab"]


def movie_choose():
    def on_movie_select():
        gl_state['movie']=v.get()
        o.config(text=f"Selected Movie, {movies[gl_state['movie']]}")

    def goto_venue():
        root2.destroy()
        choose_venue()

    # new_window = tk.Toplevel(root)
    # new_window.title(gl_state['title'])
    # new_window.geometry("300x200")

    root2 = tk.Tk()
    root2.title(gl_state['title'])
    root2.geometry("300x200")

    v = tk.IntVar(root2, 0)
    
    # Add a label to the new window
    tk.Label(root2, text=f"Hello, {gl_state['name']} please select movie").pack(pady=20)
    
    o=tk.Label(root2,text="Hello")

    for count,text in enumerate(movies): 
        tk.Radiobutton(root2, text = text, variable = v, value = count,justify=tk.LEFT,command=on_movie_select,anchor="w").pack(side = tk.TOP, fill="x",ipady = 5,ipadx=40) 

    o.pack(pady=10)

    tk.Button(root2,text="Select Venue",command=goto_venue).pack()

    root2.mainloop()

    
    # Add a button to close the new window
    # tk.Button(new_window, text="Close Window", command=new_window.destroy).pack(pady=10)


def submit():
    name = entry.get()
    if name=="":
        # messagebox("Error","Empty name. Please fill your name")
        messagebox.showerror("Error", "Empty Name.")
    else:
        gl_state['name']=name
        root.destroy()
        movie_choose()
    # root.quit()
    # label.config(text=f"Hello {name} 👋")
    # messagebox.showinfo("Info",f"Hello, {gl_state['name']}")

def choose_venue():
    root = tk.Tk()
    root.title(gl_state['title'])
    root.geometry("300x200")


root = tk.Tk()
root.title(gl_state["title"])
root.geometry("400x100")

entry = tk.Entry(root, font=("Arial", 14))
entry.pack(pady=10)


btn = tk.Button(root, text="Submit", command=submit)
btn.pack()
root.mainloop()
