
#include "zad2_wektor.h"
#include "zad2_punkt.h"
#include<stdexcept>
#include<cmath>

#ifndef ZADANIE2_PROSTAH
#define ZADANIE2_PROSTAH



class prosta{


	public:
        void unormowana();
        double A,B,C;
		prosta(punkt a, punkt b);
		prosta(wektor w );
		prosta(double A1 , double B1 ,double C1);
		prosta(prosta p, wektor w);
		double return_a();
		double return_b();
		double return_c();
		bool prostopadly(wektor w);
		bool rownolegly(wektor w);
		bool lezy(punkt p);


};
#endif
