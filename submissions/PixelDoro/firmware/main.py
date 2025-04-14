import time
from neopixel import Neopixel
from random import randint,choice
from machine import Pin
from rotary_irq_rp2 import RotaryIRQ

num_ring=17
ring=Neopixel(num_ring, 3, 0, "GRB")
status=Neopixel(1,0,1,"GRB")
timer=Neopixel(4,2,2,"GRB")

button=Pin(6, machine.Pin.IN, machine.Pin.PULL_UP)
progressColor="violet"

c = {
  "blue":(0,0,255),
  "red":(255,0,0),
  "yellow":(255,255,0),
  "green":(0,255,0),
  "0":(0,0,0),
  "halfRed":(127,0,0),
  "orange":(255,69,0),
  "lightGreen":(144,238,144),
  "sky":(135,236,235),
  "indigo":(75,0,130),
  "violet":(127, 0, 255)
}

cMap={
  "0":"0",
  "1":"halfRed",
  "2":"red",
  "3":"orange",
  "4":"yellow",
  "5":"lightGreen",
  "6":"green",
  "7":"sky",
  "8":"indigo",
  "9":"violet"

}


sec=0
paused=False
cInd=0
SW=Pin(8, Pin.IN, Pin.PULL_UP)  

r=RotaryIRQ(pin_num_clk=6,
              pin_num_dt=7,
              min_val=0,
              reverse=False,
              range_mode=RotaryIRQ.RANGE_UNBOUNDED) 

val_old=r.value() 

## Functions
# Lights up random leds with random colors
def randomLit():
  status.set_pixel(0,c["green"])
  status.show()
  num=randint(0,num_ring)
  led_pos=[]
  for i in range(num):
    led_pos.append(randint(0,num_ring-1))

  for x in led_pos:
    ring.set_pixel(x,c[choice(list(c.keys()))])
    ring.show()
    time.sleep(0.1)

def cycle():
  status.set_pixel(0,c["yellow"])
  status.show()
  for i in range(num_ring):
    ring.set_pixel(i,c[list(c.keys())[cInd]])
    ring.show()
    time.sleep(0.04)

def reset():
  ring.fill((0,0,0))
  timer.fill((0,0,0))

def showMin(n):
  x="{:02d}".format(n)
  for i in range(2):
    timer.set_pixel(i,c[cMap[x[i]]])
    timer.show()

def showSec(n):
  x="{:02d}".format(n)
  for i in range(2):
    timer.set_pixel(i+2,c[cMap[x[i]]])
    timer.show()


def countTime(paused=False):
    if not paused:
        status.set_pixel(0,c["blue"])
        status.show()
        global sec,progressColor
        m=(sec-sec%60)//60
        s=sec%60
        showMin(m)
        showSec(s)
        sec+=1
        percentCompletion=(sec/(25*60))

        progressLeds=int(num_ring*percentCompletion)

        for i in range(progressLeds):
            ring.set_pixel(i,c[progressColor])
            ring.show()

        time.sleep(1)

        if m==26: ## resets at 25 mins
            sec=0
            ring.fill(c["red"])
    else:
        status.set_pixel(0,c["red"])
        status.show()
        time.sleep(0.1)


while True:
  val_new = r.value()
  print(SW.value())
  if SW.value() == 0:
    print("Button Pressed")
    print("Selected Number is:", val_new)
    while SW.value() == 0:
      continue
  if val_old != val_new:
    val_old = val_new
    print('result =', val_new)
  if abs(val_new)==0:
    countTime(paused=paused)
  elif abs(val_new)==1:
    reset()
    cycle()
    cInd=(cInd+1)%10

  elif abs(val_new)==2:
    reset()
    randomLit()
  else:
    countTime(paused=paused)


    
