from turtle import *
import random
from random import*

tracer(0,1)
t=['red','blue','green','black','yellow','violet','orange']


def sierpinski(dl,n):
        
	if n==0:
		begin_fill()
		color(choice(t))
		forward(dl)
		left(120)
		forward(dl)
		left(120)
		forward(dl)
		left(120)
		end_fill()
		

	else:
		sierpinski(dl/2,n-1)
		forward(dl/2)
		sierpinski(dl/2,n-1)
		left(120)
		forward(dl/2)
		right(120)
		sierpinski(dl/2,n-1)
		right(120)
		forward(dl/2)
		left(120)

	


print(sierpinski(250,5))               
                


