def only_one(lista):
    tab=[]
    for element in lista:
        b=element
        if b not in tab:
            tab.append(b)
            
    return tab







l=[1,2,3,1,2,3,8,2,2,2,9,9,4]
print(only_one(l))
