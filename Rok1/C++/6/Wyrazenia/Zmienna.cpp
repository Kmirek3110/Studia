#include "Zmienna.h"
    double  zmienna:: oblicz()const{
        for(unsigned int i = 0; i < myVector.size(); i++){
            if(myVector[i].first == value){
                return myVector[i].second;
            }
        }
        throw invalid_argument("Ju¿ w bazie istnieje taka zmienna");
    } ;

        string zmienna::opis() const{ return value;};

        void zmienna:: newPair(string k, double s){


        for(unsigned int i = 0; i < myVector.size(); i++){
            if(myVector[i].first == k){
                throw invalid_argument("Ju¿ w bazie istnieje taka zmienna");
            }
        }

        myVector.emplace_back(make_pair(k, s));

    };

    void zmienna::setValue(double newValue){

    for(unsigned int i = 0; i < myVector.size(); i++){
            if(myVector[i].first == value){
                myVector[i].second = newValue;
            }
        }
      // throw
    };



    zmienna::zmienna(const string &value):value(value)
    {

        newPair("x",10.00);
        newPair("y",2.00);
        newPair("z",3.00);

        for(unsigned int i = 0; i < myVector.size(); i++){// for (auto x: myVector)
            if(myVector[i].first == value){
                return;
            }
        }

            throw invalid_argument("Nie ma takiej zmiennej w bazie");
    };

    string zmienna::formatuj_wyrazenie()const {
            return value;
        };
