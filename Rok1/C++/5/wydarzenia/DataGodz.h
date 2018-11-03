#ifndef DATAGODZ_H_INCLUDED
#define DATAGODZ_H_INCLUDED
#include <iostream>
#include <chrono>
#include <ctime>
#include "Data.h"

class DataGodz: public Data
{

    int hour;
    int minute;
    int secund;
public:
    DataGodz();
    DataGodz(const int& d, const int& m, const int& y,const int& h, const int& mi, const int& s);
    int Hour()const;
    int Min()const;
    int Sec()const;
    long long operator -(DataGodz &a);
    long long  Sekundy();
    DataGodz & operator ++(int );
    DataGodz & operator --(int );
    DataGodz & operator +=(int x);
    DataGodz & operator -=(int x);
    bool operator < (DataGodz &a);
    bool operator ==(DataGodz &a);

};


#endif // DATAGODZ_H_INCLUDED
