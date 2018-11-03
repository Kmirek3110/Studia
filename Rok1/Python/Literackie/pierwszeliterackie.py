x=open("lalka.txt").read().split()
b=set(open("slowa.txt",encoding='utf8').read().split())
u = {'ą','ć','ę','ż','ź','ł','ń','ó',"ś"}
import string
q=[]
l=[]
for e in x:
    if(e not in b ):
      l.append(q)
      q=[]
    else:
        ile=0
        for y in e:
            if(y  in u):
                l.append(q)
                q=[]
                ile+=1
                break
        if(ile==0):
            q.append(e)
        
if q not in l:        
    l.append(q)        
dlu=-1

for x in l:
    lo=0
    for y in x:
        lo+=len(y)
    if(lo>dlu):
        dlu=lo
        naj=x
print(naj)
      
        

        
