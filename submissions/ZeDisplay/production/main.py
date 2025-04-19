import machine, neopixel, time, random
from machine import Pin
from utime import sleep

pattern_pin = 1   # big matrix (down)
clock_pin = 2     # smol matrix (up)

pattern_w, pattern_h = 10, 8
clock_w, clock_h = 20, 7

pattern_np = neopixel.NeoPixel(Pin(pattern_pin), pattern_w * pattern_h)
clock_np = neopixel.NeoPixel(Pin(clock_pin), clock_w * clock_h)

def set_pixel(np, width, x, y, color):
    if y % 2 == 0:
        idx = y * width + x
    else:
        idx = y * width + (width - 1 - x)
    if 0 <= idx < len(np):
        np[idx] = color

def clear(np):
    for i in range(len(np)):
        np[i] = (0, 0, 0)
    np.write()

def draw_digit(np, width, digit, x_offset, color):
    font = {
        "0": ["111","101","101","101","111"],
        "1": ["010","110","010","010","111"],
        "2": ["111","001","111","100","111"],
        "3": ["111","001","111","001","111"],
        "4": ["101","101","111","001","001"],
        "5": ["111","100","111","001","111"],
        "6": ["100","100","111","101","111"],
        "7": ["111","001","010","010","010"],
        "8": ["111","101","111","101","111"],
        "9": ["111","101","111","001","111"],
        ":": ["000","010","000","010","000"],
    }
    rows = font.get(digit, ["000"]*5)
    for y, row in enumerate(rows):
        for x, px in enumerate(row):
            if px == "1":
                set_pixel(np, width, x + x_offset, y + 1, color)

def draw_time():
    t = time.localtime()
    h = t[3]
    m = t[4]
    time_str = "{:02}:{:02}".format(h, m)
    clear(clock_np)
    for i, char in enumerate(time_str):
        draw_digit(clock_np, clock_w, char, i * 4, (255, 100, 30))
    clock_np.write()

def random_pattern():
    for y in range(pattern_h):
        for x in range(pattern_w):
            color = (random.randint(0, 60), random.randint(0, 60), random.randint(0, 60))
            set_pixel(pattern_np, pattern_w, x, y, color)
    pattern_np.write()

while True:
    draw_time()
    random_pattern()
    sleep(0.2)
