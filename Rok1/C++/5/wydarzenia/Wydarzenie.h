#ifndef WYDZARZENIE_H_INCLUDED
#define WYDZARZENIE_H_INCLUDED
#include "Data.h"
#include "DataGodz.h"
#include <iostream>
using namespace std;

class Wydarzenie
{
    DataGodz dg;
    string opis;
public:

    Wydarzenie(DataGodz &d ,string op);
    bool operator <(Wydarzenie &w);
    string get_opis() const {return opis;}

};

inline std::ostream& operator<<(std::ostream& out, const Wydarzenie &w) {
  out << w.get_opis();
  return out;
}

#endif // WYDZARZENIE_H_INCLUDED
