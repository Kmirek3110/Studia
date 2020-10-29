#include <iostream>
#include <string>
 

int main(){
    
    std::cout<<"ENTER DATE WITH DD.MM.RRRR FORMAT"<<std::endl;

    std::string date;
    std::cin >> date;

    std::cout<<date[0]<<date[1]<<" ";


    switch(auto i = stoi(std::string(1,date[3]) + std::string(1,date[4])); i){
        case 1 : std::cout<<"stycznia"; break;
        case 2 : std::cout<<"lutego"; break;
        case 3 : std::cout<<"marca"; break;
        case 4 : std::cout<<"kwietnia"; break;
        case 5 : std::cout<<"maja"; break;
        case 6 : std::cout<<"czerwca"; break;
        case 7 : std::cout<<"lipca"; break;
        case 8 : std::cout<<"sierpnia"; break;
        case 9 : std::cout<<"wrzesnia"; break;
        case 10 : std::cout<<"pazdziernika"; break;
        case 11 : std::cout<<"listopada"; break;
        case 12 : std::cout<<"grudnia"; break;
    }

    std::cout<<" "<<date[6]<<date[7]<<date[8]<<date[9]<<std::endl;

    return 0;
}