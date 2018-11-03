#include "Stala.h"
#include "Wyrazenie.h"
#include <string>
using namespace std;

double stala::oblicz()const {
    return value;
}

string stala::opis() const  {

    string s =to_string(value);
    return s;
}

stala::stala(int value) : value(value) { }


int stala::getValue() {
    return value;
}

std::string stala::formatuj_wyrazenie() const {
    return std::to_string(value);
}
