def jedynka(l):
    suma=0
    for e in l:
        if len(str(e))==2 and e%2==0:
            suma+=e
    return suma




l=[14,13,12,11,2]

def rozne(l1):
          
    return len(set([e.lower() for e in l1]))


l1=['a','b','A','c','b']
print(rozne(l1))


a=[1,2,3,4]
b=[2,2,2,2]
def prawie_rosnacy(La):
    ile=0
    for i in range(len(La)-1):
        if La[i]>La[i+1]:
            ile+=1
        
    if(ile<2):
        return True
    return False



La=[1,2,3,2,4,2,3,4,5,6]
print(prawie_rosnacy(La))




    


                
                
      
