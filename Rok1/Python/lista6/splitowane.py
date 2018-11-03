def split(X):
    tab2=[]
    
    i=0
    napis=""
    for wraz in range(len(X)):
        if(X[wraz]!=' '):
            napis+=X[wraz]
        else:
            tab2.append(napis)
            napis=""
    tab2.append(napis)

    tab3=[]
    for element in tab2:
        if element!='':
            tab3.append(element)
    print (tab3)
tab="  Ala   ma    kota  plota cota lota     acakosda z"
split(tab)
