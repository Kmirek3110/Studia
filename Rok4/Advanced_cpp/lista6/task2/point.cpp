#include "point.h"
#include <string>
#include <iostream>




void Point::describe(){
    using namespace std;
    cout<<"Name : "<<this->name<<endl;
    cout<<"R : "<<+this->R<<endl;
    cout<<"G : "<<+this->G<<endl;
    cout<<"B : "<<+this->B<<endl;
    cout<<"Brightness : "<< this->brightness()<<endl<<endl;

}

double Point::brightness(){
    return this->R * 0.3 + this->B * 0.59 + this->B * 0.11;
}

Point::~Point(){};