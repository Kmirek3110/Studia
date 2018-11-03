#ifndef OPERATOR0_H_INCLUDED
#define OPERATOR0_H_INCLUDED
#include "Wyrazenie.h"

using namespace std;
class Operator0 : public wyrazenie {

public:
    string opis()const {return "Wartosc " + to_string(oblicz());}
};

#endif // OPERATOR0_H_INCLUDED
