package obliczenia;

/**
 * @author karol
 *Klasa reprezentująca Arcus Tangens
 */
public class Arctan extends Op1{

	public Arctan(Wyrazenie a)
	{
		this.a=a;
	}

	@Override
	public double Oblicz() {
		return Math.atan(a.Oblicz());
	}
	public String toString() {
		return "arctan("+a.toString()+")";
	}

}
