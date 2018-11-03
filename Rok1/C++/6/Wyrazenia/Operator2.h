#ifndef OPERATOR2_H_INCLUDED
#define OPERATOR2_H_INCLUDED
#include "Operator1.h"
using namespace std;
class Operator2 : public Operator1 {

public:
    string opis()const{return "Wartosc " + to_string(oblicz());};
protected:
    wyrazenie *b;
    Operator2(wyrazenie *_a, wyrazenie *_b) Operator1(_a), b(_b) {}
};

#endif // OPERATOR2_H_INCLUDED
