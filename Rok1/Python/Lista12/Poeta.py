import random


item="a"
dl = 10

dane = open('Thadius.txt',encoding='utf-8').read().split()

slownik={}
for i in range(len(dane)-1):
    if dane[i] in slownik:
        slownik[dane[i]].append(dane[i+1])
    else:
        slownik[dane[i]]=[dane[i+1]]


odp=[]

for i in range(dl):
    item = random.choice(slownik[item])
    odp.append(item)
    
    
print(odp)
