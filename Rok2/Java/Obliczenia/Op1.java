package obliczenia;

/**
 * @author karol
 *Klasa abstakcyjna reprezentująca operatory1 elementowe
 */
abstract class Op1 extends Wyrazenie {
	Wyrazenie a;
	public abstract double Oblicz();
}
