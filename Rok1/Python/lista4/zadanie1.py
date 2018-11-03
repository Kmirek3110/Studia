from turtle import *
import random

tracer(0,1)

def kwadrat(bok, kolor):
  fillcolor(kolor)
  begin_fill()
  for i in range(4):
    fd(bok)
    rt(90)
  end_fill()

BOK = 20
for i in range(10):
  for i in range(10):
    R = random.random()
    G = random.random()
    B = random.random()
    print(R,G,B)
    kwadrat(BOK, (148,152,153))
    fd(BOK)
  rt(90)
  fd(BOK)
  rt(90)
  fd(BOK*10)
  lt(180)

