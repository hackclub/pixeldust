import machine
import neopixel
import time
import math

LED_PIN = machine.Pin(26, machine.Pin.OUT)
NUM_LEDS = 16
MAX_BRIGHTNESS = 0.5

BUTTON_PIN = machine.Pin(0, machine.Pin.IN, machine.Pin.PULL_UP)
MODE_PIN = machine.Pin(1, machine.Pin.IN, machine.Pin.PULL_UP)

pixels = neopixel.NeoPixel(LED_PIN, NUM_LEDS)

NUM_SAMPLES = 10
SAMPLE_DELAY = 0.01

def scale_brightness(color, brightness_factor):
    r, g, b = color
    r = max(0, min(255, int(r * brightness_factor)))
    g = max(0, min(255, int(g * brightness_factor)))
    b = max(0, min(255, int(b * brightness_factor)))
    return (r, g, b)

def hsv_to_rgb(h, s, v):
    if s == 0:
        return (int(v * 255),) * 3
    h /= 60
    i = int(h)
    f = h - i
    p, q, t = v * (1 - s), v * (1 - s * f), v * (1 - s * (1 - f))
    if i == 0:
        r, g, b = v, t, p
    elif i == 1:
        r, g, b = q, v, p
    elif i == 2:
        r, g, b = p, v, t
    elif i == 3:
        r, g, b = p, q, v
    elif i == 4:
        r, g, b = t, p, v
    else:
        r, g, b = v, p, q
    return int(r * 255), int(g * 255), int(b * 255)


currentPixel = 0
current_hue = 0
last_temp_time = time.ticks_ms()

while True:
    if BUTTON_PIN.value() == 0:
        current_hue = (current_hue + 10) % 360
        color = scale_brightness(hsv_to_rgb(current_hue, 1, 1), 0.4)

        pixels.fill((0, 0, 0))
        pixels[currentPixel] = color
        pixels.write()

        currentPixel = (currentPixel + 1) % NUM_LEDS
    else:
        pixels.fill((0, 0, 0))
        pixels.write()

    time.sleep(0.07)