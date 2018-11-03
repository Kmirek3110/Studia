#ifndef WYMIERNA_H_INCLUDED
#define WYMIERNA_H_INCLUDED
#include <stdexcept>
#include <iostream>
#include <math.h>
#include "Wyjatki.h"
#include <climits>
namespace Obliczenia{

class Wymierna{
    public :

        Wymierna(int licz,int mia) ;
        Wymierna (int liczba);

        int getLicznik() const ;
        int getMianownik() const ;
        int nwd  (int a ,int b)const;
        int nww (int a , int b) const ;


        friend Wymierna operator+(const Wymierna &a, Wymierna &b) throw (przekroczenie_zakresu);

        friend Wymierna operator-(const Wymierna &a, Wymierna &b)throw (przekroczenie_zakresu);

        friend Wymierna operator*(const Wymierna &a, Wymierna &b)throw (przekroczenie_zakresu);

        friend Wymierna operator/(const Wymierna &a, Wymierna & b)throw (przekroczenie_zakresu);

        friend std::ostream &operator<<(std::ostream &wy, const Wymierna &a);

        friend Wymierna operator--(Wymierna &a);
        friend Wymierna operator !(Wymierna &a);
        operator int ()const;
        operator double ()const;

    private:
        void Ustaw(long long  licznik,long long  mianownik)throw (dzielenie_przez0,przekroczenie_zakresu);
        int licznik;
        int mianownik ;


    };
}

#endif // WYMIERNA_H_INCLUDED
