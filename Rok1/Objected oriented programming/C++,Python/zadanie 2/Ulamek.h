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
//Dodawanie U³amków
Ulamek Dodaj(Ulamek A,Ulamek B);
//Odejmowanie U³amków
Ulamek Odejmij(Ulamek A,Ulamek B);
//Mno¿enie U³amków
Ulamek Pomnoz(Ulamek A,Ulamek B);
//Podzia³ U³amków
Ulamek Podziel(Ulamek A,Ulamek B);
//Wypisywanie
Ulamek Wypisz(Ulamek A);





