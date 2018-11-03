#include "Data.h"
#include "DataGodz.h"
#include <iostream>
#include "Wydarzenie.h"


Wydarzenie::Wydarzenie(DataGodz& d, string op):dg(d),opis(op)
{};

bool Wydarzenie::operator <(Wydarzenie &w)
{
    Wydarzenie ob =*this;
    DataGodz(ob.dg.Day(),ob.dg.Month(),ob.dg.Year(),ob.dg.Hour(),ob.dg.Min(),ob.dg.Sec());
    return(dg<w.dg);

}

