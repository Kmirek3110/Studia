#ifndef STALA_H_INCLUDED
#define STALA_H_INCLUDED

#include "Wyrazenie.h"
using namespace std;
class stala : public wyrazenie {
    const int value;// const
public:
    virtual double oblicz() const ;// const

    virtual string opis() const ;// const

    int getValue();

    stala(int value);

    string formatuj_wyrazenie() const ;

};

#endif // STALA_H_INCLUDED
