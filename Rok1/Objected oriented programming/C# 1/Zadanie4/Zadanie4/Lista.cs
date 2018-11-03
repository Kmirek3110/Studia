//Lista Leniwa
using System;
using System.Collections.Generic;
using System.Drawing;

namespace Zad4
{
    class ListaLeniwa
    {
        protected int rozmiar;
        protected List<int> L;
        private Random r;
       
        protected virtual int kolejnaLiczba(int n)
        {
            return r.Next ();
        }

        public int size()
        {
            return rozmiar;
        }

        public int element(int n)
        {
            if (n < rozmiar) return L [n];
            else
            {
                rozmiar = n;

                if (L.Count == 0) L.Add (0);

                for(int i = L.Count-1; i < n; i++)
                {
                    L.Add(kolejnaLiczba(L[i]));
                }

                return L [n];
            }
        }

        public void wypisz()
        {
            System.Console.WriteLine("Rozmiar listy to " + rozmiar);
        }

        public ListaLeniwa()
        {
            rozmiar = 0;
            L = new List<int>();
            r = new Random ();
        }
    }
}