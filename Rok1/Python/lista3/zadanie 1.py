
szcz=0
ile=0
napis="777"
li=0
for i in range(2,100000):
    pierwsze=0
    tak=str(i)
    if(napis in tak):
        for l in range(1,i):
            if(i%l==0):
                pierwsze+=1
                if(pierwsze>1):
                    break
    if(pierwsze==1):
        li+=1
        print (tak)    
            

    
    
        

print ("illosc liczb szczesliwych " ,li)
