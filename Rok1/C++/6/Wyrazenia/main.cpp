#include <iostream>
#include <cmath>
#include "Wyrazenie.h"
#include "Stala.h"
#include "Operator0.h"
#include "Operator1.h"
#include "Sinus.h"
#include "E.h"
#include <cstdio>
#include "Dodaj.h"
#include "Zmienna.h"
using namespace std;



int main()
{
    wyrazenie *w = new odejmij(
            new pi(),
            new dodaj(
            new stala(2),
            new pomnoz(
                new zmienna("x"),
                new stala(7)
                    )
                )
);
    cout << w->formatuj_wyrazenie() << endl;
    cout<<w->opis();
    zmienna *x = new zmienna("x");
    zmienna *y = new zmienna("y");
    // ((x+1)*x)/2
    wyrazenie *a = new podziel (
            new pomnoz(
                    new dodaj(
                            x,
                            new stala(1)
                    ),
                    x
            ),
            new stala(2)
    );
    cout << a->formatuj_wyrazenie() << endl;


    // (3+5)/2+x *7
    wyrazenie *b = new podziel (
            new dodaj(
                    new stala(3),
                    new stala(5)
            ),
            new dodaj (
                    new stala(2),
                    new pomnoz(
                            x,
                            new stala(7)
                    )
            )
    );
    cout << b->formatuj_wyrazenie() << endl;



    // 2 + x * 7 / (y*3 + 5)
    wyrazenie *c = new odejmij (new dodaj (
            new stala(2),
            new pomnoz(
                    x,
                    new stala(7)
            )),
            new dodaj (
                       new pomnoz(
                                  y ,
                                  new stala(3))
                                  ,new stala(5)));
    cout << c->formatuj_wyrazenie() << endl;


    // cos((x+1)*x)
    wyrazenie *d = new podziel(
                               new cosinus (
            new pomnoz(
                    new dodaj(
                            x,
                            new stala(1)
                    ),
                    x
            )
    ),(new potega (new e(),new potega (x , new stala(2)))))
                               ;

    cout << d->formatuj_wyrazenie() << endl;


    cout << "A: " << endl;

    for(int i = 0; i < 100; ++i){
        x->setValue(static_cast<double>(i)/100.0);
        cout << a->opis() << endl;
    }

    cout << "B: " << endl;

    for(int i = 0; i < 100; ++i){
        x->setValue((double) i/100 );
        cout << b->opis() << endl;
    }


    cout << "C: " << endl;

    for(int i = 0; i < 100; ++i){
        x->setValue((double) i/100 );
        cout << c->opis() << endl;
    }

    cout << "D: " << endl;

    for(int i = 0; i < 100; ++i){
        x->setValue((double) i/100 );
        cout << d->opis() << endl;
    }



    return 0;
}
