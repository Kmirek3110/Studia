package obliczenia;

/**
 * @author karol
 *Klasa reprezentująca dodawanie
 */
public class Dodawanie extends Op2 {

    public Dodawanie(Wyrazenie a,Wyrazenie b)
    {
        this.a=a;
        this.b=b;

    }

    @Override
    public double Oblicz() {
        return a.Oblicz()+b.Oblicz();
    }

    @Override
    public String toString() {
        return "("+a+"+"+b+")";
    }
}
