#ifndef WYRAZENIE_H_INCLUDED
#define WYRAZENIE_H_INCLUDED

#include <string>

using namespace std;

class wyrazenie {

public:
    virtual double oblicz() const   = 0;
    virtual string formatuj_wyrazenie() const = 0;
    virtual string opis()  const  = 0;
};




#endif // WYRAZENIE_H_INCLUDED
