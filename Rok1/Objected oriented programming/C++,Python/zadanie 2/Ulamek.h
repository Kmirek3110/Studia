//Zadanie 2 Programowanie Obiektowe 01.03.2018 Karol Mirek
#include <iostream>
using namespace std;
struct Ulamek
{
	int li,mi;
};

void Dodaj(Ulamek *A,Ulamek B);
void Odejmij(Ulamek *A,Ulamek B);
void Pomnoz(Ulamek *A,Ulamek B);
void Podziel(Ulamek *A,Ulamek B);
void Wypisz(Ulamek *A);
//Dodawanie U�amk�w
Ulamek Dodaj(Ulamek A,Ulamek B);
//Odejmowanie U�amk�w
Ulamek Odejmij(Ulamek A,Ulamek B);
//Mno�enie U�amk�w
Ulamek Pomnoz(Ulamek A,Ulamek B);
//Podzia� U�amk�w
Ulamek Podziel(Ulamek A,Ulamek B);
//Wypisywanie
Ulamek Wypisz(Ulamek A);





