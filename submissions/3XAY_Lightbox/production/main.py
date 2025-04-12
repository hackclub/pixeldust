#This is a simplified version, it is not possible to implement the proper code in Wokwi due to certain libraries not being available + lack of RGBW LEDs

import time
from neopixel import Neopixel
from machine import Pin
from rotary_irq_rp2 import RotaryIRQ

pixels = Neopixel(16, 0, 6, "GRB")
p0 = Pin(9, Pin.IN)
p1 = Pin(10, Pin.IN)
rot = RotaryIRQ(pin_num_clk = 0, pin_num_dt = 1, min_val = 0, max_val = 255, incr = 10, reverse = False, range_mode=RotaryIRQ.RANGE_UNBOUNDED)

r = 255
g = 255
b = 255
state = "r"

lastVal = p0.value()
lastVal2 = p1.value()
lastRot = 0

while True:
  pixels.fill([r, g, b])

  if p0.value() != lastVal:
    lastVal = p0.value()
    if state == "r":
      state = "g"
    elif state == "g":
      state = "b"
    else:
      state = "r"
  if state == "r":
    r += lastRot - rot.value()
  elif state == "g":
    g += lastRot - rot.value()
  else:
    b += lastRot - rot.value()
  
  if p1.value() != lastVal2:
    lastVal2 = p1.value()
    r = 255
    g = 255
    b = 255

  if r > 255:
    r = 255
  if g > 255:
    g = 255
  if b > 255:
    b = 255
  if r < 0:
    r = 0
  if g < 0:
    g = 0
  if b < 0:
    b = 0
  pixels.show()
  print("r " + str(r) + "g " + str(g) + "b " + str(b) + "state " + state)
  lastRot = rot.value()
  time.sleep(0.2)
