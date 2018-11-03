from turtle import fd, bk, lt, rt, pu, pd, speed,tracer
from random import random,randint
speed('fastest')
x=[2,1,0]


n=30
m=8
for i in range(40):
    lt(90)
    fd(n)
    rt(90)
    fd(m)
    rt(90)
    fd(n)
    rt(90)
    fd(m)
    rt(180)
    fd(m)
    z=randint(0,4)
    n+=z
