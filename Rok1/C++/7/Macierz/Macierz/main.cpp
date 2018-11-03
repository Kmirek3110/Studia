#include <iostream>
#include <bits/stdc++.h>
#include <sstream>
#include <string>
#include "Macierz.hpp"
#include "Wyjatki.hpp"


using namespace std;

using namespace Obliczenia;

/*double Wyznacznik(const Macierz &m)
{

    if(m.getWiersze()!=m.getKolumny())
        throw(rozmiary_nie_pasuja());
    else
        if(m.getKolumny()==1)return m.getTab()[0][0];
        else
        {
            double result=0;
            for(int i=0;i<m.getKolumny();i++)
                result+=(i%2 == 0 ? 1:(-1))*m.tab[0][i]*Wyznacznik(m.Wykresl_wierszkolumne(0,1));
            return result;
        }
}*/

int main()
{

    Obliczenia::Macierz *m= new Macierz(4,2);
    cout<<*m<<endl;

    Obliczenia::Macierz *n=new Macierz(6);
    cout<<*n<<endl;
    *n*=5;
    cout<<*n<<endl;

    n->Dodaj_wielokrotnosc_w(2,3,4);
    cout<<*n<<endl;
    n->Dodaj_wielokrotnosc_k(2,3,4);
    cout<<*n<<endl;
    n->Transpozycja();
    cout<<*n<<endl;


    n->Zamien_kolumne(1,4);
    cout<<*n<<endl;

    n->Zamien_wiersz(3,2);
    cout<<*n<<endl;


    Macierz *p= new Macierz(7);
    cout<<*p<<endl;
    p->Wykresl_wierszkolumne(2,3);
    cout<<*p<<endl;


    return 0;
}
