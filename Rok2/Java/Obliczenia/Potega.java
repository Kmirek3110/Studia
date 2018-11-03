package obliczenia;

/**
 * @author karol
 *Klasa reprezentująca potęgowanie
 */
public class Potega extends Op2{
	Wyrazenie a;
	Wyrazenie b;
	public Potega(Wyrazenie a,Wyrazenie b)
	{
		this.a=a;
		this.b=b;
		
	}
	@Override
	public double Oblicz() {
		return Math.pow(a.Oblicz(), b.Oblicz());
	}
	public String toString(){
        return "("+a+"^"+b+")";
	} 
	

}
