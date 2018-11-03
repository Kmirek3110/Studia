#include <iostream>
#include <climits>
#include "Wymierna.h"
using namespace std;
using namespace Obliczenia;

int main() {


    Wymierna a = Wymierna(1,4);
    Wymierna b = Wymierna(2,4);
    cout<<a.getLicznik()<<"/"<<a.getMianownik()<<endl;
    cout<<b.getLicznik()<<"/"<<b.getMianownik()<<endl;
    Wymierna c = b+a;
    cout<<c.getLicznik()<<"/"<<c.getMianownik()<<endl;
    cout<<c<<endl;




    return 0;
}
