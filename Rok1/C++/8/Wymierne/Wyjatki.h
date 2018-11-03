#ifndef WYJATKI_H_INCLUDED
#define WYJATKI_H_INCLUDED

using namespace std;


class dzielenie_przez0 : public exception{

    const char* what() const noexcept {return "Dzielenie przez 0!\n";}

};
class przekroczenie_zakresu : public dzielenie_przez0{

    const char* what() const noexcept {return "przekroczenie zakresu!\n";}

};
#endif // WYJATKI_H_INCLUDED
