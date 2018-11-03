
niebieska = """
.........#####.
...............
..#####........
...............
.........#.....
......#........
....######.....
.....###.......
......##.......
....#.#....#...
......#........
.##....#.......
......#........
....######.....
..#######......
"""

czerwona="""
...............
...............
...............
$..............
$..............
$..............
$..$$$$$.......
...............
...............
....$..........
...............
...............
...............
...............
...............

"""
T=[]
licznik=0
for x in niebieska.split():
    k=0
    for y in czerwona.split():
     if(k==licznik):
        T.append(x+y)
        licznik+=1
        break
     k+=1



    
def pisz(T):
  for wiersz in T:
    print (''.join(wiersz))

def sasiedzi(x,y):
  wynik = []
  for dx,dy in [ (-1,-1), (-1, 1), (1,-1), (1,1), (0,-1), (0,1), (1,0), (-1,0)]:
    nx = (x + dx) % MX
    ny = (y + dy) % MY
    wynik.append( (nx, ny) )
  return wynik
      
MY = len(T)    
MX = len(T[0])
    
def pusta_tablica():
  return [ MX * ['.'] for i in range(MY)]

def nowe_pokolenie(T):
  P = pusta_tablica()
  for y in range(MY):
    for x in range(MX):
        liczba_sasiadow = 0
        for nx,ny in sasiedzi(x,y):
          if T[ny][nx] == '#':
            liczba_sasiadow += 1
        if T[y][x] == '#' and liczba_sasiadow in [2,3]:
          P[y][x] = '#'
        elif T[y][x] == '.' and liczba_sasiadow == 3:
          P[y][x] = '#'
        liczba_sasiadow=0
        for nx,ny in sasiedzi(x,y):
          if T[ny][nx] == '$':
            liczba_sasiadow += 1
        if T[y][x] == '$' and liczba_sasiadow in [2,3]:
          P[y][x] = '$'
        elif T[y][x] == '.' and liczba_sasiadow == 3:
          P[y][x] = '$'
              
  return P
def cos(T):
    G=pusta_tablica() 
    for y in range(MY):
        for x in range(MX):
            if(T[y][x]!="#"):
                G[y][x]="."
            else:
                G[y][x]="#"
                
             
    return G           
def cos1(T):
    G=pusta_tablica()
    for y in range(MY):
        for x in range(MX):
            if(T[y][x]!="$"):
                G[y][x]="."
            else:
                G[y][x]="$"    
               
    return G            
               

licznik = 0
historia1 = set()

  
while True:
  licznik += 1
  pisz(T)
  T = nowe_pokolenie(T)
  W=T[:]
  W1=T[:]
  if str(cos(W)) in historia1 :
    print ('koniec:', licznik,"WYGRYWA $$$$$")
    break
  if str(cos1(W1)) in historia1 :
    print ('koniec:', licznik,"WYGRYWA ######")
    break     
  historia1.add(str(cos(W)))
  historia1.add(str(cos1(W1)))
  print()
  input()
  
