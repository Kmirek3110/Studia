import java.io.Serializable;
public class Ksiazka implements Serializable {
	private static final long serialVersionUID = 4661681646491395516L;
	public String tytul, autor;
	public int wydanie;
	
	
	public Ksiazka(String tytul, String autor, int wydanie)
	{
		this.tytul = tytul; this.autor = autor; this.wydanie = wydanie;
	}
	public Ksiazka() {this("tytul","autor",1998);}
	public String toString()
	{
		return tytul + "\n" + autor + "\n" + Integer.toString(wydanie); 
	}

}
