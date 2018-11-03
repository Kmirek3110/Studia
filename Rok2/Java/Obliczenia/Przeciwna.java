package obliczenia;

/**
 * @author karol
 *Klasa reprezentująca liczbę przeciwną
 */
public class Przeciwna extends Op1 {

	Wyrazenie a;
	public Przeciwna(Wyrazenie a)
	{
		this.a=a;
	}

	@Override
	public double Oblicz() {
		return -a.Oblicz();
	}
	public String toString() {
		return "-("+a.Oblicz()+")";
	}

}
