#ifndef OPERATOR1_H_INCLUDED
#define OPERATOR1_H_INCLUDED

#include "Operator0.h"

class Operator1 : public Operator0{

public:

    std::string opis() const {

    return "Wartosc " + std::to_string(oblicz());

};

protected:
    wyrazenie *a;
    Operator1(wyrazenie *_a): a(_a) {}
};

#endif // OPERATOR1_H_INCLUDED
