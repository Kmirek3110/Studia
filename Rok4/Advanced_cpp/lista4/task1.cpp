#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <string>
#include <iterator>
#include <algorithm>
#include <functional>



template <typename T>
std::function<void(T)> compare(const T& a, const T& b)
{
    return [&](const T& c) {
        if (b > c && c > a)
            std::cout << c <<" ";
    };
}

template <typename Ts>
auto find_minmax(const Ts& elements)
{
    auto min = elements.begin();
    auto max = elements.begin();
    auto iter = elements.begin();

    std::for_each(elements.begin(), elements.end(), [&](auto& elem) {
        if (elem < *min)
            min = iter;
        else if (*max < elem)
            max = iter;
        iter++;
    });

    return std::pair{min, max};
}

template <typename Ts>
auto sum_elements(Ts elements, typename Ts::value_type neutral_value)
{
    std::for_each(elements.begin(), elements.end(), [&](auto& value) { neutral_value += value; });
    return neutral_value;
}

int main(){
    // ZADANIE 1
    std::vector<double> vec = {1.0,2.5,2.3,2.2,4.1,3.7,4.2,-1.0};
    std::list<std::string> list = {"B", "G","Z","C","G","C","X"};
    std::set<int> set = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,18};

    double a = 1.0;
    double b = 7.0;
    std::for_each(vec.begin(), vec.end(),compare<double>(2.0,3.0) );

    std::cout<<std::endl;

    std::for_each(list.begin(),list.end(),compare<std::string>("A","F"));

    std::cout<<std::endl;

    std::for_each(set.begin(),set.end(),compare<int>(2,5));

     std::cout<<std::endl;

    // ZADANIE 2

    std::cout<<"podpunkty B"<<std::endl;
    constexpr int k = 3, p = 4;

    std::for_each(vec.begin() + p, vec.end(), [](double val) {
        static int k_counter = 0;
        if (k_counter++ % k == 0)
            std::cout << val << " ";
    });
    std::cout << std::endl;

    auto list_iterator = list.begin();
    std::advance(list_iterator, p);
    std::for_each(list_iterator, list.end(), [](std::string val) {
        static int k_counter = 0;
        if (k_counter++ % k == 0)
            std::cout << val << " ";
    });
    std::cout << std::endl;

    auto set_iterator = set.begin();
    std::advance(set_iterator, p);
    std::for_each(set_iterator, set.end(), [](int val) {
        static int k_counter = 0;
        if (k_counter++ % k == 0)
            std::cout << val << " ";
    });
    std::cout << std::endl;

    // ZADANIE 3

    auto sum_double = sum_elements<std::vector<double>>(vec,0.0);

    auto sum_int = sum_elements<std::set<int>>(set,0);
    
    std::cout<<"podpunkt C"<<std::endl;
    
    std::cout<<"ŚREDNIA ARYTMETYCZNA WYnosi doubli : "  << sum_double / vec.size()<<std::endl;

    std::cout<<"ŚREDNIA ARYTMETYCZNA WYnosi intow : " << sum_int / set.size()<<std::endl;

    // ZADANIE 4
    
    auto [vector_min, vector_max]  = find_minmax<std::vector<double>>(vec);
    
    std::cout<<*vector_min<< " = minimalna vectorowa"<<std::endl;
    std::cout<<*vector_max<< " = maksymalna vectorowa"<<std::endl;

    auto [set_min, set_max] = find_minmax<std::set<int>>(set);

    std::cout<<*set_min<< " = minimalna setowa"<<std::endl;
    std::cout<<*set_max<< " = maksymalna setowa"<<std::endl;

    auto [list_min, list_max] = find_minmax<std::list<std::string>>(list);

    std::cout<<*list_min<< " = minimalna listowa"<<std::endl;
    std::cout<<*list_max<< " = maksymalna listowa"<<std::endl;

    auto sum_list = sum_elements<std::list<std::string>>(list,"");
    std::cout<<sum_list<<std::endl;
    

    return 0;
}