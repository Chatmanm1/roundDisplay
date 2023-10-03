
#this works below here 
# for python 3.x use 'tkinter' rather than 'Tkinter'
import tkinter as tk
import time
import psutil
import requests
from bs4 import BeautifulSoup
import time
import serial

ser = serial.Serial("COM11", 9600)




class App():
    def __init__(self):
        self.root = tk.Tk()
        self.root.title("Glass Info")
        self.label1 = tk.Label(text="CPU")
        self.label1.pack()
        self.update_cpu()
        self.label2 = tk.Label(text="Memory")
        self.label2.pack()
        self.update_mem()
        self.label3 = tk.Label(text="")
        self.label3.pack()
        self.getWeather()
        self.root.mainloop()
    def update_cpu(self):
        cpu = psutil.cpu_percent(interval=1)
        self.label1.configure(text=str(cpu)+"% CPU")
        self.root.after(10000, self.update_cpu)
        cpuString = str(cpu).encode()
        ser.write(cpuString)
        ser.write(b'% CPU')
    def update_mem(self):
        mem = psutil.virtual_memory().percent
        self.label2.configure(text=str(mem)+"% mem")
        self.root.after(15000, self.update_mem)
        memString = str(mem).encode()
        ser.write(memString)
        ser.write(b'% MEM')
    def getWeather(self):
        #enter City Name
        city = "Des Moines"
        url = "https://www.google.com/search?q="+"weather"+city
        html = requests.get(url).content
        soup = BeautifulSoup(html, 'html.parser')
        temp = soup.find('div', attrs={'class': 'BNeawe iBp4i AP7Wnd'}).text
        str2 = soup.find('div', attrs={'class': 'BNeawe iBp4i AP7Wnd'}).text
        data = str2.split('\n')
        time = data[0]
        self.label3.configure(text=time)
        self.root.after(30000, self.getWeather)
        timeString = str(time).encode()
        ser.write(timeString)
        ser.write(b' in DSM')

  
              
    

app=App()


