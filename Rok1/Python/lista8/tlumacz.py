import random

def naj(z):
  b=open("Browna.txt",encoding='utf8').read().split() 
  naj=0
  for i in z:
     ile=b.count(i)
     if(ile>=naj):
      naj=ile
      h=i
  return(h)
  
    
def tlumacz(txt):
  wynik = []
  for p in txt.split():
    if p in pol_ang:
      wynik.append(naj(pol_ang[p]))
    else:
      wynik.append('?' + p)
  return ' '.join(wynik)
      
pol_ang = {} # pusty słownik

for x in open('pol_ang.txt',encoding="utf8"):
  x = x.strip()
  L = x.split('=')
  if len(L) != 2:
    continue
  pol, ang = L
  
  if pol not in pol_ang:
    pol_ang[pol] = [ang]
  else:  
    pol_ang[pol].append(ang)
  
  """
  if pol not in pol_ang:
    pol_ang[pol] = []
  pol_ang[pol].append(ang)  
  """
zdanie = 'dziewczyna spotkać chłopiec i pójść do kino wieczór'
print (tlumacz(zdanie))

