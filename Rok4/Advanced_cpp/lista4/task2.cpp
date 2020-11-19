#include<iostream>
#include<vector>
#include<functional>
using namespace std;

template<typename F,typename G> class compose_f_gxy_t {
  typedef typename F::result_type result_type;
  typedef typename G::first_argument_type  first_argument_type;
  typedef typename G::second_argument_type  second_argument_type;

  F _f;
  G _g;

public:
  compose_f_gxy_t(F f,G g):_f(f),_g(g) {};

  result_type operator()(first_argument_type x,
                         second_argument_type y) {
    return _f(_g(x,y));
  }

};
template<typename F,typename G> 
compose_f_gxy_t<F,G>
compose_f_gxy(F f,G g) {return  compose_f_gxy_t<F,G>(f,g);};

int main() {
    std::cout<<compose_f_gxy(
                         __gnu_cxx::compose1(std::ptr_fun(exp),
                                       std::negate<double>()),
                         f)(1.0,1.0)<<"";
}