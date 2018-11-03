package obliczenia;

import struktury.Para;
import struktury.ZbiorNaTablicy;

/**
 * @author karol
 *KLasa reprezetnująca Zmienne
 */
public class Zmienna extends Wyrazenie {
    public static final ZbiorNaTablicy zmienne;

    public String name;
    static{
        zmienne = new ZbiorNaTablicy(50);
    }

    public Zmienna(String name){
        this.name=name;
    }
/*
 * Dodawanie zmiennych
 */
    public static void NowaZmienna(String key, double value) {
        Para para;
			para = new Para(key, value);
		
			zmienne.ustaw(para);
		
    }
    @Override
    public String toString(){
        return name;
    }

	@Override
	public double Oblicz() {
		return zmienne.czytaj(name);
	}
	
		
	
}
