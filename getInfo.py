# for python 3.x use 'tkinter' rather than 'Tkinter'
import tkinter as tk
import time
import psutil





class App():
    def __init__(self):
        self.root = tk.Tk()
        self.label = tk.Label(text="")
        self.label.pack()
        self.label1 = tk.Label(text="")
        self.label1.pack()
        self.update_clock()
        self.update_cpu()
        self.label2 = tk.Label(text="")
        self.label2.pack()
        self.update_mem()
        self.root.mainloop()

    def update_clock(self):
        now = time.strftime("%H:%M:%S")
        self.label.configure(text=now)
        self.root.after(1000, self.update_clock)
    def update_cpu(self):
        cpu = psutil.cpu_percent(interval=1)
        self.label1.configure(text=cpu)
        self.root.after(200, self.update_cpu)
    def update_mem(self):
        mem = psutil.virtual_memory().percent
        self.label2.configure(text=mem)
        self.root.after(1000, self.update_mem)
        

app=App()








    