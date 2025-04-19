import board
import neopixel
import time
import adafruit_ahtx0
i2c = board.i2c(scl=board.D36, sda=board.D37)
tempsensor = adafruit_ahtx0_AHTx0(i2c)
pxr = neopixel.NeoPixel(board.D38, 9, brightness=0.5) #8+inbuilt neopixel
pxl = neopixel.Neopixel(board.D14, 8, brightness=0.5)
def ramp(neo):
    for b in range (3):
        for px in neo:
            px = (16+b*16, 16+b*16, 16+b*16) #slowly power on, idk if my caacitor is good enough
        time.sleep(0.5)
ramp(pxr)
ramp(pxl)
def env():
    humIndex = round(tempsensor.relative_humidity/10)
    if humIndex < 3:
        finIndex = abs(round(humIndex/2)) # max finIndex 1 at humIndex 2, max hum 0.24
        print(f"low humIndex")
    elif (humIndex > 6):
        finIndex = round(humIndex/2)+2
    else:
        finIndex = humIndex-1
        print("normal")
    tempAdjust = tempsensor.temp/30
    print(tempAdjust)
    tempColor = (finIndex, (64+64*tempAdjust, 32+32*tempAdjust,32))
    print(tempColor)
    return tempColor

def bars(pxbar, offset, tarlen, color):
    for i in range(offset, tarlen+offset):
        pxbar[i] = color
    
envs = (0,(0,0,0))
while True:
    lastenv = envs
    envs = env()
    if envs != lastenv:
        bars(pxr, 1, envs[0], envs[1])
        bars(pxl, 0, envs[0], envs[1])
    time.sleep(2)
