package obliczenia;

/**
 * @author karol
 *Klasa reprezentuje liczbę
 */
public class Liczba extends  Wyrazenie {
    private double value;
    public Liczba(double value)
    {
        this.value=value;
    }

    @Override
    public double Oblicz() {
        return value;
    }
    public String toString()
    {
    	return ""+value+"";
    }


}
