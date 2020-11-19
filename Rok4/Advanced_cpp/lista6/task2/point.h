#ifndef POINT_H
#define POINT_H
#include <string>

class Point{
    private:
        uint8_t R;
        uint8_t G;
        uint8_t B;
        std::string name;
    public:
        Point(std::string name, uint8_t r, uint8_t g, uint8_t b):name(name),R(r),G(g),B(b){};
        std::string get_name(){return this->name;};
        void describe();
        u_int8_t get_R(){return +this->R;};
        u_int8_t get_G(){return +this->G;};
        u_int8_t get_B(){return +this->B;};
        double brightness();
        ~Point();

};




#endif