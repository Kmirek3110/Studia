#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <math.h>


class Task{
   
    public:
        uint64_t counter = 1;
        virtual ~ Task();
    
};

Task::~Task(){
    std::cerr<<"Destruktor : "<<counter<<std::endl;
}

void rec_addnat(std::unique_ptr<Task[]>& array, int size, int times, int ex_counter){

    for(auto i = 0; i<size; i++){
        if(rand()%2)
            array[i].counter += ex_counter;
    }

    if(times == ex_counter)
        return;

    rec_addnat(array, size ,times, ex_counter+1);
}



int main(){

    int n, m;

    std::cout<<"Podaj liczbę liczników"<<std::endl;
    std::cin>>n;

    std::cout<<"Podaj liczbę wywołań rekurencyjnych"<<std::endl;
    std::cin>>m;


    std::unique_ptr<Task[]> tab{new Task[n]};
 
    rec_addnat(tab, n, m, 1);

    for(auto i = 0; i<n; i++){   
        std::cout<<tab[i].counter<<std::endl;
    }


    return 0;
}