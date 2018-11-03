package obliczenia;

/**
 * @author karol
 *Klasa reprezentująca liczbę pi
 */
public class LiczbaPI extends Wyrazenie{
	double pi;

	public LiczbaPI()
	{
		this.pi=Math.PI;
	}
	@Override
	public double Oblicz() {
		return pi;
	}
	
	

}
