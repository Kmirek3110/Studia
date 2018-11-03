package obliczenia;

/**
 * @author karol
 *Klasa reprezentująca stałą
 */
public class Stala extends Wyrazenie {
    public final String znak;
    public double wartosc;

    public Stala(String znak , double wartosc)
    {
        this.znak=znak;
        this.wartosc=wartosc;
    }

    @Override
    public double Oblicz() {
        return wartosc;
    }

    @Override
    public String toString() {
        return znak;
    }
}
