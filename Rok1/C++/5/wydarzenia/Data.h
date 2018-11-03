#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED
#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;
class Data{
    static const int dniwmiesiacach[2][13];
    static const int dniodpoczroku[2][13];
    protected :
        int day;
        int month;
        int year;
        bool przestepny();
    public:
        Data();
        Data(const int& d, const int& m, const int& y);
        Data(const Data &a);
        int Year() const ;
        int Month()const ;
        int Day() const ;
        bool poprawna()  ;
        long iledni(Data &a);
        Data & operator  ++();
        Data & operator  ++(int );
        Data & operator  --();
        Data  & operator  --(int );
        Data & operator  +=(int x);
        Data  & operator  -=(int x);
        int operator -(Data &a);
        int days_counter();




};



#endif // DATA_H_INCLUDED
