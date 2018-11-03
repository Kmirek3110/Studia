def ciagi_binarne(N):
  if N == 0:
    return [ [] ]
  return [ [b] + c for b in [True, False] for c in ciagi_binarne(N-1)]  
    
# 2 --> [ [False, False], [False, True], [True, False], [True, True] ]    
def dlugie(F):
    G=F.split()
    zmienne=set()
    for e in G:
      e=list(e)
      if(len(e)>3) and e[0]=='(' and e[1]=='-' and e[-1]==')':
        e=e[2:-1]
      e=''.join(e)
      zmienne.add(e)
    return zmienne  

def wartosciowania(zmienne):
  cb = ciagi_binarne(len(zmienne))
  return [ dict(zip(zmienne, ciag)) for ciag in cb]
  
def wartosc_formuly(F, wart):
  F = F.replace('*', ' and ')
  F = F.replace('+', ' or ')
  F = F.replace('-', ' not ')
  F = F.replace('T',' True ')
  F = F.replace('F',' False ')
  print (F, wart)
  return eval(F, wart)
  

def spelnialna(F):
  
  zmienne = dlugie(F) - set('+* TF')
  for wart in wartosciowania(zmienne):
    if wartosc_formuly(F, wart) == True:
      return True
  return False

def taut(F):
  zmienne = dlugie(F) - set('+* TF')
  for wart in wartosciowania(zmienne):
    if wartosc_formuly(F, wart) == False:
      return False
  return True    
print (spelnialna('(-plotka) * T * r'))  
print (taut('T + F '))
