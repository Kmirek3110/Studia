//Karol Mirek 
//Programowanie obiektowe, czwartek, sala 108
//Lista 4, zadanie 2, liczby pierwsze kolekcja
// Kod źródłowy
// 2018.03.21



//Język C#
//Środowisko JetBrains Rider

using System;
using System.Collections;

namespace zad2
{
    //Klasa liczby pierwsze
    public class Primes : IEnumerator
    {
        private int licznik;

        private bool PrimeCheck(int n) //sprawdzamy czy jest pierwsza
        {
            if (n < 2) return false;
            if (n % 2 == 0) return false;
            for (int i = 3; i < n - 1; i+=2)
            {
                if (n % i == 0) return false;
            }

            return true;
        }

        public Primes()  //Konstruktor
        {
            licznik = 1;
        }

        public bool MoveNext() //Kolejna liczba pierwsza
        {
            licznik++;
            while (!PrimeCheck(licznik)) licznik++;
            return licznik<int.MaxValue;
        }

        public void Reset() //resetuje
        {
            licznik = 1;
        }

        public object Current //Zwraca bieżącą liczbę pierwszą
        {
            get
            {
                return licznik;
            }
        }
    }


    
    class PrimeCollection : IEnumerable//Klasa tworząca kolekcję
    {
        
        public IEnumerator GetEnumerator()//moduł wyliczający
        {
            return new Primes();
        }
    }
}