from machine import Pin, TouchPad
from rotary_irq_esp import RotaryIRQ
import time
import math
import neopixel
import network
import urequests as req
import random

MAX_BRIGHTNESS = 0.25
URL = 'https://api.open-meteo.com/v1/forecast?latitude=40.7143&longitude=-74.006&hourly=weather_code,is_day&current=weather_code,is_day&timezone=America%2FNew_York&forecast_days=1&timeformat=unixtime&wind_speed_unit=mph&temperature_unit=fahrenheit&precipitation_unit=inch'
SSID = ' '
PASSWORD = ' '

print("Connecting to WiFi", end="")
sta_if = network.WLAN(network.STA_IF)
sta_if.active(True)
sta_if.connect(SSID, PASSWORD)
while not sta_if.isconnected():
  print(".", end="")
  time.sleep(0.1)
print(" Connected!")

np = neopixel.NeoPixel(Pin(1), 69)
rotary = RotaryIRQ(pin_num_clk=8, pin_num_dt=7, min_val=0, max_val=23, reverse=True, range_mode=RotaryIRQ.RANGE_BOUNDED)
button = Pin(9, Pin.IN, Pin.PULL_UP)

def rgb(r, g, b):
  return (math.floor(r*MAX_BRIGHTNESS), math.floor(g*MAX_BRIGHTNESS), math.floor(b*MAX_BRIGHTNESS))

center = range(9)
primary = list(range(9, 33, 2)) + list(range(33, 69, 3))
secondary = list(range(35, 69, 3)) + list(range(10, 33, 2))
innerRing = range(9, 33)
outerRing = range(33, 69)
selector = [
  [68, 33, 34],
  [35, 36, 37],
  [38, 39, 40],
  [41, 42, 43],
  [44, 45, 46],
  [47, 48, 49],
  [50, 51, 52],
  [53, 54, 55],
  [56, 57, 58],
  [59, 61, 62],
  [63, 64, 65],
  [66, 67, 68], 
  [68, 33, 34],
  [35, 36, 37],
  [38, 39, 40],
  [41, 42, 43],
  [44, 45, 46],
  [47, 48, 49],
  [50, 51, 52],
  [53, 54, 55],
  [56, 57, 58],
  [59, 60, 61],
  [62, 63, 64],
  [65, 66, 67]
]

data = None
currentData = None
currentDayNight = None
currentCode = None
forecastData = None
forecastDayNight = None
forecastCode = None

def getData():
  global data
  global currentData
  global currentDayNight
  global currentCode
  global forecastData
  global forecastDayNight
  global forecastCode
  response = req.get(URL)
  data = response.json()
  currentData = data['current']
  currentDayNight = currentData['is_day']
  currentCode = currentData['weather_code']
  forecastData = data['hourly']
  forecastDayNight = forecastData['is_day']
  forecastCode = forecastData['weather_code']


# day = 1 night = 0
# weather_code/animation numbers
# 0                    = clear
# 1 & 2                = mainly/partly
# 3                    = cloudy
# 45 & 48              = foggy
# 51, 53, 55, 56, & 57 = drizzle
# 61, 63, 65, 66, & 67 = rain
def animation(dn, num):
  # day ------------------------------------
  if dn == 1:
    # clear ++++++++++++++++++++++++++++++++
    if num == 0: 
      for i in center:
        np[i] = rgb(255, 255, 0)
      if animFrame == 1:
        for i in primary:
          np[i] = rgb(255, 255, 0)
      elif animFrame == 2:
        for i in secondary:
          np[i] = rgb(255, 255, 0)
    # mainly/partly +++++++++++++++++++++++++
    elif num == 1 or num == 2: 
      for i in center:
        np[i] = rgb(255, 255, 0)
      if animFrame == 1:
        for i in primary:
          np[i] = rgb(255, 255, 0)
      elif animFrame == 2:
        for i in secondary:
          np[i] = rgb(255, 255, 0)
      for x in range(2):
        randrange = random.randrange(9,64)
        for i in range(randrange, randrange+5):
          np[i] = rgb(180, 180, 180)
    # cloudy +++++++++++++++++++++++++++++++++
    elif num == 3: 
      for i in center:
        np[i] = rgb(255, 255, 0)
      if animFrame == 1:
        for i in primary:
          np[i] = rgb(255, 255, 0)
        for i in innerRing:
          np[i] = rgb(125, 125, 125)
      elif animFrame == 2:
        for i in secondary:
          np[i] = rgb(255, 255, 0)
        for i in innerRing:
          np[i] = rgb(180, 180, 180)
    # foggy +++++++++++++++++++++++++++++++++
    elif num == 45 or num == 48:
      if animFrame == 1:
        for i in innerRing:
          np[i] = rgb(125, 125, 125)
        for i in outerRing:
          np[i] = rgb(180, 180, 225)
      elif animFrame == 2:
        for i in innerRing:
          np[i] = rgb(180, 180, 225)
        for i in outerRing:
          np[i] = rgb(150, 150, 150)
    # drizzle +++++++++++++++++++++++++++++++
    elif num == 51 or num == 53 or num == 55 or num == 56 or num == 57:
      for i in innerRing:
        np[i] = rgb(100, 100, 100)
      for i in outerRing:
        np[i] = rgb(100, 100, 0)
      for x in range(6):
        np[random.randrange(9, 69)] = rgb(0, 0, 255)
    # rain ++++++++++++++++++++++++++++++++++
    elif num == 61 or num == 63 or num == 65 or num == 66 or num == 67:
      for i in innerRing:
        np[i] = rgb(100, 100, 100)
      for i in outerRing:
        np[i] = rgb(100, 100, 0)
      randrange1 = random.randrange(9,26)
      for i in range(randrange1, randrange1+7):
        np[i] = rgb(0, 0, 255)
      randrange2 = random.randrange(33,57)
      for i in range(randrange2, randrange2+12):
        np[i] = rgb(0, 0, 255)

  # night ----------------------------------
  if dn == 0: 
    # clear ++++++++++++++++++++++++++++++++
    if num == 0: 
      for x in range(3):
        np[random.randrange(9, 69)] = rgb(255, 255, 255)
    # mainly/partly +++++++++++++++++++++++++
    elif num == 1 or num == 2:
      for x in range(2):
        randrange = random.randrange(9,64)
        for i in range(randrange, randrange+5):
          np[i] = rgb(255, 255, 255)
    # cloudy +++++++++++++++++++++++++++++++++
    elif num == 3:
      if animFrame == 1:
        for i in primary:
          np[i] = rgb(125, 125, 125)
        for i in innerRing:
          np[i] = rgb(125, 125, 125)
      elif animFrame == 2:
        for i in secondary:
          np[i] = rgb(125, 125, 125)
        for i in innerRing:
          np[i] = rgb(180, 180, 180)
    # foggy +++++++++++++++++++++++++++++++++
    elif num == 45 or num == 48:
      if animFrame == 1:
        for i in outerRing:
          np[i] = rgb(150, 150, 200)
      elif animFrame == 2:
        for i in innerRing:
          np[i] = rgb(150, 150, 200)
    # drizzle +++++++++++++++++++++++++++++++
    elif num == 51 or num == 53 or num == 55 or num == 56 or num == 57:
      for i in innerRing:
        np[i] = rgb(100, 100, 100)
      for x in range(6):
        np[random.randrange(9, 69)] = rgb(0, 0, 255)
    # rain ++++++++++++++++++++++++++++++++++
    elif num == 61 or num == 63 or num == 65 or num == 66 or num == 67:
      for i in innerRing:
        np[i] = rgb(100, 100, 100)
      randrange1 = random.randrange(9,26)
      for i in range(randrange1, randrange1+7):
        np[i] = rgb(0, 0, 255)
      randrange2 = random.randrange(33,57)
      for i in range(randrange2, randrange2+12):
        np[i] = rgb(0, 0, 255)


animTimer = 0
animFrame = 1
timeTravelling = False

def overlay():
  rValue = rotary.value()
  for i in selector[rValue]:
    if rValue > 11:
      np[i] = rgb(255, 165, 0)
    else:
      np[i] = rgb(255, 0, 0)

def update():
  for i in range(0,69):
    np[i] = (0, 0, 0)

  if timeTravelling == False:
    animation(currentDayNight, currentCode)
  elif timeTravelling == True:
    rValue = rotary.value()
    animation(forecastDayNight[rValue], forecastCode[rValue])
    overlay()
  
  np.write()

val_old = rotary.value()
while True:
  val_new = rotary.value()

  if currentData == None:
    getData()

  if button.value() == 0:
    timeTravelling = False

  if val_new != val_old:
    val_old = val_new
    if timeTravelling == False:
      timeTravelling = True
      currentTime = currentData['time']
      forecastTimes = forecastData['time']
      rotaryTime = forecastTimes.index(min(forecastData['time'], key= lambda x: abs(x - currentTime)))
      rotary.set(value = rotaryTime)

  if animTimer == 10:
    animTimer = 0
    if animFrame == 1:
      animFrame = 2
    elif animFrame == 2:
      animFrame = 1
  else:
    animTimer += 1

  update()
  time.sleep_ms(50)