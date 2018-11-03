from random import randint , random

def randperm(x):
    le=len(x)
    z=[]
    n=0
    for i in range(le):
        a=randint(0,len(x)-1)
        
        z.append(x[a])
        del x[a]     
    return z
   


n=int(input("Podaj n"))
l=[]

for i in range (0,n):
    l.append(i)
    


print(randperm(l))


