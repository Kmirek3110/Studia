x=open("tekst.txt").read().split()


naj=[]
tekst=""
q=[]
for e in x:
    tekst+=" "+e
    if(x.count(tekst)>1):
        if(len(q[0])<len(tekst)):
            q=[tekst]
    else:
        tekst=""
print(q)        
