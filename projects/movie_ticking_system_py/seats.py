import tkinter as tk

root = tk.Tk()
root.title("10x10 Checkbox Grid")

SIZE = 10
vars = [[tk.IntVar() for _ in range(SIZE)] for _ in range(SIZE)]

frame = tk.Frame(root)
frame.pack(padx=10, pady=10)

for r in range(SIZE):
    for c in range(SIZE):
        cb = tk.Checkbutton(
            frame,
            variable=vars[r][c],
            width=1,          # very small
            height=1,
            padx=0,
            pady=0,
            bd=0,
            highlightthickness=0
        )
        cb.grid(row=r, column=c, padx=0, pady=0)

root.mainloop()
