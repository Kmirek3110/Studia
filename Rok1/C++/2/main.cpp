#include <cstdlib>
#include <iostream>
#include <climits>
#include <vector>
#include <stdexcept>
#include <sstream>
#include<cmath>
#include <cstdint>
#include<fstream>
#include "zad2_wektor.h"
#include "zad2_punkt.h"
#include "zad2_prosta.h"
bool rownolegle(double a,double a1 )
{
    if(a==a1)
        return true;
    return false;

}
bool prostopadle(double a,double a1)
{
    if(a*a1==-1)
        return true;
    return false;
}
void przeciecie(double a,double b,double c,double a1, double b1,double c1)
{
   double x,y;
   x=(c*b1-c1*b)/(a1*b-a*b1);
   y =  (a*c1 - a1*c) / (b1 * a - b * a1 );
   cout<<"Przeciecie prostych w punkcie : "<<x<<" , "<<y<<endl;
}
using namespace std;
int main () {

	punkt a = punkt(6,7);
    punkt b = punkt(5,8);
    //Powstanie punktow
	cout<<a.x<<" , "<<a.y<<endl<<endl;
    cout<<b.x<<" , "<<b.y<<endl<<endl;
    prosta pierwsza=prosta(a,b);
    //Prosta przechodzaca przez 2 punkty
    cout<<pierwsza.return_a()<<" "<<pierwsza.return_b()<<" "<<pierwsza.return_c()<<endl<<endl;

    //Przesuniecie prostej o wektor
    prosta test=prosta(2,-1,-3);
    wektor asd=wektor(2,1);
    test=prosta(test,asd);
    cout<<test.return_a()<<" "<<test.return_b()<<" "<<test.return_c()<<endl<<endl;
    //
    wektor w =wektor(2,1);
    prosta p = prosta(2,1,3);
    // test czy wektor jest prostopadly do prostej
    if(p.prostopadly(w))
        cout<<"Wektor Prostopadly"<<endl<<endl;
    wektor w1=wektor(1,-2);
    // test czy wektor jest rownolegly do prostej
    if(p.rownolegly(w1))
            cout<<"Wektor Rownolegly"<<endl<<endl;
    prosta test2=prosta(1,-1,2);
    punkt p2=punkt(1,3);
    // test czy punkt lezy na prostej
    if(test2.lezy(p2))
            cout<<"Punkt lezy na prostej"<<endl<<endl;
    // test czy proste sa rownolegle
    if(rownolegle(p.return_a(),test.return_a()))
        cout<<"Proste sa rownolegle"<<endl<<endl;

    prosta a1(2,2,2);
    //2x+2y=0 ->  -2y=2x+2  ->   y=-x-1
    prosta a2(-0.5,2,2);
    //-0.5x+2y+2=0 -> -2y=-0.5+2 -> y=0.25x -1

    // test czy proste sa prostopadle
    if(prostopadle(a1.return_a(),a2.return_a()))
        cout<<"Proste sa prostopadle"<<endl<<endl;
    // gdzie sie przecinaj¹
    przeciecie(a1.return_a(),a1.return_b(),a1.return_c(),a2.return_a(),a2.return_b(),a2.return_c());
    //Sprawdzam czy postaæ normalna dzia³a

    cout<<endl<<endl;
    cout<<a1.return_a()<<" . " << a1.return_b()<<" . " <<a1.return_c()<<endl;
    wektor p1=wektor(asd);
    cout<<p1.x<<"      "<<p1.y<<endl;
    return 0;
}
