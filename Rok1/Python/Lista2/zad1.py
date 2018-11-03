
n=input("Podaj n")
k=input("Podaj k")
def jeden(k):
    for i in range(int(k)):
        print((" "*int(k)+"#"*int(k))*int(n))
def dwa(k):
    for i in range(int(k)):
        print(("#"*int(k)+" "*int(k))*int(n))

for i in range(int(n)):
    jeden(k)
    dwa(k)


