#include <cstdlib>
#include <iostream>
#include "stos.h"
#include <initializer_list>

using namespace std;

stos::stos():pojemnosc(1),ile(0),stk{new string[pojemnosc]}{}

stos::stos(const int pojemnosc1):pojemnosc(pojemnosc1),ile(0),stk{new string[pojemnosc]}
{
}
stos::stos(initializer_list<string>lista): pojemnosc(lista.size()),ile(0),stk(new string [pojemnosc]){

    for(auto it=lista.begin();it!=lista.end();it++)
    {
        stk[ile]=*it;
        ile++;
    }
}
stos::stos(const stos & a):pojemnosc(a.pojemnosc),ile(0),stk(new string [a.pojemnosc]){
    for(int i=0;i<a.ile;i++)
    {
        wloz(a.stk[i]);
    }
}
stos::stos(stos&& x) :  pojemnosc(x.pojemnosc), ile(x.ile),stk(x.stk){
  x.stk = nullptr;
}

stos & stos::operator=(const stos& x){
return *this = stos(x);
}

stos & stos::operator=(stos&& x){
    if (this == &x) return *this;
    pojemnosc = x.pojemnosc;
    ile = x.ile;
    stk = move(x.stk);
    x.stk=nullptr;
    return *this;
}
 void stos::wloz(const string &cos)
 {
 if(ile<pojemnosc)
    {
    stk[ile]=cos;
    ile++;
    }
 }
const int stos::rozmiar() {return pojemnosc;}
const string stos::sprawdz  (){
    if(ile==0)throw  std::invalid_argument("Nie ma nic w tablicy");
    return stk[ile-1];}
void stos::sciagnij(){
    if(ile==0)throw std::invalid_argument("Nie ma nic w tablicy");
    ile-=1;}
void stos::wypisz(){

for(int i=0;i<pojemnosc;i++)
    cout<<stk[i]<<endl;
}
stos::~stos() {delete[] stk;}
