package obliczenia;

/**
 * @author karol
 *Klasa reprezentująca sinus liczby
 */
public class Sinus extends Op1{
	Wyrazenie a;
	public Sinus(Wyrazenie a)
	{
		this.a=a;
	}

	@Override
	public double Oblicz() {
		return Math.sin(a.Oblicz());
	}
	public String toString() {
		return "Sin("+a.Oblicz()+")";
	}

}
