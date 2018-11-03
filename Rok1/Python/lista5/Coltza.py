from statistics import median

def F(n,ile):
    if n!=1:
        if n % 2 == 0: 
            ile+=1
            return F(n / 2,ile)
        else:
            ile+=1
            return F(3 * n + 1,ile)
    return  ile

def AnalizaColtz(n,m):
    tab=[]
    srednia=0
    ile=0
    for i in range(n,m+1):
        ile+=1
        ilosc=0
        srednia+=F(i,ilosc)
        print ('energia',i, 'wynosi',F(i,ilosc))
    tab.append("Srednia wynosi")
    tab.append(srednia/ile)
    #return (srednia/ile)
    max=0
    min=9999999999999
    cos=[]
    for i in range(n,m+1):
        
        ile+=1
        ilosc=0
        cos.append(F(i,ilosc))
    sorted(cos)
    tab.append("Mediana wynosi")
    tab.append(median(cos))
       
    for i in range(n,m+1):
        ile+=1
        ilosc=0
        if(max<F(i,ilosc)):
            max=F(i,ilosc)
        if(min>F(i,ilosc)):
            min=F(i,ilosc)
    tab.append("Max wynosi")
    tab.append(max)
    tab.append("Min wynosi")
    tab.append(min)
    return tab    

    

a=int(input("Podaj a"))
b=int(input("Podaj b"))
ilosc=0

print(AnalizaColtz(a,b))
   
