def permutacja(s):
    w={}
    l=[]
    j=1
    so=''
    for i in range(len(s)):
        if(s[i] not in l):
            w[s[i]]=j
            j+=1
            l.append(s[i])
            if(i!=len(s)-1):
                so+=str(w[s[i]])+'-'
            else:
                so+=str(w[s[i]])
        else:
            if(i!=len(s)-1):
                so+=str(w[s[i]])+'-'
            else:
                so+=str(w[s[i]])
    return so











s=input("Podaj słowo")
print(permutacja(s))
