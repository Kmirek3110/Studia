napis='7777777'
szcz=0

for i in range(9999999999,1000000000,-1):
    pierwsze=0
    tak=str(i)
    if(napis in tak):
        #print(tak)
        for l in range(2,10000):
            if(i%l==0):
                break
        if(pierwsze==0):
            print("LICZBA SUPER TO ",tak)
            break
