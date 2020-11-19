#ifndef PERSON_H
#define PERSON_H
#include<string>
#include <iostream>

class Person{
    private:   
        std::string name;
        std::string surname;
        int height;
        int age;
        float weight;
    public:
        Person(std::string name, std::string surname, int age, int height, float weight)
            :name(name),surname(surname),age(age),height(height),weight(weight){};

        Person(const Person&  p );

        bool operator==(const Person & p){
            if(this->name != p.name) return false;
            if(this->surname != p.surname) return false;
            if(this->height != p.height) return false;
            if(this->weight != p.weight) return false;
            if(this->age  != p.age) return false;
            return true;
        };
        
        // void SportTrip()
        float BMI();
        void person_info();
        float get_weight();
        void set_weight(float &new_weight);
        int get_height();
        int get_age(){return this->age;};
        std::string get_name();
        std::string get_surname();

};




#endif