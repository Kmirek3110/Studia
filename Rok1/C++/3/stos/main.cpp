#include <iostream>
#include "stos.h"
#include <initializer_list>
using namespace std;

int main()

{   string test="pies";
    string test1="kot";
    stos a = stos(4);
    a.wloz(test);
    a.wloz(test1);


    cout<<a.rozmiar()<<endl;
    a.wypisz();
    stos b=stos();
    b.wloz(test);
    b.wypisz();
    initializer_list<string> cos={"ala","kot","malpa","dluzszeSlowo","pies"};
    stos c=stos(cos);
    cout<<c.rozmiar()<<endl;
    c.wypisz();
    stos d(c);
    cout<<endl<<endl;
    d.wypisz();
    d=d;
    cout<<endl<<endl;
    d.wypisz();

}
