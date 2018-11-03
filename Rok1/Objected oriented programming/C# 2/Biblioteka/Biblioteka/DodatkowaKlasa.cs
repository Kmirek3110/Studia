//Karol Mirek 
//Programowanie obiektowe , Czwartek 
// sala 108
//Lista 3 , Zadanie 1 . Stos/Kolejka
//Biblioteka DodatkowaKlasa
// 2018.03.15
namespace Zad1
{
    public class Dodatkowa<T>
    {
        public T wartość;
        public Dodatkowa<T> następny;
        public Dodatkowa<T> poprzednik;
        
        public Dodatkowa()
        {
            następny = null;
            wartość = default(T);
            poprzednik = null;
        }
    }
}