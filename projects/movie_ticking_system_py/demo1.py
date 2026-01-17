import tkinter as tk

root = tk.Tk()
root.title("Responsive Frame")
root.geometry("400x300") # Initial size

# --- The Responsive Frame ---
main_frame = tk.Frame(root, bg="lightgray", bd=2, relief="sunken")
main_frame.pack(fill='both', expand=True, padx=10, pady=10) # Frame fills the window

# --- Widgets inside the Frame (also responsive) ---
label = tk.Label(main_frame, text="Hello, Responsive World!", bg="lightgray")
label.pack(pady=20)

button = tk.Button(main_frame, text="Click Me")
button.pack(pady=10)

# Make inner widgets responsive within the frame
label.pack(pady=5, fill='both', expand=True) # Example of widget resizing
button.pack(pady=5, fill='both', expand=True) # Example of widget resizing

root.mainloop()
