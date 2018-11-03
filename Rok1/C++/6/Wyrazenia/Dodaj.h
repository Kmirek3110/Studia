#ifndef DODAJ_H_INCLUDED
#define DODAJ_H_INCLUDED
#include "Wyrazenie.h"
#include "Operator2.h"
#include <stdexcept>
using namespace std;
class dodaj : public Operator2{

public:
    virtual double oblicz() const;

    virtual string opis() const ;

    dodaj(wyrazenie *a, wyrazenie *b);

    string formatuj_wyrazenie()const;


};
//--------------------------------
class odejmij : public Operator2{

public:
    virtual double oblicz() const;

    odejmij(wyrazenie *a, wyrazenie *b);

    string formatuj_wyrazenie() const;


};
//--------------------------------
class podziel : public Operator2{

public:
    virtual double oblicz() const;

    podziel(wyrazenie *a, wyrazenie *b);

    string formatuj_wyrazenie() const;


};
//--------------------------------
class pomnoz : public Operator2{

public:
    virtual double oblicz() const;

    pomnoz(wyrazenie *a, wyrazenie *b);

    string formatuj_wyrazenie() const;


};
//--------------------------------
class potega : public Operator2{

public:
    virtual double oblicz() const;


    potega(wyrazenie *a, wyrazenie *b);

    string formatuj_wyrazenie() const;


};
//--------------------------------
class logarytm : public Operator2{

public:
    virtual double oblicz() const;

    logarytm(wyrazenie *a, wyrazenie *b);

    string formatuj_wyrazenie() const;


};
//--------------------------------


#endif // DODAJ_H_INCLUDED
