#ifndef SINUS_H_INCLUDED
#define SINUS_H_INCLUDED

#include "Operator1.h"
#include <cmath>


class sinus : public Operator1{

public:
    double oblicz()const{return sin(a->oblicz());};

    sinus(wyrazenie *a): Operator1(a) { };

    string formatuj_wyrazenie()const{return "sin (" + a->formatuj_wyrazenie() + ")";};
};
//--------------------------------------------------
class cosinus : public Operator1{

public:
    double oblicz() const{return cos(a->oblicz());};

    cosinus(wyrazenie *a){ this->a = a; };

    string formatuj_wyrazenie()const{return "cos (" + a->formatuj_wyrazenie() + ")";};
};
//--------------------------------------------------
class bezwzgledna : public Operator1{

public:
    double oblicz()const{return fabs(a->oblicz());};

    bezwzgledna(wyrazenie *a){ this->a = a; };

    string formatuj_wyrazenie()const{return "|" + a->formatuj_wyrazenie() + "|";};
};
//--------------------------------------------------
class odwrotna : public Operator1{

public:
    double oblicz()const{return pow(a->oblicz(),-1);};

    odwrotna(wyrazenie *a){ this->a = a; };

    string formatuj_wyrazenie()const{return a->formatuj_wyrazenie() + "^-1";};
};
//--------------------------------------------------
class przeciwna : public Operator1{

public:
    double oblicz()const{return (-1)*(a->oblicz());};

    przeciwna(wyrazenie *a){ this->a = a; };

    string formatuj_wyrazenie()const{return "(-1)*" + a->formatuj_wyrazenie();};
};
//--------------------------------------------------
class lognat : public Operator1{

public:
    double oblicz()const{return log2(a->oblicz());};

    lognat(wyrazenie *a){ this->a = a; };

    string formatuj_wyrazenie()const{return "log2 " + a->formatuj_wyrazenie();};
};
//--------------------------------------------------
class exponent  : public Operator1{

public:
    double oblicz()const{return exp(a->oblicz());};

    exponent (wyrazenie *a){ this->a = a; };

    string formatuj_wyrazenie()const{return "e" + a->formatuj_wyrazenie();};
};

#endif // SINUS_H_INCLUDED
