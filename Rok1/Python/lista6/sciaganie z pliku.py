
slowa=open('slowa.txt',encoding="utf8").read().split()



t=[]
a=0
s=set(slowa)
for i in slowa:
  z=i[::-1]
  if(z in s and z not in t):
   t.append(z)

for i in t:
  j=i[::-1]
  print(i,"   ",j)
