#include <iostream>
#include <limits>


using namespace std;

int main(){

    cout<<"Smallest positive for float"<<numeric_limits<float>::denorm_min<<endl;
    cout<<"Smallest positive for double"<<numeric_limits<double>::denorm_min<<endl;

    cout<<"Biggest value for float "<<numeric_limits<float>::max()<<endl;
    cout<<"Biggest value for double "<<numeric_limits<double>::max()<<endl;

    cout<<"Diff between 1 and next value >1 for float "<<numeric_limits<float>::epsilon()<<endl;
    cout<<"Diff between 1 and next value >1 for double "<<numeric_limits<double>::epsilon()<<endl;

    return 0;
}