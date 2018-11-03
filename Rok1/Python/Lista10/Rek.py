def a(L,w):
    w.add(sum(L))    
    for e in L:
        K=L[:]
        K.remove(e)
        a(K,w)
    return w


wynik = set()
L=[1,2,3,100]
print(sorted(a(L,wynik)))


