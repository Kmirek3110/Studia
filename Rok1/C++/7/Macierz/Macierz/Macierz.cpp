#include "Macierz.hpp"
#include "Friend.hpp"
using namespace Obliczenia;
Macierz::Macierz(int l) throw (zly_argument){

    if(l<1)
        throw(zly_argument());

    wiersze = kolumny = l;

    tab = new double*[l];
    for(int i=0;i<l;i++)
        tab[i]= new double[l];

    for(int i=0;i<l;i++)
        {
        for(int j=0;j<l;j++)
            if(i==j)
                tab[i][j]=1;
            else
                tab[i][j]=0;
        }
}

Macierz::Macierz(int x, int y)throw (zly_argument){

    if(x<1||y<1)
        throw(zly_argument());

    wiersze = x;
    kolumny = y;

    tab = new double*[x];

    for(int i=0;i<x;i++)
        tab[i]= new double[y];

    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++)
            tab[i][j]=0;
    }
}

Macierz::Macierz(const Macierz& m){

    wiersze = m.wiersze;
    kolumny = m.kolumny;

    tab = new double*[kolumny];
    for(int i = 0;i<wiersze;i++)
        tab[i]= new double[wiersze];

    for(int i=0;i<wiersze;i++){
        for(int j=0;j<kolumny;j++)
           tab[i][j]=m.tab[i][j];
    }
}

Macierz::Macierz(const Macierz&& m){

    wiersze=m.wiersze;
    kolumny=m.kolumny;
    tab = m.tab;
    m.tab = nullptr;
}



Macierz & Macierz::operator=(const Macierz& m){

    return *this = std::move(Macierz(m));
}

Macierz & Macierz::operator=(const Macierz&& m){

    wiersze=move(m.wiersze);
    kolumny=move(m.kolumny);
    std::swap(tab,m.tab);
}

Macierz::~Macierz(){

    tab =new double*[kolumny];

    for(int i=0;i<wiersze;i++)
        delete tab[i];

    delete tab;

}

Macierz & Macierz::operator+=(const Macierz& m) throw(rozmiary_nie_pasuja){


   if((kolumny!=m.kolumny)||(wiersze!=m.wiersze))
    {
    throw(rozmiary_nie_pasuja());
   }
   else
    {
        for(int i=0;i<wiersze;i++)
            {
            for(int j=0;j<kolumny;j++)
            tab[i][j]+=m.tab[i][j];
            }
    }
   return *this;
}

Macierz & Macierz::operator-=(const Macierz& m) throw(rozmiary_nie_pasuja){


   if((kolumny!=m.kolumny)||(wiersze!=m.wiersze))
    {
        throw(rozmiary_nie_pasuja());
    }
   else{
        for(int i=0;i<wiersze;i++)
            {
            for(int j=0;j<kolumny;j++)
                tab[i][j]-=m.tab[i][j];
            }
   }
   return *this;
}

Macierz & Macierz::operator*=(const Macierz& m) throw(rozmiary_nie_pasuja){
   if(kolumny!=m.wiersze)
    {
        throw(rozmiary_nie_pasuja());
   }
   else
    {

    Macierz C= Macierz(wiersze,m.kolumny);

    for(int i = 0; i < kolumny; i++)
        for(int j = 0; j < m.wiersze; j++)
        {
            double s = 0;
            for(int k = 0; k < wiersze; k++) s += tab[i][k] * m.tab[k][j];
                C.tab[i][j] = s;
        }
    *this=C;
    }
    return *this;
   }

Macierz & Macierz::operator*=(const double s){
    for(int i=0;i<wiersze;i++)
        {
        for(int j=0;j<kolumny;j++)
            tab[i][j]*=s;
        }
   return *this;
}

Macierz Macierz::Transpozycja()
{
    Macierz P = Macierz(kolumny,wiersze);

    for(int i=0;i<wiersze;i++){
        for(int j=0;j<kolumny;j++)
            P.tab[j][i]=tab[i][j];
    }
    int temp=kolumny;
    kolumny=wiersze;
    wiersze=temp;

    *this=P;
    return *this;
}




Macierz Obliczenia::Macierz::Zamien_wiersz(int a, int b) throw(brak_wiersza){

    double temp[wiersze];
    double temp1[wiersze];

    a-=1;
    b-=1;

    if(a<0||a>wiersze||b<0||b>wiersze) {
            throw(brak_wiersza());
    }

    for(int i=0;i<kolumny;i++)
        temp[i]=tab[a][i];

    for(int j=0;j<kolumny;j++)
        temp1[j]=tab[b][j];

    for(int i=0;i<kolumny;i++)
        tab[a][i]=temp1[i];

    for(int j=0;j<kolumny;j++)
        tab[b][j]=temp[j];

    return *this;
}

Macierz Macierz::Zamien_kolumne(int a, int b) throw(brak_kolumny){

    double temp[kolumny];
    double temp1[kolumny];

    a-=1;
    b-=1;

    if(a<0||a>kolumny||b<0||b>kolumny)
        {
            throw(brak_kolumny());
        }


    for(int i=0;i<wiersze;i++)
        temp[i]=tab[i][a];

    for(int j=0;j<wiersze;j++)
        temp1[j]=tab[j][b];

    for(int i=0;i<wiersze;i++)
        tab[i][a]=temp1[i];

    for(int j=0;j<wiersze;j++)
        tab[j][b]=temp[j];

    return *this;

}

Macierz Macierz::Pomnoz_wiersz(int a ,double s) throw(brak_wiersza){

    a-=1;

    if(a<0||a>wiersze) {
            throw(brak_wiersza());
    }

    double temp[wiersze];

    for(int i=0;i<kolumny;i++)
        temp[i]=s*tab[a][i];

    for(int i=0;i<kolumny;i++)
        tab[a][i]=temp[i];

    return *this;
}

Macierz Macierz::Pomnoz_kolumne(int a, double s) throw(brak_kolumny){

     a=a-1;

     if(a<0||a>kolumny)
        {
            throw(brak_kolumny());
        }

    double temp1[kolumny];

    for(int i=0;i<wiersze;i++)
        temp1[i]=s*tab[i][a];

    for(int i=0;i<wiersze;i++)
        tab[i][a]=temp1[i];

    return *this;
}

Macierz Macierz::Dodaj_wielokrotnosc_w(int x, int y, double s) throw(brak_wiersza){

    double temp[wiersze];

    x=x-1;
    y=y-1;
    if(x<0||x>wiersze||y<0||y>wiersze)
        {
            throw(brak_wiersza());
        }

    for(int i=0;i<kolumny;i++)
        temp[i]=s*tab[x][i];

    for(int j=0;j<kolumny;j++)
        tab[y][j]+=temp[j];

    return *this;
}

Macierz Macierz::Dodaj_wielokrotnosc_k(int x, int y, double s) throw(brak_kolumny){

    double temp[kolumny];

    x-=1;
    y-=1;

    if(x<0||y>kolumny||x>kolumny||y<0) {
            throw(brak_kolumny());
    }

    for(int i=0;i<wiersze;i++)
        temp[i]=s*tab[i][x];

    for(int j=0;j<wiersze;j++)
        tab[j][y]+=temp[j];


    return *this;
}
 namespace Obliczenia
{

ostream &operator<<(ostream &wy, const Obliczenia::Macierz &x){

     for(int i = 0; i<x.wiersze; i++) {
            for(int j = 0; j<x.kolumny; j++) {
                wy<<x.tab[i][j]<<" ";
            }
            wy<<"\n";
        }
        return wy;
}


istream &operator>>(istream &we, Obliczenia::Macierz &x){

     for(int i = 0; i<x.wiersze; i++) {
            for(int j = 0; j<x.kolumny; j++) {
                we>>x.tab[i][j];
            }
        }
        return we;
}

Macierz operator+(const Macierz& x, const Macierz& y) throw(rozmiary_nie_pasuja){

     if(x.kolumny != y.kolumny || x.wiersze != y.wiersze) throw (rozmiary_nie_pasuja());
        else {
           Macierz temp = Macierz(x.wiersze, x.kolumny);
           for(int i = 0; i<temp.wiersze; i++) {
            for(int j = 0; j<temp.kolumny; j++) {
                temp.tab[i][j] = x.tab[i][j] + y.tab[i][j];
            }
           }
           return temp;
        }
}

Macierz operator- (const Macierz &x, const Macierz &y) throw (rozmiary_nie_pasuja){

    if(x.kolumny != y.kolumny || x.wiersze != y.wiersze) throw (rozmiary_nie_pasuja());
        else {
           Macierz temp = Macierz(x.wiersze, x.kolumny);
           for(int i = 0; i<temp.wiersze; i++) {
            for(int j = 0; j<temp.kolumny; j++) {
                temp.tab[i][j] = x.tab[i][j] - y.tab[i][j];
            }
           }
           return temp;
        }
}




Macierz operator* (const Macierz &x, const double s){

      for(int i=0;i<x.wiersze;i++){
            for(int j=0;j<x.kolumny;j++)
                x.tab[i][j]*=s;
        }

    return x;
}


}
}
