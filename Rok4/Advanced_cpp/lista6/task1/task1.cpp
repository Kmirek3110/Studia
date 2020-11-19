#include <string>
#include <deque>
#include <iostream>
#include "person.h"
#include <algorithm>
#include <vector>


void Sport_Trip(std::deque<Person> &osoby){
    std::for_each(osoby.begin(),osoby.end(),
            [](Person &a){
                float curr_weight = a.get_weight();
                curr_weight *= 0.9;
                a.set_weight(curr_weight);
                });
};

Person median_height(std::deque<Person> osoby){
    size_t size = osoby.size();

    sort(osoby.begin(),osoby.end(),[](Person &a, Person &b){
        return a.get_height() > b.get_height();
    });

    return osoby[size/2];

}


int main(){

    std::deque<Person> osoby;

    Person osoba = Person("karol","mirek",12,189,200);
    Person osoba1 = Person("agata","dfgxcz",14,170,59);
    Person osoba2 = Person("maciek","sdfsdf",17,178,83);
    Person osoba3 = Person("agnieszka","asdas",222,180,62);
    Person osoba4 = Person("julka","asdasd",123,155,43);
    Person osoba5 = Person("kinga","asdasd",21,167,55);
    Person osoba6 = Person("pawel","qweqwe",28,176,212);
    Person osoba7 = Person("marcin","fsgsdf",32,186,123);
    Person osoba8 = Person("tomek","asdsad",30,181,69);
    Person osoba9 = Person("bogdan","zxczx",26,170,90);
    Person osoba10 = Person("ania","xsad",269,160,40);

    osoby.push_back(osoba);
    osoby.push_back(osoba1);
    osoby.push_back(osoba2);
    osoby.push_back(osoba3);
    osoby.push_back(osoba4);
    osoby.push_back(osoba5);
    osoby.push_back(osoba6);
    osoby.push_back(osoba7);
    osoby.push_back(osoba8);
    osoby.push_back(osoba9);
    osoby.push_back(osoba10);

    std::sort(osoby.begin(), osoby.end(),[](Person &a, Person &b) {return a.BMI() > b.BMI(); });

    std::for_each(osoby.begin(),osoby.end(),
            [](Person &a){a.person_info();std::cout<<std::endl;});

    Sport_Trip(osoby);


    std::for_each(osoby.begin(),osoby.end(),
            [](Person &a){a.person_info();std::cout<<std::endl;});



    std::deque<Person>::iterator bound;

    bound = std::partition(osoby.begin(),osoby.end(),
                [](Person &a){
                    return a.get_weight() > 100;
                }
            );

    std::cout<<"MORE THAN 100KG"<<std::endl;
    std::cout<<std::endl;

    int counter = 0;
    for(std::deque<Person>::iterator it=osoby.begin(); it != bound; ++it){
        osoby[counter].person_info();
        counter ++;
    };
    std::cout<<std::endl;
    std::cout<<"LESS THAN 100KG"<<std::endl;

    for(std::deque<Person>::iterator it=bound; it != osoby.end(); ++it){
        osoby[counter].person_info();
        std::cout<<std::endl;
        counter ++;
    };
    
    std::for_each(osoby.begin(),osoby.end(),
            [](Person &a){a.person_info();std::cout<<std::endl;});

    Person median = Person(median_height(osoby));

    std::cout<<"median person"<<std::endl;
    median.person_info();

    for(int i = 0; i< osoby.size();i++){
        if(osoby[i] == median){
            osoby.erase(osoby.begin()+i);
            break;
        }
    }     

    osoby.emplace(osoby.begin()+ osoby.size()/2,median);
    

    std::for_each(osoby.begin(),osoby.end(),
            [](Person &a){a.person_info();std::cout<<std::endl;});


    std::cout<<"RANDOM SHUFFLE --------------------------"<<std::endl;


    std::random_shuffle(osoby.begin(),osoby.begin()+osoby.size()/2);
    std::random_shuffle(osoby.begin()+(osoby.size()/2), osoby.end());


    std::for_each(osoby.begin(),osoby.end(),
            [](Person &a){a.person_info();std::cout<<std::endl;});


    auto result = std::minmax_element(osoby.begin(),osoby.end(),
            [](Person &a,Person &b){
                return a.get_age() > b.get_age();
            });
    osoby[result.first - osoby.begin()].person_info();
    osoby[result.second - osoby.begin()].person_info();
    


    return 0;
}