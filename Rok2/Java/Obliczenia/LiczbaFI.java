package obliczenia;

/**
 * @author karol
 *Klasa reprezentująca liczbę fi
 */
public class LiczbaFI extends Wyrazenie {
	double fi;

	public LiczbaFI()
	{
		this.fi=1.61803398874989484;
	}
	@Override
	public double Oblicz() {
		return fi;
	}
	public String toString()
	{
		return "fi";
	}

}
