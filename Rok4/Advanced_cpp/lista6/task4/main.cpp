#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <algorithm>



int main(){
   
    
    std::ifstream ifs ("filename.txt");
    std::string s;
    getline (ifs, s, (char) ifs.eof());

    std::string::iterator end_pos = std::remove(s.begin(), s.end(), ' ');
    s.erase(end_pos, s.end());

    std::map<char, int> counters;
    int size = s.size();
    for(auto &i: s)
    {   
        // std::cout<<int(i)<<std::endl;
        if(('a' <= i) && (i <= 'z')){
            ++counters[i];
        }
        else if(('A' <= i) && (i <= 'Z')){
            ++counters[char(+i+32)];
        }
    }

    for(auto &c :counters){
        std::cout<<c.first<<" :"<<c.second<<" / "<< size<<std::endl;
    }
   
    return 0;
}