#include "Operator0.h"
#include <cmath>
#include <cstdio>
#ifndef E_H_INCLUDED
#define E_H_INCLUDED
#define m_e 2.71828182846;
constexpr double m_pi = 3.1415;
#define m_fi 1.6180 ;



using namespace std;
class e : public Operator0{

public:
    double oblicz()const{return m_e ;};

    string formatuj_wyrazenie()const{return to_string(oblicz());};

};
//-------------------------------
class pi : public Operator0{

public:
    double oblicz()const{return m_pi;};

    string formatuj_wyrazenie()const{return to_string(oblicz());};

};
//-------------------------
class fi : public Operator0{

public:
    double oblicz() const {return m_fi;};

    string formatuj_wyrazenie()const{return to_string(oblicz());};

};

#endif // E_H_INCLUDED
