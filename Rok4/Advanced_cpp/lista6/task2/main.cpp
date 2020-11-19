#include <iostream>
#include <list>
#include <string>
#include "point.h"
#include <cstdlib>
#include <algorithm>




int main(){

    std::list<Point> points;

    Point punkt0 = Point("pierwszy",rand() % 255 +1,rand() % 255 +1,rand() % 255 +1);
    Point punkt1 = Point("drugi",rand() % 255 +1,rand() % 255 +1,rand() % 255 +1);
    Point punkt2 = Point("trzeci",rand() % 255 +1,rand() % 255 +1,rand() % 255 +1);
    Point punkt3 = Point("czwa",rand() % 255 +1,rand() % 255 +1,rand() % 255 +1);
    Point punkt4 = Point("asdzx",rand() % 255 +1,rand() % 255 +1,rand() % 255 +1);
    Point punkt5 = Point("adsfadf",rand() % 255 +1,rand() % 255 +1,rand() % 255 +1);
    Point punkt6 = Point("zxc",rand() % 255 +1,rand() % 255 +1,rand() % 255 +1);
    Point punkt7 = Point("asds",rand() % 255 +1,rand() % 255 +1,rand() % 255 +1);
    Point punkt8 = Point("czs",rand() % 255 +1,rand() % 255 +1,rand() % 255 +1);
    Point punkt9 = Point("asdq",rand() % 255 +1,rand() % 255 +1,rand() % 255 +1);
    Point punkt10 = Point("zxcasd",rand() % 255 +1,rand() % 255 +1,rand() % 255 +1);
    Point punkt11 = Point("asd",rand() % 255 +1,rand() % 255 +1,rand() % 255 +1);
    Point punkt12 = Point("fdsf",rand() % 255 +1,rand() % 255 +1,rand() % 255 +1);
    Point punkt13 = Point("pierwszy",rand() % 255 +1,rand() % 255 +1,rand() % 255 +1);
    Point punkt14 = Point("fasf",rand() % 255 +1,rand() % 255 +1,rand() % 255 +1);
    Point punkt15 = Point("asdas",rand() % 255 +1,rand() % 255 +1,rand() % 255 +1);
    Point punkt16 = Point("pierfdfswszy",rand() % 255 +1,rand() % 255 +1,rand() % 255 +1);
    
    points.push_back(punkt0);
    points.push_back(punkt1);
    points.push_back(punkt2);
    points.push_back(punkt3);
    points.push_back(punkt4);
    points.push_back(punkt5);
    points.push_back(punkt6);
    points.push_back(punkt7);
    points.push_back(punkt8);
    points.push_back(punkt9);
    points.push_back(punkt10);
    points.push_back(punkt11);
    points.push_back(punkt12);
    points.push_back(punkt13);
    points.push_back(punkt14);
    points.push_back(punkt15);
    points.push_back(punkt16);


    std::cout<<points.size()<<std::endl;

    auto new_end = std::remove_if(points.begin(),points.end(),
            [](Point &a){ return a.get_name().length() > 5;});
    
    points.erase(new_end, points.end());
    

    std::cout<<points.size()<<std::endl;

    for(auto &point : points){
        point.describe();
    }

    auto first_quarter = std::count_if(points.begin(), points.end(),
        [](Point& a){if(a.get_R() > 127 && a.get_G() > 127) return 1; else return 0;});
    auto second_quarter = std::count_if(points.begin(), points.end(),
        [](Point& a){if(a.get_R() < 127 && a.get_G() > 127) return 1; else return 0;});
    auto third_quarter = std::count_if(points.begin(), points.end(),
        [](Point& a){if(a.get_R() < 127 && a.get_G() < 127) return 1; else return 0;});
    auto fourth_quarter = std::count_if(points.begin(), points.end(),
        [](Point& a){if(a.get_R() > 127 && a.get_G() < 127) return 1; else return 0;});

    std::cout<<first_quarter<<std::endl;
    std::cout<<second_quarter<<std::endl;
    std::cout<<third_quarter<<std::endl;
    std::cout<<fourth_quarter<<std::endl;

    points.sort([](Point &a, Point&b){
             return a.get_R() * 0.3 + a.get_B() * 0.59 + a.get_B() * 0.11 >
             b.get_R() * 0.3 + b.get_B() * 0.59 + b.get_B() * 0.11;
        });

    for(auto &point : points){
        point.describe();
    }

    std::list<Point> dark;

    for(auto &point : points){
        if( point.brightness() > 64) dark.push_back(point);
    }

     for(auto &point : dark){
        point.describe();
    }

    return 0;
};