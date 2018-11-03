b=open("Szyfrogram.txt").readline().split()
x=set(open("slowa.txt",encoding='utf8').read().split())
from cezar import szyfruj
lista=[]
for i in b:
    licznik=1
    for y in range(31):
        b=szyfruj(i,y)
        print(b)
        if b in x:
            print(b)
            break
        else:
            licznik+=1
        
        
        
        
