package obliczenia;

/**
 * @author karol
 *Klasa reprezentująca odejmowanie
 */
public class Odejmowanie extends Op2 {
    Wyrazenie a;
    Wyrazenie b;
    public Odejmowanie(Wyrazenie a,Wyrazenie b)
    {
        this.a=a;
        this.b=b;

    }

    @Override
    public double Oblicz() {
        return a.Oblicz()-b.Oblicz();
    }
    public String toString() {
        return "("+a+"-"+b+")";
    }

	
}
