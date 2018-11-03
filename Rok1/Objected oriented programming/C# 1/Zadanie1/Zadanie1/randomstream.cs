//Losowe Liczby
using System;
using System.Runtime.CompilerServices;

namespace Zad1
{
    public class RandomStream : IntStream
    {
        Random rnd = new Random();

        public override int next()
        {
            
            return rnd.Next();
        }
    }
}