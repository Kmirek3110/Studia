#include "Data.h"
#include <iostream>
#include <chrono>
#include <ctime>
#include<cmath>

using namespace std;
 Data::Data(){
    time_t now;
    struct tm nowLocal;
    now=time(NULL);
    nowLocal=*localtime(&now);
    year=nowLocal.tm_year+1900;
    month=nowLocal.tm_mon+1;
    day=nowLocal.tm_mday;
 };
 Data::Data(const int& d,const int& m,const  int& y):day(d),month(m),year(y){};
 int Data::Year()const {return year;};
 int Data::Month()const {return month;};
 int Data::Day()const {return day;};

const int Data::dniodpoczroku[2][13] = {
    {0,31,59,90,120,151,181,212,243,273,304,334,365}, // lata zwyk³e
    {0,31,60,91,121,152,182,213,244,274,305,335,366} // lata przestêpne
};
const int Data::dniwmiesiacach [2][13] = {
    {0,31,28,31,30,31,30,31,31,30,31,30,31}, // lata zwyk³e
    {0,31,29,31,30,31,30,31,31,30,31,30,31} // lata przestêpne
};
Data::Data(const Data& a):day(a.Day()),month(a.Month()),year(a.Year()){};

bool Data::poprawna()
{
    if(day<1)
        return false;
    if(day>dniwmiesiacach[przestepny()][month])
        return false;
    return true;
}
bool Data::przestepny()
{
    if (year% 4 == 0 && year% 100 != 0)
    {
        return 1;
    }
    else if(year% 400 == 0)
    {
        return 1;
    }
    return 0;

};

Data & Data::operator++(int){
    Data b=*this;
    if(Data(b.Day()+1,b.Month(),b.Year()).poprawna())
    {
        *this=Data(b.Day()+1,b.Month(),b.Year());
        return b;
    }
    else if(Data(1,b.Month()+1,b.Year()).poprawna())
    {
        *this=Data(1,b.Month()+1,b.Year());
        return b;
    }
    else
    {
        *this=Data(1,1,b.Year()+1);
        return b;
    }
}

Data  & Data::operator ++(){
    Data b=*this;
    if(Data(b.Day()+1,b.Month(),b.Year()).poprawna())
    {
        *this=Data(b.Day()+1,b.Month(),b.Year());
        return *this;
    }
    else if(Data(1,b.Month()+1,b.Year()).poprawna())
    {
        *this=Data(1,b.Month()+1,b.Year());
        return *this;
    }
    else
    {
        *this=Data(1,1,b.Year()+1);
        return *this;
    }
}

Data  & Data::operator--(int){
    Data b=*this;
    if(Data(b.Day()-1,b.Month(),b.Year()).poprawna())
    {
        *this=Data(b.Day()-1,b.Month(),b.Year());
        return b;
    }
    else if(Data(31,b.Month()-1,b.Year()).poprawna())
    {
        *this=Data(31,b.Month()-1,b.Year());
        return b;
    }
    else if(Data(30,b.Month()-1,b.Year()).poprawna())
    {
        *this=Data(30,b.Month()-1,b.Year());
        return b;

    }
    else if(Data(29,b.Month()-1,b.Year()).poprawna())
    {
        *this=Data(29,b.Month()-1,b.Year());
        return b;

    }
    else if(Data(28,b.Month()-1,b.Year()).poprawna())
    {
        *this=Data(28,b.Month()-1,b.Year());
        return b;

    }
    else
    {
        *this=Data(31,12,b.Year()-1);
        return b;

    }
}
int   Data::operator -(Data &a)
{
    Data c=*this;
    return abs(c.days_counter()-a.days_counter());
}
Data &  Data::operator   --(){
    Data b=*this;
    if(Data(b.Day()-1,b.Month(),b.Year()).poprawna())
    {
        *this=Data(b.Day()-1,b.Month(),b.Year());
        return *this;
    }
    else if(Data(31,b.Month()-1,b.Year()).poprawna())
    {
        *this=Data(31,b.Month()-1,b.Year());
        return *this;
    }
    else if(Data(30,b.Month()-1,b.Year()).poprawna())
    {
        *this=Data(30,b.Month()-1,b.Year());
        return *this;

    }
    else if(Data(29,b.Month()-1,b.Year()).poprawna())
    {
        *this=Data(29,b.Month()-1,b.Year());
        return *this;

    }
    else if(Data(28,b.Month()-1,b.Year()).poprawna())
    {
        *this=Data(28,b.Month()-1,b.Year());
        return *this;

    }
    else
    {
        *this=Data(31,12,b.Year()-1);
        return *this;

    }
}
int Data::days_counter()
{
    year=year-1;
    int przestepne=year/4-year/100+year/400+1;
    int nieprzestepne=year-przestepne+1;
    int wynik=przestepne*dniodpoczroku[1][12]+nieprzestepne*dniodpoczroku[0][12];
    year=year+1;
    if(przestepny())
        wynik=wynik+dniodpoczroku[1][month-1];
    else
        wynik=wynik+dniodpoczroku[0][month-1];
    wynik+=day;

    return wynik;
}
Data & Data::operator +=(int x)
{
    Data d=*this;
    for(int i=0;i<x;i++)
    {
       d++;
    }
    *this=d;
    return *this;
}
Data & Data::operator -=(int x)
{
    Data d=*this;
    for(int i=0;i<x;i++)
    {
       d--;
    }
    *this=d;
    return *this;
}


