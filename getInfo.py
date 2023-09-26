# for python 3.x use 'tkinter' rather than 'Tkinter'
import tkinter as tk
import time
import psutil
import requests
from bs4 import BeautifulSoup



class App():
    def __init__(self):
        self.root = tk.Tk()
      
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
        self.label1.configure(text=cpu)
        self.root.after(4000, self.update_cpu)
    def update_mem(self):
        mem = psutil.virtual_memory().percent
        self.label2.configure(text=mem)
        self.root.after(4000, self.update_mem)
    def getWeather(self):
        # enter city name
        city = "Des Moines"
        url = "https://www.google.com/search?q="+"weather"+city
        html = requests.get(url).content
        soup = BeautifulSoup(html, 'html.parser')
        temp = soup.find('div', attrs={'class': 'BNeawe iBp4i AP7Wnd'}).text
        str = soup.find('div', attrs={'class': 'BNeawe tAd8D AP7Wnd'}).text
        data = str.split('\n')
        time = data[0]
        sky = data[1]
        self.label3.configure(text=temp+" "+sky)
        self.root.after(30000, self.getWeather)
          
    

app=App()








    
