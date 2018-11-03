

from turtle import goto,fd,bk,tracer,lt,rt,fillcolor,begin_fill,end_fill,color,colormode,pu,pd
colormode(255)
tracer(0,1)

   
   
    

x=-200
y=300
wiersz=open('kolory.txt').readlines()
for i in wiersz:
    z=i.split()
    for j in z:
        pu()
        goto(x,y)
        pd()
        fillcolor(eval(j))
        begin_fill()
        fd(10)
        rt(90)
        fd(10)
        rt(90)
        fd(10)
        rt(90)
        fd(10)
        rt(90)
        end_fill()
        x+=10
    y-=10
    x=-200









