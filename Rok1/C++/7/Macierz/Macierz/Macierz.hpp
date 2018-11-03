#ifndef Macierz_hpp
#define Macierz_hpp

#include <iostream>
#include <bits/stdc++.h>
#include <sstream>
#include <string>
#include "Wyjatki.hpp"

using namespace std;



namespace Obliczenia
{

class Macierz
{
    private:
    double **tab;
    int wiersze;
    int kolumny;
public:

    int getKolumny()const{return kolumny;};
    int getWiersze()const{return wiersze;};
    double ** getTab()const{return tab;};
    Macierz(int l)throw (zly_argument);
    Macierz(int x, int y)throw (zly_argument);
    Macierz (const Macierz &m);
    Macierz (const Macierz &&m);
    Macierz& operator=(const Macierz& m);
    Macierz& operator=(const Macierz &&m);
    ~Macierz();

    friend Macierz operator+ (const Macierz &x, const Macierz &y)throw (rozmiary_nie_pasuja);

    Macierz & operator+= (const Macierz &y)throw (rozmiary_nie_pasuja);

    friend Macierz operator- (const Macierz &x, const Macierz &y)throw (rozmiary_nie_pasuja);

    Macierz & operator-= (const Macierz &y)throw (rozmiary_nie_pasuja);

    friend Macierz operator* (const Macierz &x, const Macierz &y)throw (rozmiary_nie_pasuja);

    Macierz & operator*= (const Macierz &y)throw (rozmiary_nie_pasuja);

    friend Macierz operator* (const Macierz &x, const double s);

    Macierz & operator*= (const double s);

    Macierz Transpozycja();
    Macierz Zamien_wiersz(int a, int b) throw (brak_wiersza);
    Macierz Zamien_kolumne(int a, int b)throw (brak_kolumny);
    Macierz Pomnoz_wiersz(int a,double s)throw (brak_wiersza);
    Macierz Pomnoz_kolumne(int a,double s)throw (brak_kolumny);
    Macierz Dodaj_wielokrotnosc_w(int x, int y, double s)throw (brak_wiersza);
    Macierz Dodaj_wielokrotnosc_k(int x, int y, double s)throw (brak_kolumny);


    friend istream &operator>> (istream &we, Macierz &x);
    friend ostream &operator<< (ostream &wy, const Macierz &x);

};

}




#endif // Macierz_hpp
