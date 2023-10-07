# for python 3.x use 'tkinter' rather than 'Tkinter'
import tkinter as tk
import time
import psutil
import requests
from bs4 import BeautifulSoup
import serial

ser = serial.Serial("COM11", 9600)


class App():
    def __init__(self):
        
        self.root = tk.Tk()
        self.root.title("Glass Info")
       # self.iconbitmap("C:/Users/mchatman/Desktop/cube.ico")
        self.label1 = tk.Label(text="CPU")
        self.label1.pack()
        self.update_cpu()
        self.label2 = tk.Label(text="Memory")
        self.label2.pack()  
        self.update_mem()
        self.label3 = tk.Label(text="")
        self.label3.pack()
        self.label4 = tk.Label(text="")
        self.label4.pack()
        self.getWeather() 
        self.root.mainloop()
        


    def update_cpu(self):
        cpu = psutil.cpu_percent(interval=1)
        self.label1.configure(text=str(cpu)+"% CPU")
        cpu_message = f"CPU: {cpu}%"
        ser.write(cpu_message.encode())
        self.root.after(5000, self.update_cpu)
     
    def update_mem(self):
        mem = psutil.virtual_memory().percent
        self.label2.configure(text=str(mem)+"% mem")
        mem_message = f"MEM: {mem}%"
        ser.write(mem_message.encode())
        self.root.after(4001, self.update_mem)
        
    def getWeather(self):
        # enter city name
        city = "Des Moines"
        url = "https://www.google.com/search?q=weather+des+moines&sca_esv=568775834&sxsrf=AM9HkKluiEWh_FJ4KxfXEkoCpoELVlrRKg%3A1695820224185&source=hp&ei=wCkUZe_0BPbMkPIP-aCh0AI&iflsig=AO6bgOgAAAAAZRQ30F9Q7KzAszBEr0XatF45A-I1mR67&ved=0ahUKEwjv1LzQ7sqBAxV2JkQIHXlQCCoQ4dUDCAw&uact=5&oq=weather+des+moines&gs_lp=Egdnd3Mtd2l6IhJ3ZWF0aGVyIGRlcyBtb2luZXMyCxAAGIAEGLEDGIMBMgUQABiABDIFEAAYgAQyBRAAGIAEMgUQABiABDIFEAAYgAQyBRAAGIAEMgUQABiABDIFEAAYgAQyBRAAGIAESLcRUABY0BBwAHgAkAEAmAGRAqABzguqAQYxNS4yLjG4AQPIAQD4AQHCAgcQIxiKBRgnwgIEECMYJ8ICDhAAGIoFGLEDGIMBGJECwgIREC4YgAQYsQMYgwEYxwEY0QPCAggQABiABBixA8ICCBAAGIoFGJECwgILEC4YgAQYxwEYrwHCAgcQABiKBRhDwgINEAAYigUYsQMYgwEYQ8ICERAuGIoFGLEDGMcBGNEDGJECwgIIEAAYgAQYkgPCAggQABiKBRiSA8ICCRAAGIoFGAoYQ8ICCxAAGIoFGJIDGJECwgIUEC4YigUYsQMYgwEYxwEY0QMYkQLCAg8QIxiKBRgnGJ0CGEYYgALCAgsQABiKBRixAxiDAQ&sclient=gws-wiz"
        html = requests.get(url).content
        soup = BeautifulSoup(html, 'html.parser')
        temp = soup.find('div', attrs={'class': 'BNeawe iBp4i AP7Wnd'}).text
        str = soup.find('div', attrs={'class': 'BNeawe tAd8D AP7Wnd'}).text
        data = str.split('\n')
        time = data[0]
        sky = data[1]
        self.label4.configure(text=time)   
        self.label3.configure(text=temp+" "+sky)
        temp_message = f"TEMP: {sky}"
        ser.write(temp_message.encode())     
        self.root.after(30000, self.getWeather)
        
          
    

app=App()







    
