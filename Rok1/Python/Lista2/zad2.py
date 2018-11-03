from random import randint


def gra():
    zapas=100
    l=[]
    t=0
    g=0
    while(zapas!=0):
        r=randint(1,6)
        l.append(r)
        print ('Rzut',zapas,'ilosc oczek',l[t])
        if(l[t]>l[t-1]>l[t-2]>l[t-3]>l[t-4]):
            print("Gra skonczona")
            g+=1
            break
        zapas-=1
        t+=1
    if zapas==0 and g==0:
        gra()
        
def gra2():
    zapas=100
    l=[]
    t=0
    g=0
    while(zapas!=0):
        r=randint(1,6)
        l.append(r)
        print ('Rzut',zapas,'ilosc oczek',l[t])
        if(t>=6 and (l[t]>=l[t-1]>=l[t-2]>=l[t-3]>=l[t-4]>=l[t-5])):
            print("Gra skonczona")
            g+=1
            break
        zapas-=1
        t+=1
    if zapas==0 and g==0:
        gra2()
n=input("Jesli ciag ma byc rosnocy wpisz '1' w przeciwnym wyrazie '2' ")

if int(n)==1:
    gra()
else:
    gra2()


