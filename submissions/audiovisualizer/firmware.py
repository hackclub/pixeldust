from machine import Pin
import neopixel
import array
import rp2
import math
from ulab import numpy as np
from rp2 import PIO, StateMachine, asm_pio
import time
import audiobusio

LED_PIN = 1 # GPIO26
NUM_LEDS = 120
np_strip = neopixel.NeoPixel(Pin(LED_PIN), NUM_LEDS)

# I2S Microphone Configuration (ICS-43434)
I2S_BCLK = 9
I2S_WS = 7 
I2S_DOUT = 5 

i2s = audiobusio.I2SIn(bit_clock=Pin(I2S_BCLK), word_select=Pin(I2S_WS), data=Pin(I2S_DOUT), sample_rate=16000, bits_per_sample=16)

def update_leds():
    buffer = bytearray(1024) 
    i2s.readinto(buffer)
    samples = np.frombuffer(buffer, dtype=np.int16)
    fft_result = np.abs(np.fft.fft(samples))[:NUM_LEDS]  
    max_val = np.max(fft_result) if np.max(fft_result) > 0 else 1 
    
    for i in range(NUM_LEDS):
        brightness = int((fft_result[i] / max_val) * 255) 
        np_strip[i] = (brightness, 0, 255 - brightness) 
    
    np_strip.write() 

while True:
    update_leds()
    time.sleep(0.05)
