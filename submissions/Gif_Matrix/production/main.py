import machine
import neopixel
import time
from frames import frames 

NUM_PIXELS = 64
PIN = 0
np = neopixel.NeoPixel(machine.Pin(PIN), NUM_PIXELS)

speed = 0.1

def show_frame(frame):
    for i, (r, g, b) in enumerate(frame):
        if i < NUM_PIXELS:
            np[i] = (r, g, b)
    np.write()

while True:
    for frame in frames:
        show_frame(frame)
        time.sleep(speed)
