//Karol Mirek 
//Programowanie obiektowe , Czwartek 
// sala 108
//Lista 3 ,Zadanie 1 . Stos/Kolejka
//Funckja sprawdzająca poprawność bibliotek
// 2018.03.15
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace Zad1
{
    class Testowanie
    {
        static void Main(string[] args)
        {
            //Tworzę nowy obiekt z wartościami typu string
            Lista<string> test=new Lista<string>();
            Console.Write("Pierwsze testy : \n");
            //Sprawdzam czy obiekt zawiera elementy
            Console.Write(test.Pusta());
            //Dodaję element na początek 
            test.Początek("czy");
            Console.Write("\n ");
            test.Elementy();
            
            //Dodaje element na koniec
            test.Koniec("działa");
            Console.Write("\n ");
            //Wypisuje elementy obiektu
            test.Elementy();
            Console.Write("\n ");
            test.Początek("Sprawdzam");
            test.Elementy();
            //Ponownie sprawdzam czy obiekt zawiera elementy
            Console.Write("\n ");
            Console.Write(test.Pusta());
            Console.Write("\n ");
            //Usuwam ostatni element obiektu
            test.UsunOstatni();
            test.Elementy();
            //Uusuwam pierwszy element obiektu
            test.UsuńPierwszy();
            Console.Write("\n ");
            test.Elementy();
            Console.Write("\n ");
            //Tworzę nowy obiekt z wartościami typu int
            Console.Write("Nowa lista");
            Lista<int>liczby=new Lista<int>();
            liczby.Początek(2);
            liczby.Elementy();
            Console.Write("\n ");
            liczby.Początek(4);
            liczby.Elementy();
            
            liczby.UsuńPierwszy();
                      
            Console.Write("\n ");
            liczby.Elementy();
        }
    }
}