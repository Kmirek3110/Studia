def napis_z_liczbami(L):
    w=len(str(L))
    q=''
    if(w==1):
        z=1
    if(w==2):
        z=10
    if(w==3):
        z=100
    if(10<int(L)<20):
        q+=' '+liczby[L]
    else:
        for i in str(L):
            i=int(i)
            i=i*z
            z/=10
            q+=' '+liczby[i]
    return q   
def napis_z_liczbami1(L):
    q=[]
    for i in L:
        i=str(i)
        for x in i:
            if x=='0' or x=='1' or x=='2' or x=='3' or x=='4' or x=='5' or x=='6' or x=='7' or x=='8' or x=='9':
                q.append(napis_z_liczbami(int(i)))
                break
            else:
                q.append(i)
                break
    return q           
liczby = {
  1 : 'jeden',
  2 : 'dwa',
  3 : 'trzy',
  4 : 'cztery',
  5 : 'pięć',
  6 : 'sześć',
  7 : 'siedem',
  8 : 'osiem',
  9 : 'dziewięć',
  10 : 'dziesięć',
  11 : 'jedenaście',
  12 : 'dwanaście',
  13 : 'trzynaście',
  14 : 'czternaście',
  15 : 'piętnaście',
  16 : 'szesnaście',
  17 : 'siedemnaście',
  18 : 'osiemnaście',
  19 : 'dziewiętnaście',
  20 : 'dwadzieścia',
  30 : 'trzydzieści',
  40 : 'czterdzieści',
  50 : 'pięćdziesiąt',
  60 : 'sześćdziesiąt',
  70 : 'siedemdziesiąt',
  80 : 'osiemdziesiąt',
  90 : 'dziewięćdziesiąt',
  100 : 'sto',
  200 : 'dwieście',
  300 : 'trzysta',
  400 : 'czterysta',
  500 : 'pięćset',
  600 : 'sześćset',
  700 : 'siedemset',
  800 : 'osiemset',
  900 : 'dziewięćset'
}




print(napis_z_liczbami(123))
print(napis_z_liczbami1(['Ala', 'ma', 13, 'kotów', 'i', '57' ,'kanarków','gatunku',256]))









