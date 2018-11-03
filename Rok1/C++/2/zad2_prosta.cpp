#include <math.h>
#include<cmath>
#include <stdexcept>
#include "zad2_prosta.h"
         void prosta::unormowana(){
            double czynnik;

        if ( C < 0 ){
            czynnik = ( 1.0 / std::sqrt( A * A + B * B) );
        }
        else
        {
            czynnik = ( -1.0 / std::sqrt( A * A + B * B) );
        }
        A = A * czynnik;
        B = B * czynnik;
        C = C * czynnik;
    }

         prosta::prosta(punkt a, punkt b)
         {
         	A=(b.x-a.x);
         	B=a.x-b.x;
         	C=(b.x*a.y)-(a.x*b.y);
            unormowana();
		 }

		prosta::prosta(double A1 , double B1 ,double C1){
		  if(A == 0 && B == 0)
		  	throw invalid_argument("nie mo¿na jednoznacznie utworzyæ prostej");
          A=A1;
          B=B1;
          C=C1;
          unormowana();

		}
		prosta::prosta(prosta p , wektor w)
		{	A=p.return_a();
			B=p.return_b();
			C=p.return_c()+w.y;
			C=A*-w.x+C;
            unormowana();
		}

		double prosta::return_a(){
        	return A;
    	}
    	double prosta::return_b(){
        	return B;
    	}
    	double prosta::return_c(){
        	return C;
		}
        bool prosta::prostopadly( wektor w)
        {
            if (w.x == A && w.y == B)return true;
            return false;
        }
        bool prosta::rownolegly(wektor w)
        {
            if(w.y/w.x == -A/B ) return true;
            return false;
        }
        bool prosta::lezy(punkt p)
        {
         return (-B*p.y)==(A*p.x+C);
        }

