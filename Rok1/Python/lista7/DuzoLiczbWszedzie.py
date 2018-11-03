from duze_cyfry import dajCyfre
from turtle import *
from random import *
import random

zbior=[0,1,2,3,4,5,6,7,8,9]

for i in range(30):
    liczba=randint(0,9)
    tracer(0,1)
    a=randint(-150,150)
    b=randint(-150,150)
    c=a
    R = random.random()
    G = random.random()
    B = random.random()
    for x in dajCyfre(liczba):
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
        a=c



