from math import sqrt  # pierwiastek kwadratowy


def potega(a, n):
    wynik = 1  # zmienna lokalna
    for i in range(n):
        wynik = wynik * a  # albo: wynik *= a
    return wynik


def kwadrat(n):
    for i in range(n):
        for j in range(n):
            print("*", end="")
        print()


def kwadrat2(n):
    for i in range(n):
        print(n * "#")

        #





dwa=0
for i in range(10):
    print("Przebieg:", i)
    print(20 * "-")
    if 5>i:
        kwadrat(3 + 2 * i)
    else:
        kwadrat2(3+dwa)
        dwa+=1
    print()
    
