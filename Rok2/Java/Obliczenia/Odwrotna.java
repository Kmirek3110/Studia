package obliczenia;

/**
 * @author karol
 *Klasa reprezentująca liczbę odwrotną
 */
public class Odwrotna extends Op1 {

	Wyrazenie a;
	public Odwrotna(Wyrazenie a)
	{
		this.a=a;
	}

	@Override
	public double Oblicz() {
		return 1/a.Oblicz();
	}
	public String toString() {
		return "(1/"+a.Oblicz()+")";
	}

}
