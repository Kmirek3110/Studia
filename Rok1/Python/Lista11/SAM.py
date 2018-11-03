import random

slowo = 'tak'
dl = 20

dane = open('Thadius.txt',encoding='utf8')


slownik={}
for i in range(len(dane)-1):
    if dane[i] in slownik:
        slownik[dane[i]].append(dane[i+1]) 
    else:
        slownik[dane[i]]=[dane[i+1]]


out=[slowo]

for i in range(dl):
    item = random.choice(slownik[slowo])
    out.append(item)
    slowo=item
    
print(out)
