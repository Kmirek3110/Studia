package obliczenia;

/**
 * @author karol
 *Klasa reprezentująca dzielenie
 */
public class Dzielenie extends  Wyrazenie{
    Wyrazenie a;
    Wyrazenie b;
    public Dzielenie(Wyrazenie a,Wyrazenie b)
    {
        this.a=a;
        this.b=b;

    }

    @Override
    public double Oblicz() {
        return a.Oblicz()/b.Oblicz();
    }
    public String toString() {
        return "("+a+"/"+b+")";
    }
}
