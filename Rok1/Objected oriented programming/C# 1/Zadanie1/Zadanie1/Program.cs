//Karol Mirek Programowanie Obiektowe 08.03.2018 Zadanie 1

using System;
namespace Zad1
{    //Klasa główna 
    class MainClass
    {
        public static void Main(string[] args)
        {
            IntStream I = new IntStream();
            
            System.Console.WriteLine("Kolejne liczby naturalne \n");

            for (int i = 0; i < 10; i++)
            {
                System.Console.WriteLine(I.next());
                if(i%5==0)I.reset();
            }
            System.Console.WriteLine ("\nKolejne Liczby Pierwsze\n");

            PrimeStream J = new PrimeStream();

            for (int i = 0; i < 10; i++)
            {
                System.Console.WriteLine (J.next ());
            }
            System.Console.WriteLine ("\nLosowe Slowa o ilosci znakow kolejnych liczb pierwszych \n");

            RandomWordStream K = new RandomWordStream();

            for (int i = 0; i < 10; i++)
            {
                System.Console.WriteLine (K.next ());
                 
            }

            System.Console.WriteLine ("\nLosowe Liczby \n");

            RandomStream L = new RandomStream();

            for (int i = 0; i < 10; i++)
            {
                System.Console.WriteLine (L.next ());
                
            }
            
        }
    }
}
