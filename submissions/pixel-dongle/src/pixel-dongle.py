
from machine import Pin
from neopixel import NeoPixel
from time import sleep_ms, time
from random import randint
import requests
import json


pin = Pin(2, Pin.OUT)
count = 15
brightness = .75
weather_poll_delay = 3 # Seconds between checking weather
max_temp = 30 # Highst temperature = bar fully filled


button0 = Pin(26, Pin.IN, Pin.PULL_UP)
button1 = Pin(27, Pin.IN, Pin.PULL_UP)
button2 = Pin(14, Pin.IN, Pin.PULL_UP)
button3 = Pin(12, Pin.IN, Pin.PULL_UP)

interrupt0 = False
interrupt1 = False
interrupt2 = False
interrupt3 = False


def button0_interrupt(event):
    global interrupt0
    interrupt0 = True

def button1_interrupt(event):
    global interrupt1
    interrupt1 = True

def button2_interrupt(event):
    global interrupt2
    interrupt2 = True

def button3_interrupt(event):
    global interrupt3
    interrupt3 = True


np = NeoPixel(pin, count)


button0.irq(trigger=Pin.IRQ_FALLING, handler=button0_interrupt)
button1.irq(trigger=Pin.IRQ_FALLING, handler=button1_interrupt)
button2.irq(trigger=Pin.IRQ_FALLING, handler=button2_interrupt)
button3.irq(trigger=Pin.IRQ_FALLING, handler=button3_interrupt)

# Startup values
mode = 1
offset = 0
last_update = time() - weather_poll_delay
light_up_count = 0

while True:
    if interrupt0:
        mode = 0
    if interrupt1:
        mode = 1
    elif interrupt2:
        mode = 2
    elif interrupt3:
        mode = 3
    
    interrupt0 = False
    interrupt1 = False
    interrupt2 = False
    interrupt3 = False

    # Temp
    if mode == 0:
        if (time() - last_update) >= weather_poll_delay:
            #json_report = requests.get("https://api.open-meteo.com/v1/forecast?latitude=20.062426&longitude=-155.495409&current=temperature_2m,relative_humidity_2m")
            json_report = """{"latitude":20.0,"longitude":-155.625,"generationtime_ms":0.028967857360839844,"utc_offset_seconds":0,"timezone":"GMT","timezone_abbreviation":"GMT","elevation":638.0,"current_units":{"time":"iso8601","interval":"seconds","temperature_2m":"°C","relative_humidity_2m":"%"},"current":{"time":"2025-04-06T08:15","interval":900,"temperature_2m":16.0,"relative_humidity_2m":97}}"""
            report = json.loads(json_report)
            temperature = report["current"]["temperature_2m"]
            humidity = report["current"]["relative_humidity_2m"]
            light_up_count = round((abs(temperature) / max_temp) * count)
            last_update = time()
        
        red = 0
        green = 255
        blue = 0
        for i in range(count):
            if i < light_up_count:
                np[i] = (red, green, blue)
                red += int(255/15)
                if red > 255:
                    red = 255
                green -= int(255/15)
                if green < 0:
                    green = 0
            else:
                np[i] = (0, 0, 0)
            

    # All the same random
    elif mode == 1:
        red = int(randint(0, 255) * brightness)
        green = int(randint(0, 255) * brightness)
        blue = int(randint(0, 255) * brightness)
        for i in range(count):
            np[i] = (red, green, blue)
            
    # All random
    elif mode == 2:
        for i in range(count):
            red = int(randint(0, 255) * brightness)
            green = int(randint(0, 255) * brightness)
            blue = int(randint(0, 255) * brightness)
            np[i] = (red, green, blue)

    # Rainbow
    elif mode == 3:
        for i in range(count):
            hue = int((((i + offset) % count ) / count) * 255)
            if hue < 85:
                red = int(hue * 3 * brightness)
                green = int((255 - hue * 3) * brightness)
                blue = 0
            elif hue < 170:
                hue -= 85
                red = int((255 - hue * 3) * brightness)
                green = 0
                blue = int(hue * 3 * brightness)
            else:
                hue -= 170
                red = 0
                green = int(hue * 3 * brightness)
                blue = int((255 - hue * 3) * brightness)
            np[i] = (red, green, blue)
        offset = (offset - 1) % count
        

    np.write()
    sleep_ms(100)