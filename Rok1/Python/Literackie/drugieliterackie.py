x=open("Thadius.txt",encoding="utf8").read().split()
b=set(open("slowa.txt",encoding='utf8').read().split())
u = {'.',',',':',';','>','-'}
l="a"
slowo=""
for e in x:
    for y in e:
        
        if(y.lower() not in u):
            slowo+=y.lower()
            break
j=0

for a in slowo:
    test=""
    if j<len(slowo)-10:
        for i in range(j,j+9):
            test+=slowo[i] 
            if(test in b):
                if(len(test)>len(l)):
                    l=test
                    print(l)
                  
    j+=1
print(l)    
    
