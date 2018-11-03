#include "DataGodz.h"
#include "Data.h"
#include <iostream>
#include <chrono>
#include <ctime>
#include <cmath>

DataGodz::DataGodz()
{
    time_t now;
    struct tm nowLocal;
    now=time(NULL);
    nowLocal=*localtime(&now);// chrono
    hour=nowLocal.tm_hour;
    minute=nowLocal.tm_min;
    secund=nowLocal.tm_sec;
}
 int DataGodz::Hour()const {return hour;};
 int DataGodz::Min()const {return minute;};
 int DataGodz::Sec()const {return secund;};
 DataGodz::DataGodz(const int& d, const int& m, const int& y,const int& h, const int& mi, const int& s)
 :Data(d,m,y),hour(h),minute(mi),secund(s){};
 long long DataGodz::Sekundy()
 {
     long long ile=0;
     ile=secund+minute*60+hour*60*60;
     return ile;

 };
long long  DataGodz::operator-(DataGodz &a)
{
    DataGodz b=*this;
    return abs(b.Sekundy()-a.Sekundy());

};
bool DataGodz::operator<(DataGodz &a)
{
    if(year<a.Year())
        return true;
    else if(year==a.Year())
    {
        if(month<a.Month())
            return true;
        else if(month==a.Month())
        {
            if(day<a.Day())
                return true;
            else if(day==a.Day())
            {
                if(hour<a.Hour())
                    return true;
                else if(hour==a.Hour())
                {
                    if(minute<a.Min())
                        return true;
                    else if(minute==a.Min())
                    {
                        if(secund<a.Sec())
                            return true;
                    }
                }

            }
        }

    }


    return false;
}
bool DataGodz::operator==(DataGodz &a)
{
    return(year!=a.Year()||month!=a.Month()||day!=a.Day()
       ||hour!=a.Hour()||minute!=a.Min()||secund!=a.Sec());

}
DataGodz & DataGodz::operator++ (int)
{
    int hour = this->hour;
    int minute  = this->minute;
    int sec = this->secund;
    int day = this->Day();
    int month = this->Month();
    int year = this->Year();
    Data ob(day, month, year);
    if(sec == 59)
    {
        if(minute == 59)
        {
            if(hour == 23)
            {
                ob++;
                DataGodz k1(ob.Day(),ob.Month(),ob.Year(),0, 0, 0 );
                *this = k1;
            }
            else
            {
                this->hour= hour+1;
                this->minute= 0;
                this->secund= 0;
            }
        }
        else
        {
            this->minute = minute+1;
            this->secund= 0;
        }
    }
    else this->secund  = secund +1;
    return *this;
}
DataGodz& DataGodz::operator-- (int)
{
    int godzina = this->hour;
    int minuta  = this->minute;
    int sekunda = this->secund;
    int dzien = this->Day();
    int miesiac = this->Month();
    int rok = this->Year();
    Data ob(dzien, miesiac, rok);
    if(sekunda == 0)
    {
        if(minuta == 0)
        {
            if(godzina == 0)
            {
                ob--;
                DataGodz k1(ob.Day(),ob.Month(),ob.Year(),23, 59, 59 );
                *this = k1;
            }
            else
            {
                this->hour = hour-1;
                this->minute = 59;
                this->secund = 59;
            }
        }
        else
        {
            this->minute= minute-1;
            this->secund = 59;
        }
    }
    else this->secund = secund-1;
    return *this;
}
DataGodz & DataGodz::operator+=(int x)
{
    DataGodz d1 = *this;
    for(int j=0; j<x; j++)
    {
        d1++;
    }
    *this = d1;
    return *this;
}
DataGodz  & DataGodz::operator-=(int x)
{
    DataGodz d1 = *this;
    for(int j=0; j<x; j++)
    {
        d1--;
    }
    *this = d1;
    return *this;
}
