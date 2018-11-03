from duze_cyfry import dajCyfre
n=int(input("Podaj liczbe 5cyfrowa"))
tab=[]
i=0
z=len(str(n))
while(z!=0):
    cyfra=n%10
    tab.append(int(cyfra)) 
    n/=10
    i+=1
    z-=1
while (i-1>=0):  
    for r in dajCyfre(int(tab[i-1])): print (r)
    i-=1
