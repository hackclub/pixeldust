import neopixel
from machine import Pin
import time

led_num = 49
color = (0,255,255)
p = Pin(0, Pin.OUT)
n = neopixel.NeoPixel(p, led_num)

# while True:
  # for i in range(led_num):
      # n[i] = (0,255,255)
      # n[i-led_num_half] = (0,255,0)
      # n.write()
      # time.sleep(0.1)

def reset():
  for i in range(led_num):
      n[i] = (0,0,0)
  n.write()

def wave():
  for i in range(led_num):
      if i in [0, 1, 2, 10, 11, 12, 20, 21, 22, 23, 24, 25, 26, 34, 38, 39, 40, 42, 43, 44]:
          n[i] = color
  n.write()
  time.sleep(0.5)
  reset()
  for i in range(led_num):
      if i in [4, 5, 6, 9, 10, 11, 15, 18, 21, 25, 29, 32, 37, 39, 38, 46, 47, 48]:
          n[i] = color
  n.write()
  time.sleep(0.5)
  reset()
  for i in range(led_num):
      if i in [0, 1, 9, 10, 18, 19, 27, 32, 33, 37, 38, 42, 43]:
          n[i] = color
  n.write()
  time.sleep(0.5)
  reset()
  for i in range(led_num):
      if i in [7, 8, 9, 10, 11, 12, 13, 14, 17, 20, 21, 24, 27, 28, 34, 35, 41]:
          n[i] = color
  n.write()
  time.sleep(0.5)
  reset()

def two_eight_two_six():
   for i in range(led_num):
       if i in [7, 10, 11, 12, 13, 14, 17, 20, 21, 24, 27, 28, 31, 34, 35, 36, 37, 38, 41]:
          n[i] = color
   n.write()
   time.sleep(0.5)
   reset()
   for i in range(led_num):
       if i in [8, 9, 11, 12, 14, 17, 20, 21, 24, 27, 28, 31, 34, 36, 37, 39, 40]:
           n[i] = color
   n.write()
   time.sleep(0.5)
   reset()
   for i in range(led_num):
       if i in [7, 10, 11, 12, 13, 14, 17, 20, 21, 24, 27, 28, 31, 34, 35, 36, 37, 38, 41]:
           n[i] = color
   n.write()
   time.sleep(0.5)
   reset()
   for i in range(led_num):
       if i in [7, 8, 9, 10, 11, 12, 13, 14, 17, 20, 21, 24, 27, 28, 31, 34, 35, 38, 39, 40, 41]:
           n[i] = color
   n.write()
   time.sleep(0.5)
   reset()

wave()

two_eight_two_six()
