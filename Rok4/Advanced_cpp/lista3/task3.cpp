#include <ratio>
#include <iostream>

using namespace std;

template<int N> 
struct harmonic : public ratio_add<ratio<1,N>, harmonic<N-1>>{};

template<>
struct harmonic<1>: public ratio<1,1>{};


int main(){

    constexpr int n = 46;
    using h_n = harmonic<n>;

    cout<<"H_"<< n<<" = "<<h_n::num<<" / "<<h_n::den<<endl;


    return 0;
}