#include <iostream>
#include <chrono>
#include <ctime>
#include "Data.h"
#include "DataGodz.h"
#include "Wydarzenie.h"
#include <vector>
#include <algorithm>
#include <cstdlib>


using namespace std;

int main()
{
    Data b=Data(1,1,2);
    cout<<"Day "<<b.Day()<<"Month "<<b.Month()<<"Year "<<b.Year()<<endl;
    b++;
    cout<<"Day "<<b.Day()<<"Month "<<b.Month()<<"Year "<<b.Year()<<endl;
    Data c=Data(1,1,2);
    cout<<"Day "<<c.Day()<<"Month "<<c.Month()<<"Year "<<c.Year()<<endl;
    c+=1000;
    cout<<"Day "<<c.Day()<<"Month "<<c.Month()<<"Year "<<c.Year()<<endl;

    DataGodz ca=DataGodz(1,1,2012,9,44,26);
    Data ode1=Data(1,1,1);
    Data ode2=Data(1,2,2);
    cout<<ode2.days_counter();
    cout<<"Roznica"<<endl;
    cout<<ode1-ode2<<endl;
    cout<<" Day "<<ca.Day()<<" Month "<<ca.Month()<<" Year "<<ca.Year()<<
    " Hour "<<ca.Hour()<<" Minute "<<ca.Min()<<" Secund "<<ca.Sec();
    DataGodz test=DataGodz();
    cout<<endl;
    cout<<" Day "<<test.Day()<<" Month "<<test.Month()<<" Year "<<test.Year()<<
    " Hour "<<test.Hour()<<" Minute "<<test.Min()<<" Secund "<<test.Sec();
    cout<<endl;
    DataGodz test1 =DataGodz(11,11,11,13,27,15);
    cout<<"Roznica sekund : "<<endl;
    cout<<test-test1<<endl;
    DataGodz test2 =DataGodz();
    cout<<" Day "<<test2.Day()<<" Month "<<test2.Month()<<" Year "<<test2.Year()<<
    " Hour "<<test2.Hour()<<" Minute "<<test2.Min()<<" Secund "<<test2.Sec();
    cout<<endl;
    test2++;
    cout<<" Day "<<test2.Day()<<" Month "<<test2.Month()<<" Year "<<test2.Year()<<
    " Hour "<<test2.Hour()<<" Minute "<<test2.Min()<<" Secund "<<test2.Sec();
    cout<<endl;
    test2+=3123;
    cout<<" Day "<<test2.Day()<<" Month "<<test2.Month()<<" Year "<<test2.Year()<<
    " Hour "<<test2.Hour()<<" Minute "<<test2.Min()<<" Secund "<<test2.Sec();
    cout<<endl;
    DataGodz test4=DataGodz(26,03,2018,14,3,15);
    if(test2<test4)
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;
    DataGodz test5=DataGodz();
    if(test2==test5)
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;
    Data git=Data(15,10,1582);
    cout<<"Test days counter"<<endl;
    cout<<git-test<<endl;

    DataGodz uro=DataGodz(31,10,1998,1,1,1);
    DataGodz cos=DataGodz(12,12,1234,1,2,3);

    Wydarzenie urodziny=Wydarzenie(uro,"Urodziny");
    Wydarzenie cosi=Wydarzenie(cos,"Cos");

    cout<<urodziny.get_opis()<<endl;
    vector<Wydarzenie>sortowanie ;
    sortowanie.push_back(urodziny);
    sortowanie.push_back(cosi);
    sort(sortowanie.begin(),sortowanie.end());
    int j=sortowanie.size();

    for( int i = 0; i < j; i++)
    {
        cout<<sortowanie[i]<< endl;
    }
    return 0;
}
