def normalizuj(L):
   "funkcja odejmuje od kazdego elementu listy L srednia wartosc wszystkich elementow tej listy"
   suma=0
   for i in range (len(L)):
       suma+=L[i]
   for j in range (len(L)):
       L[j]-=int((suma)/4)
   
     
          
      
L = [1,2,3,4,5]
L2 = L[:]

print ("")         
print ("Zaczynamy od " + str(L2) + " i normalizujemy 3 razy")

normalizuj(L2); print (L2)
normalizuj(L2); print (L2)
normalizuj(L2); print (L2)           
