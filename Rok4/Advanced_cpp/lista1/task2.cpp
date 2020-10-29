#include <iostream> 
using namespace std; 
  
int main() 
{ 
    string point1 = R"(Instytut Informatyki Uniwersytetu Wrocławskiego
                    Fryderyka Joliot-Curie 15
                    50-383 Wrocław)";  

    string point2= R"(C:\ProgramFiles\)";
    string point3= R"k(++/n\n\n\n\/n??-"))k";

    cout << point1 << endl; 
    cout << point2 << endl;
    cout << point3 << endl;
    
      
    return 0; 
} 