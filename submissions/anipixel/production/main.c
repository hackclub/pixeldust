import time
from neopixel import Neopixel
pixels = Neopixel(8, 0, 0, "GRB")

colors = [
  (0xff, 0x00, 0x00),
  (0x00, 0xff, 0x00),
  (0x00, 0x00, 0xff),
]

pixel_index = 0
color_index = 0
while True:
  pixels.set_pixel(pixel_index, colors[color_index])
  pixels.show()
  pixel_index += 1
  if pixel_index == 8:
    pixel_index = 0
    color_index = (color_index + 1) % 3
  time.sleep(0.1)

