#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){

    string input;
    cout<<"Podaj string do permutacji"<<endl;

    cin >> input ;

    std::sort(input.begin(), input.end());
    do {
        std::cout << input << '\n';
    } while(std::next_permutation(input.begin(), input.end()));


    return 0;
}