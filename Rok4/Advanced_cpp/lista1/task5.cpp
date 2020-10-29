#include <iostream>


auto lucas_number(uint32_t n){

    if (n == 0)
        return 2;

    if (n == 1)
        return 1;

    return lucas_number(n-1) + lucas_number(n-2); 
}


int main(){

    uint32_t chosen_n = 37;

    std::cout<<lucas_number(chosen_n);
    std::cout<<std::endl;

    return 0;
}