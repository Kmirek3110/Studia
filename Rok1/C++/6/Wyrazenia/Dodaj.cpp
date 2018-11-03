#include "Dodaj.h"
#include <cmath>

double dodaj::oblicz()const {
    return a->oblicz()+b->oblicz();
}

string dodaj::opis()const {

    return "Wartosc " + to_string(oblicz());

}

string dodaj::formatuj_wyrazenie() const{
    return "(" + a->formatuj_wyrazenie() + " + " + b->formatuj_wyrazenie() + ")";
}

dodaj::dodaj(wyrazenie *a, wyrazenie *b){ this->a = a; this->b = b; }
//-------------------------------------------------------
double odejmij::oblicz() const{
    return a->oblicz()-b->oblicz();
}
odejmij::odejmij(wyrazenie *a, wyrazenie *b) { this->a = a; this->b = b; }


string odejmij::formatuj_wyrazenie()const {
    return "(" + a->formatuj_wyrazenie() + " - " + b->formatuj_wyrazenie() + ")";
}
//-------------------------------------------------------
double podziel::oblicz()const {

    return a->oblicz()/b->oblicz();
}
podziel::podziel(wyrazenie *a, wyrazenie *b){
    this->a = a;
    this->b = b;
    if( b->oblicz() == 0 ) {  throw invalid_argument("Dzielenie przez 0"); }
}

string podziel::formatuj_wyrazenie() const {
    return "(" + a->formatuj_wyrazenie() + " / " + b->formatuj_wyrazenie() + ")";
}
//-------------------------------------------------------
double pomnoz::oblicz()const {
    return a->oblicz()*b->oblicz();
}

pomnoz::pomnoz(wyrazenie *a, wyrazenie *b) {
    this->a = a;
    this->b = b;
}

string pomnoz::formatuj_wyrazenie()const {
    return "(" + a->formatuj_wyrazenie() + " * " + b->formatuj_wyrazenie() + ")";
}
//-----------------------------------
double potega::oblicz() const{
    return pow(a->oblicz(),b->oblicz());
}

potega::potega(wyrazenie *a, wyrazenie *b) {
    this->a = a;
    this->b = b;
}

string potega::formatuj_wyrazenie() const{
    return a->formatuj_wyrazenie() + "^" + b->formatuj_wyrazenie();
}
//--------------------------------------
double logarytm::oblicz()const {

    return log2(b->oblicz())/log2(a->oblicz());
}

logarytm::logarytm(wyrazenie *a, wyrazenie *b){ this->a = a; this->b = b; }

string logarytm::formatuj_wyrazenie()const {
    return "log" + a->formatuj_wyrazenie() + " " +  b->formatuj_wyrazenie();
}
