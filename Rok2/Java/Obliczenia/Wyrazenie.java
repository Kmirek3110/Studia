package obliczenia;

/**
 * @author karol
 *Klasa reprezentująca Wyrazenie
 */
public abstract class Wyrazenie implements Obliczalny {
    // ...
    /** metoda sumująca wyrażenia */
    public static double suma (Wyrazenie... wyr) {
        double sum=0;
        for(Wyrazenie exp:wyr)
        {
            sum+=exp.Oblicz();
        }
        return sum;
    }
/*
 * Iloczyn liczb zwraca double
 */
    public static double iloczyn(Wyrazenie... wyr) {
        double sum = 1;
        for (Wyrazenie exp:wyr)
        {
            sum *= exp.Oblicz();
        }
        return sum;
    }
    boolean equals (Wyrazenie a)
    {
        return this.Oblicz()==a.Oblicz();
    }
    

}
