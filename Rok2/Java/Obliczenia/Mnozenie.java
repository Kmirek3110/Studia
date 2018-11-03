package obliczenia;

/**
 * @author karol
 *Klasa reprezentująca mnożenie
 */
public class Mnozenie extends Op2 {
    Wyrazenie a;
    Wyrazenie b;
    public Mnozenie(Wyrazenie a,Wyrazenie b)
    {
        this.a=a;
        this.b=b;

    }

    @Override
    public double Oblicz() {
         return a.Oblicz()*b.Oblicz();
    }
    public String toString() {
        return "("+a+"*"+b+")";
    }

	
	
}
