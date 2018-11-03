#ifndef ZMIENNA_H_INCLUDED
#define ZMIENNA_H_INCLUDED

#include "Wyrazenie.h"
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;
class zmienna : public  wyrazenie{
public:
    virtual double oblicz()const;

    virtual string opis() const;

    void newPair(string k, double s);

    void setValue(double newValue) ;


    zmienna(const string &value);

    string formatuj_wyrazenie()const ;
private:
    const string value ;
    vector< pair<string, double> > myVector;
};
#endif // ZMIENNA_H_INCLUDED
