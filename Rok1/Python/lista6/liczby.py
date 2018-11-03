from duze_cyfry import dajCyfre
from turtle import *
import random

tracer(0,1)
a=0
b=0
R = random.random()
G = random.random()
B = random.random()
for x in dajCyfre(6):
    for y in x:
        if(y!=" "):
            fillcolor(R,G,B)
            begin_fill()
            pu()
            goto(a,b)
            pd()
            fd(10)
            rt(90)
            fd(10)
            rt(90)
            fd(10)
            rt(90)
            fd(10)
            rt(90)
            end_fill()
        a+=10
    
    b-=10
    a=0



