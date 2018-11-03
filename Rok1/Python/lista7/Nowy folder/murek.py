from turtle import *
import random

def kwadrat(bok):
   R = random.random()
   G = random.random()
   B = random.random()      
   color(R,G,B)
   begin_fill()
   for i in range(4):
     fd(bok)
     rt(90)
   end_fill()
   
def murek(s,bok):
  for a in s:
    if a == 'f':
       kwadrat(bok)
       fd(bok)
    elif a == 'b':
       kwadrat(bok)
       fd(bok)       
    elif a == 'l':
       bk(bok)
       lt(90)
    elif a == 'r':
      rt(90)
      fd(bok)



ht()

tracer(0,0) # szybkie rysowanie    
murek('ffffrfrffflflfffrfrfff',16)


update() 


