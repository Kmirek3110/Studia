package obliczenia;

/**
 * @author karol
 *Klasa reprezentująca logarytm
 */
public class Logarytm extends Op2{

	Wyrazenie a;
	Wyrazenie b;
	public Logarytm(Wyrazenie a,Wyrazenie b)
	{
		this.a=a;
		this.b=b;
		
	}
	@Override
	public double Oblicz() {
		return Math.log(a.Oblicz()/ b.Oblicz());
	}
	public String toString(){
		
        return "(log"+a+","+b+")";
	} 

}
