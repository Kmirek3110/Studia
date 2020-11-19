#include "person.h"
#include <iostream>






Person::Person(const Person&  p ){
    this->name = p.name;
    this->surname = p.surname;
    this->height = p.height;
    this->weight = p.weight; 
    this->age = p.age;
};

float Person::BMI(){
    return (double)this->weight / (double)(this->height*this->height);
};



void Person::person_info(){
    std::cout<<"Name : "<<this->name<<std::endl;
    std::cout<<"Surname : "<<this->surname<<std::endl;
    std::cout<<"Age : "<<this->age<<std::endl;
    std::cout<<"Height : "<<this->height<<std::endl;
    std::cout<<"Weight : "<<this->weight<<std::endl;
};

float Person::get_weight(){
    return this->weight;
}

void Person::set_weight(float &new_weight){
    this->weight = new_weight;
}

int Person::get_height(){
    return this->height;
}

std::string Person::get_name(){
    return this->name;
}


std::string Person::get_surname(){
    return this->surname;
}