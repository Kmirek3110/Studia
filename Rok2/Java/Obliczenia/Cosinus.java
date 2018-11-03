package obliczenia;

/**
 * @author karol
 *Klasa reprezentująca Cosinus
 */
public class Cosinus  extends Op1{

	Wyrazenie a;
	public Cosinus(Wyrazenie a)
	{
		this.a=a;
	}

	@Override
	public double Oblicz() {
		return Math.cos(a.Oblicz());
	}
	
	public String toString() {
		return "Cos("+a.Oblicz()+")";
	}

}
