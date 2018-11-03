#ifndef Wyjatki_hpp
#define Wyjatki_hpp

using namespace std;

class rozmiary_nie_pasuja : public exception{

    const char* what() const noexcept {return "Rozmiary nie pasuja!\n";}

};

class zly_argument : public exception{

    const char* what() const noexcept {return "Zly argument!\n";}
};

class brak_wiersza : public zly_argument{

    const char* what() const noexcept {return "Nie ma takiego wiersza!\n";}
};

class brak_kolumny : public zly_argument{

    const char* what() const noexcept {return "Nie ma takiej kolumny!\n";}
};


#endif // Wyjatki_hpp
