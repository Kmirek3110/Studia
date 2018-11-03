//Karol Mirek Programowanie Obiektowe 08.03.2018 Zadanie 4
//JetBrains Ride 
//Język C#
using System;


namespace Zad4
{
    class MainClass
    {
        public static void Main (string[] args)
        {
            Console.WriteLine ("\nLista zwykla :\n");

            ListaLeniwa test = new ListaLeniwa();
            test.wypisz ();
            Console.WriteLine ("20 element listy to " +test.element (20));
            test.wypisz();
            Console.WriteLine ("23 element listy to " + test.element(23));
            test.wypisz();
            Console.WriteLine ("2 element listy to " + test.element(2));
            test.wypisz();
            Console.WriteLine ("100 element listy to " + test.element(100000));
            test.wypisz();	
            Console.WriteLine(test.element(50000));
            Console.WriteLine ("\nLista liczb  pierwszych :\n");

            Pierwsze test1 = new Pierwsze();
            test1.wypisz ();
            Console.WriteLine ("19 element listy to " + test1.element (19));
            test1.wypisz();
            Console.WriteLine ("29 element listy to " + test1.element(29));
            test1.wypisz();
            Console.WriteLine ("3 element listy to " + test1.element(3));
            test1.wypisz();
            Console.WriteLine ("101 element listy to " + test1.element(101));
            test1.wypisz();
            Console.WriteLine ("1 element listy to " + test1.element(1));
            test1.wypisz();

        }
    }
}