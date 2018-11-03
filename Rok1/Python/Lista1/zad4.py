from losowanie_fragmentow import losuj_fragment
n=int(input("Podaj n"))
s=''
sum=0
i=0
while (i<10):
    x=losuj_fragment()
    if(sum+len(x)<n-4):
        sum+=len(x)
        s+=x
    elif sum+len(x)==n:
        sum+=len(x)
        s+=x    
    else:
        if(sum+len(x)==n-2):
                sum+=len(x)
                s+=x
        elif(sum+len(x)==n-4):
                sum+=len(x)
                s+=x
        elif(sum+len(x)==n-3):
                sum+=len(x)
                s+=x
    if(sum==n):
        print(s)
        i+=1
        sum=0
        s=''
