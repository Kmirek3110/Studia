z=set(open("test.txt",encoding='utf8').read().split())
from random import*

alfabeton=[]
def cos(x):
    print(x)
    x=str(x)
    for i in x:
        print(i)
def układane(x,z):
    L={}
    for i in z:
        ile=0
        for j in z:
            if(i==j):
                ile+=1
        L[i]=ile
    f=0
    bad="Bad"
    ok="OK"
    for g in x:
        for t in z:
            if g not in z:
                return bad
        ile=0
        for j in x:
            if g==j:
                ile+=1
        if ile<=L[g]:
           f+=1
    if f==len(x):
       return ok
    else:
       return bad
    
 
    
for i in range(3):
    x=sample(z,1)
    if(cos(x)=='gut'):
        alfabeton.append(x)
        break
print(alfabeton)    
    
    


