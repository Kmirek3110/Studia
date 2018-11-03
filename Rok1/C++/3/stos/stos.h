#include<stdexcept>
#include<cmath>
#include <initializer_list>
#ifndef ZADANIE3_STOS
#define ZADANIE3_STOS
using namespace std;

class stos{

    int pojemnosc;
    int ile;
    string *stk ;
public:
    stos();
    stos(int poj);
    stos(initializer_list<string> lista);
    stos(const stos &a);
    stos(stos&&x);
    stos & operator=(const stos& x);
    stos & operator=(stos&&x);

    void wloz(const string &cos);
    void sciagnij();
    const string sprawdz() ;
    const int rozmiar() ;
    void wypisz();
    ~stos();


};


#endif
