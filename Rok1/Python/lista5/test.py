def F(n,ile):
    if n!=1:
        if n % 2 == 0: 
            ile+=1
            return F(n / 2,ile)
        else:
            ile+=1
            return F(3 * n + 1,ile)
    return ile
ilosc=0
print(F(9,ilosc))
16+3+19=38/3
