#include "Wymierna.h"

namespace Obliczenia{


void Wymierna::Ustaw(long long licznik, long long mianownik)throw(dzielenie_przez0,przekroczenie_zakresu){

    if(licznik > INT_MAX || mianownik > INT_MAX || licznik < INT_MIN || mianownik < INT_MIN)
        throw(przekroczenie_zakresu());

    if(mianownik == 0) throw (dzielenie_przez0());
    if(nwd(licznik, mianownik) != 1)
    {
        int a=nwd(licznik,mianownik);
        licznik=licznik/a;
        mianownik=mianownik/a;
    }
    if(mianownik < 0) {

        this->licznik = (-1)*licznik;
        this->mianownik = (-1)*mianownik;
    }
    else {
        this->licznik = licznik;
        this->mianownik = mianownik;
    }

}
Wymierna::Wymierna(int licznik,int mianownik){
            Ustaw(licznik, mianownik);
}
Wymierna::Wymierna(int liczba):licznik(liczba),mianownik(1){};



int Wymierna::getLicznik()const {return licznik;}
int Wymierna::getMianownik()const  {return mianownik;}

int Wymierna::nwd(int a, int b) const  {

    a = std::abs(a);
    b = std::abs(b);

    while(a!=b)
        if(a>b) a-=b;
        else b-=a;
    return a;
}

int Wymierna::nww(int a, int b)const
{
    return a/nwd(a,b)*b;
}

Wymierna::operator int () const{

    return licznik/mianownik;
}

Wymierna::operator double ()const {

    return 1.0*licznik/mianownik;
}

Wymierna operator+(const Wymierna &a, Wymierna &b) throw (przekroczenie_zakresu)
{
    long long   mia;

    mia = b.nww(b.mianownik, a.mianownik);

    Wymierna c= Wymierna(a.licznik*mia + b.licznik*mia,a.mianownik*mia+b.mianownik*mia );

    return c;
}


Wymierna operator-(const Wymierna &a, Wymierna &b)throw (przekroczenie_zakresu) {
    long long   mia;

    mia = b.nww(b.mianownik, a.mianownik);

    Wymierna c= Wymierna(a.licznik*mia - b.licznik*mia,a.mianownik*mia-b.mianownik*mia );

    return c;
}

Wymierna operator*(const Wymierna &a, Wymierna &b)throw (przekroczenie_zakresu) {
    Wymierna c=Wymierna(b.mianownik*a.mianownik,b.licznik*a.licznik);
    return c;
}

Wymierna operator/(const Wymierna &a, Wymierna &b)throw (przekroczenie_zakresu) {

    Wymierna c=Wymierna(b.mianownik*a.licznik,b.licznik*a.mianownik);
    return c;
}


Wymierna operator--(Wymierna &a) {
    a.licznik = (-1) * a.licznik;
    return a;
}
Wymierna operator !(Wymierna& a)
{
    a.Ustaw(a.getMianownik(),a.getLicznik());
    return a ;
}

std::ostream& operator << (std::ostream &wy, const Wymierna &w){

    return wy << 1.0*w.licznik/w.mianownik;
}

}
