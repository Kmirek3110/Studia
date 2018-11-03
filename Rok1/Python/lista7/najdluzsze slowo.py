z=open("dlu.txt").read().split()
import string
exclude = set(string.punctuation)


dlugosc=0


for element in z :
    for c in string.punctuation:
        element=element.replace(c,"")
    if len(element)>dlugosc:
        naj=[]
        naj.append(element)
        dlugosc=len(element)
    elif len(element)==dlugosc:
        naj.append(element)
        dlugosc=len(element)
print(sorted(naj))
    
