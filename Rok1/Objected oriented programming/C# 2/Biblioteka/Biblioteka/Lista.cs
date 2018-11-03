//Karol Mirek 
//Programowanie obiektowe , Czwartek 
// sala 108
//Lista 3 ,Zadanie 1 . Stos/Kolejka
// Biblioteka Lista
// 2018.03.15
using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Net.Http.Headers;
using System.Text;
using System.Threading.Tasks;

namespace Zad1
{
    public class Lista<T> : Dodatkowa<T>
    {
        public Dodatkowa<T> głowa,ogon;
        public Lista()
        {
            głowa = null;
            ogon = null;
        }
        
//Wstawianie elementu na początek
        public void Początek(T x)
        {
            Dodatkowa<T> w = new Dodatkowa<T>();
            w.wartość = x;
            if (głowa == null)
            {
                głowa = w;
                ogon = w;
            }
            else
            {
                głowa.poprzednik = w;
                w.następny = głowa;
                głowa= w;
            }
        }
//Wstawianie elementu na koniec
        public void Koniec(T x)
        {
            Dodatkowa<T> nowa=new Dodatkowa<T>();
            nowa.wartość = x;
            if (głowa == null)
            {
                głowa = nowa;
                ogon = nowa;  
            }
            else
            {
                głowa.następny = nowa;
                nowa.poprzednik = ogon;
                ogon = nowa;
            }
        }
//Usuwanie pierwszego elementu
        public Dodatkowa<T> UsuńPierwszy()
        {
            if (głowa == ogon)
            {
                Dodatkowa<T> pierwsza = głowa;
                głowa = null;
                ogon = null;
                return pierwsza;
            }
            else
            {
                Dodatkowa<T> druga = głowa.następny;
                Dodatkowa<T> pierwsza = głowa;
                głowa = druga;
                druga.poprzednik = null;
                pierwsza.następny = null;
                return pierwsza;
            }
        }

//Usuwanie ostatniego elementu
        public Dodatkowa<T> UsunOstatni()
        {
            if (głowa == ogon)
            {
                Dodatkowa<T> ostatni = głowa;
                głowa = null;
                ogon = null;
                return ostatni;
            }
            else
            {

                Dodatkowa<T> przedostatni = ogon.poprzednik;
                Dodatkowa<T> ostatni = ogon;
                ogon = przedostatni;
                przedostatni.następny = null;
                ostatni.poprzednik = null;
                return ostatni;
            }
        }

//Sprawdzanie lista jest pusta
        public bool Pusta()
        {
            return (głowa == null);
        }
//Wypisywanie elementów
        public void Elementy()
        {
            Dodatkowa<T> zapas = głowa;
            if (zapas == null)
                System.Console.Write ("lista jest pusta"); 
            while (zapas != null)
            {
                System.Console.Write (" " + zapas.wartość);
                zapas = zapas.następny;
            }
        }

    }
}

