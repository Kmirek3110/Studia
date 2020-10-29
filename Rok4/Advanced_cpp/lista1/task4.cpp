#include <iostream>


enum class name: u_int16_t{
    Karol,
    Mirek,
    Karolina,
    Matylda
};

 void message_to(std::string statement, name receiver){
    
     std::string to_whom;
     switch(receiver)
     {
     case name::Karol:
        to_whom = "Karol";
        break;
     case name::Karolina:
        to_whom = "Karolina";
        break;
     case name::Mirek:
        to_whom = "Mirek";
        break;
     case name::Matylda:
        to_whom = "Matylda";
        break;
     default:
        to_whom = "Unknown";
     }

    std::cout<<statement<<" given to : "<<to_whom<<std::endl;
 }


 int main(){
     message_to("Wiadomosc do przekazania", name::Matylda);
     return 0;
 }