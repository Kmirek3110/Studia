napis='7777777'
szcz=0
licz=0
for i in range(1007777777,9999999999,100):
    pierwsze=0
    tak=str(i)
    if(napis in tak):
        for l in range(2,10000):
            if(i%l==0):
                pierwsze+=1
                break
        if(pierwsze==0):
            print(tak)
            licz+=1
print(licz)            
