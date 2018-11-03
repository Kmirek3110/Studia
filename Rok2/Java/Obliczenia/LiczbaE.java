package obliczenia;

/**
 * @author karol
 *Klasa reprezentująca liczbe e
 */
public class LiczbaE extends Wyrazenie{

	double e;

	public LiczbaE()
	{
		this.e=Math.E;
	}
	@Override
	public double Oblicz() {
		return e;
	}
	public String toString()
	{
		return "e";
	}

}
