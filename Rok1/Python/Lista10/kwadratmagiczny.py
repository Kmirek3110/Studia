def B(n,a,b,s):
    if n==0:
        print(s)
        return
    if n==1:
        for i in range(a,b+1):
            if s!='':
              if int(s[len(s)-1])<=i:
                 print (s+str(i))
            else:
                print(i)
        return
    if s!='':
        while a < int(s[len(s)-1]): a+=1
    for i in range(a,b+1):
            for j in range(i,b+1):
                    B(n-2,i,b, s + str(i) + str(j))



B(2,1,9,'')
