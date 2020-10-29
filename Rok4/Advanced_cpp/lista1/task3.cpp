#include <iostream>
#include <set>
#include <algorithm>


using alias_string = std::set<std::string>;


int main(){

    alias_string stringi {"Zadanie", "Numer", "Trzy"};

    
    for(auto elem: stringi){
        std::cout<<elem<<std::endl;
    }


    return 0;
}