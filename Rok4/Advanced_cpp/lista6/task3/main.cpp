#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>




int main(){
    std::vector<int> test{1,1,3,5,8,9,5,8,8,5};

    std::map<int, int> counters;
    for(auto i: test)
    {
        ++counters[i];
    }
    int biggest_key = 0 ;
    std::vector<std::pair<int,int>> most_frequent;
    for(auto &i: counters)
    {
        if(i.second > biggest_key){
            most_frequent.clear();
            most_frequent.push_back(std::make_pair(i.first, i.second));
            biggest_key = i.second;
        }
        else if (i.second == biggest_key) most_frequent.push_back(std::make_pair(i.first, i.second));
        
    }
    for(auto &i : most_frequent){
        std::cout<<i.first<<" : "<<i.second<<std::endl;
    }


    return 0;
}