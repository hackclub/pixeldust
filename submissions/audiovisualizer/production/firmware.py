import time
import board
import neopixel
import array
import audiobusio
from ulab import numpy as np

LED_PIN = board.GP1
NUM_LEDS = 120
SAMPLERATE = 16000
BUFFER_SIZE = 1024

pixels = neopixel.NeoPixel(LED_PIN, NUM_LEDS, brightness=0.5, auto_write=False)

i2s = audiobusio.I2SIn(
    bit_clock=board.GP9,
    word_select=board.GP7,
    data=board.GP5,
    sample_rate=SAMPLERATE,
    bits_per_sample=16
)

def update_leds():
    buffer = bytearray(BUFFER_SIZE)
    i2s.record(buffer, len(buffer))
    samples = np.frombuffer(buffer, dtype=np.int16)
    
    fft_result = np.abs(np.fft.fft(samples))[0:NUM_LEDS]
    max_val = np.max(fft_result)
    if max_val == 0:
        max_val = 1
    
    for i in range(NUM_LEDS):
        intensity = int((fft_result[i] / max_val) * 255)
        pixels[i] = (intensity, 0, 255 - intensity)
    
    pixels.show()

while True:
    update_leds()
    time.sleep(0.05)
