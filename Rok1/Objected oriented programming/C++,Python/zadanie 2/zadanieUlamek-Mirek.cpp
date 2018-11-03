//Programowanie Obiektowe 01.03.2018 Karol Mirek Zadanie 2 u³amki
// Wejœcie : Podajemy licznik i mianownik ka¿dego z 2 u³amków !!Licznik mo¿e byæ tylko ujemny!!
//Na wyjsciu : Wypisujemy wartoœæ u³amków sprowadzon¹ do wspólnego mianownika , ich sumê , ró¿nicê , iloczyn oraz iloraz
//Jêzyk C++  // Œrodowisko DEV-C++ 5.11
#include <iostream>
#include "Ulamek.h"
#include <stdexcept>
using namespace std;
//Dodawanie
Ulamek Dodaj(Ulamek A, Ulamek B)
{
	Ulamek C;
	C.li= A.li + B.li;
	C.mi = A.mi ;
	B=C;
	return B;
}
//Odejmanie
Ulamek Odejmij(Ulamek A, Ulamek B)
{
	Ulamek C;
	C.li = A.li - B.li;
	C.mi=A.mi;
	B=C;
	return B;
}
//Mno¿enie
Ulamek Pomnoz(Ulamek A, Ulamek B)
{
	Ulamek C;
	C.li = A.li * B.li ;
	C.mi = A.mi * B.mi ;
	B=C;
	return B;
}
//Dzielenie
Ulamek Podziel(Ulamek A,Ulamek B)
{
	Ulamek C;
	C.li= A.li * B.mi;
	C.mi=A.mi * B.li;
	B=C;
	return B;
}
//Inny Sposób przeprowadzania dzia³añ
void Dodaj(Ulamek *A, Ulamek B)
{
	A->li = A->li + B.li;
	A->mi= A->mi ;
}
void Odejmij(Ulamek *A, Ulamek B)
{
	A->li = A->li- B.li;
	A->mi = A->mi ;
}
void Pomnoz(Ulamek *A, Ulamek B)
{	
	A->li = A->li * B.li ;
	A->mi = A->mi * B.mi ;	
}
void Podziel(Ulamek *A,Ulamek B)
{
	
	int X= A->li * B.mi;
	int Y= A->mi*B.li;
	A->li=X;A->li=Y;		
}
int NWD(int a,int b){
	if(a<0)a*=-1;
	if(b<0)b*=-1;
	while(a!=b)
{
if(a>b) a=a-b;
else b=b-a;
}
return a;	
}
Ulamek Wypisz(Ulamek A)
{	
if(A.li&&A.mi!=0)
cout<<A.li/NWD(A.mi,A.li)<<"/"<<A.mi/NWD(A.mi,A.li)<<endl;
else
cout<<0<<endl;
}
int main () {
	Ulamek A,C;
	cout<<"Podaj Licznik 1 ulamka"<<endl;cin>>A.li;
	cout<<"Podaj Mianownik 1 ulamka"<<endl;	cin>>A.mi;
	cout<<"Podaj Licznik 2 ulamka"<<endl;cin>>C.li;
	cout<<"Podaj Mianownik 2 ulamka"<<endl;cin>>C.mi;cout<<endl;
	if((A.mi||C.mi)==0)
	throw invalid_argument("Dzielenie przez zero");
	//Dodatkowy U³amek do sprowadzenia do wspólnego mianownika
	Ulamek A1;A1.li=A.li*C.mi;A1.mi=A.mi*C.mi;
	C.li=A.mi*C.li;
	C.mi=A.mi*C.mi;
	A=A1;
	cout<<"Pierwszy ulamek : ";Wypisz(A);
	cout<<"Drugi ulamek : ";Wypisz(C);;
	Ulamek B=Dodaj(A,C);cout<<"Wynik dodawania : ";Wypisz(B);
	B = Odejmij(A,C);cout<<"Wynik odejmowania : " ;Wypisz(B);
	B= Pomnoz(A,C); cout<<"Wynik mnozenia : ";Wypisz(B);
	B = Podziel(A,C); cout<<"Wynik dzielenia : ";Wypisz(B);	
    return 0;
}

