import machine
import neopixel
import time
import dht
import random
#import math
# Configuration
PIN = 15  # GPIO pin connected to the SK6812MINI
NUM_LEDS = 36  # Change this to match your setup
d = dht.DHT22(machine.Pin(16))
temp=0
#22 celcius
np = neopixel.NeoPixel(machine.Pin(PIN), NUM_LEDS)
t=0.36
#TRY CHANGING THE TEMPERATURE AND SEE WHAT HAPPENS
def choose_color(temp):
 #   global temp
    global r
    global g 
    global b
    if temp< 22: #cool
            r= random.randint(0,150)
            g=random.randint(100,255)
            b=random.randint(150,255)
            return True #true == cool
    if temp>= 22:
            r= random.randint(150,255)
            g=random.randint(0,150)
            b=random.randint(0,100)
            return False

def set_color():
    global t
    global d
    measure()
    #choose_color(temp) #for only 1 color at a time
    for i in range(NUM_LEDS):
        choose_color(temp) #for random

        np[i] = (r, g, b)
        time.sleep(t)
        if i==35:
            t=0.36
        else:
            t -=0.01
        np.write()
    
def measure():
    global temp
    d.measure()
    temp = d.temperature()
    return temp

def blink(blinks):
    for blink in range (0,blinks):
        choose_color(measure())
        for i in range (NUM_LEDS):
            if i % 2:
                np[i]= r,g,b
        np.write()
        time.sleep(0.3)
        for q in range (NUM_LEDS):
            np[q]= 0,0,0
        np.write()
        time.sleep(0.3)

def horz(blinks):
    for i in range(NUM_LEDS):
        np[i]=0,0,0
    np.write()
    for i in range (0,blinks):
        choose_color(measure())
        for i in range (NUM_LEDS):
            if i//6 == 1 or  i//6==3 or i//6==5:
                np[i]= r,g,b
        np.write()
        time.sleep(0.3)
        for i in range (NUM_LEDS):
            if i//6 == 1 or  i//6==3 or i//6==5:
                np[i]= 0,0,0 
        np.write() 
        time.sleep(0.3)

while True:
    horz(4)
    time.sleep(0.5)
    blink(4) 
    time.sleep(0.5)
    set_color()     
    time.sleep(1)    
    set_color()  
    time.sleep(1)     
    #set_color()     
    #time.sleep(1)
 #   blink()