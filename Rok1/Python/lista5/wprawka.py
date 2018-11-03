def merge(list1,list2):
    tab=[]
    le=len(list1)+len(list2)
    i=0
    j=0
    
    while True:
        if(i<len(list1)):
            a=list1[i]
        
        if(j<len(list2)):
            b=list2[j]
        
        
            
        if(a<b):
            tab.append(a)
            i+=1
        else:
            tab.append(b)
            j+=1
            
        if(len(tab)==le):
            break
        if i==len(list1):
            tab+=list2[j:]
            break
        if j==len(list2):
            tab+=(list1[i:])
            break
    return tab




L=[1,3,4,102, 103, 104]
L2=[0,2,5,6]
print(merge(L,L2))
