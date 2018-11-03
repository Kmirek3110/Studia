n=int(input("PODAJ N"))

r=n
cos=n
while cos>=1:
    if(n%r==0):
        ile=0
        for i in range(1,r):
           if(r%i==0):
               ile+=1
           if(ile>2):
                break
        if(ile==1):
            print(r)
    r-=1    
    cos-=1
