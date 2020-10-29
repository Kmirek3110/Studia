#include <iostream>
#include <limits>



int main(){
    constexpr long long int  max = std::numeric_limits<long long int>::max();
    constexpr long long int  min = std::numeric_limits<long long int>::min();

    std::cout<<"Max long long value "<<max<<std::endl;
    std::cout<<"Number of base 2 digits "<<std::numeric_limits<long long int>::digits<<std::endl;
    std::cout<<"Number of base10 digits "<<std::numeric_limits<long long int>::digits10<<std::endl;
    std::cout<<"Min long long value "<<min<<std::endl;

    return 0;
}