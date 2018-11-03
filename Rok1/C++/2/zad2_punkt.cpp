#include <cstdlib>

#include "zad2_punkt.h"
#include "zad2_wektor.h"


	punkt::punkt():x(0),y(0){}
	punkt::punkt(const double dx ,const double dy):x(dx),y(dy){}
	punkt::punkt(const double x1,const double y1, wektor z ):x(x1+z.x),y(y1+z.y){}




