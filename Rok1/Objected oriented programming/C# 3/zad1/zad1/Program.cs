//Karol Mirek 
//Programowanie obiektowe, czwartek, sala 108
//Lista 4, zadanie 2, liczby pierwsze
//Funkcja testująca 
// 2018.03.21


//Język C#
//Środowisko JetBrains Rider

using System;

namespace zad2
{
    class Program//Klasa główna sprawdzająca poprawność programu
    {
        public static void Main(string[] args)//metoda główna
        {
            PrimeCollection pc = new PrimeCollection();//tworzymy nowy obiekt
            foreach (int p in pc)
                System.Console.WriteLine(p);//wypisujemy elementy
        }
    }
}