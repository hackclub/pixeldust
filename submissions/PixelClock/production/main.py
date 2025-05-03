import time
import machine
import neopixel

np = neopixel.NeoPixel(machine.Pin(0), 133)

DIGITS = {
    '0': [
        1, 1, 1,
        1, 0, 1,
        1, 0, 1,
        1, 0, 1,
        1, 1, 1
    ],
    '1': [
        0, 1, 0,
        1, 1, 0,
        0, 1, 0,
        0, 1, 0,
        1, 1, 1
    ],
    '2': [
        1, 1, 1,
        0, 0, 1,
        1, 1, 1,
        1, 0, 0,
        1, 1, 1
    ],
    '3': [
        1, 1, 1,
        0, 0, 1,
        1, 1, 1,
        0, 0, 1,
        1, 1, 1
    ],
    '4': [
        1, 0, 1,
        1, 0, 1,
        1, 1, 1,
        0, 0, 1,
        0, 0, 1
    ],
    '5': [
        1, 1, 1,
        1, 0, 0,
        1, 1, 1,
        0, 0, 1,
        1, 1, 1
    ],
    '6': [
        1, 1, 1,
        1, 0, 0,
        1, 1, 1,
        1, 0, 1,
        1, 1, 1
    ],
    '7': [
        1, 1, 1,
        0, 0, 1,
        0, 0, 1,
        0, 0, 1,
        0, 0, 1
    ],
    '8': [
        1, 1, 1,
        1, 0, 1,
        1, 1, 1,
        1, 0, 1,
        1, 1, 1
    ],
    '9': [
        1, 1, 1,
        1, 0, 1,
        1, 1, 1,
        0, 0, 1,
        1, 1, 1
    ]
}

def clear_matrix():
    for i in range(133):
        np[i] = (0, 0, 0)
    np.write()

def get_pixel_index(row, col):
    if row < 0 or row >= 7 or col < 0 or col >= 19:
        return -1
    return row * 19 + col

def display_digit(digit, start_col):
    pattern = DIGITS[digit]
    for row in range(5):
        for col in range(3):
            if pattern[row * 3 + col] == 1:
                idx = get_pixel_index(row + 1, start_col + col)
                if idx >= 0 and idx < 133:
                    np[idx] = (10, 0, 0)

last_update = time.ticks_ms()
update_interval = 1000

while True:
    current_time = time.ticks_ms()
    if time.ticks_diff(current_time, last_update) >= update_interval:
        t = time.localtime()
        hours = t[3] % 24
        minutes = t[4]
        time_str = f"{hours:02d}{minutes:02d}"
        clear_matrix()
        display_digit(time_str[0], 1)
        display_digit(time_str[1], 5)
        display_digit(time_str[2], 9)
        display_digit(time_str[3], 13)
        np.write()
        last_update = current_time