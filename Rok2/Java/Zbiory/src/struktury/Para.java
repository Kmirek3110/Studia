package struktury;

public class Para {
	public final String klucz;
	private double wartość;

	public Para(String klucz, Double wartość) {
		this.klucz = klucz;
		this.wartość = wartość;
	}

	public String toString() {
		return ("Dla klucza " + klucz + "wartość wynosci = " + wartość);
	}

	public boolean equals(Para a) {
		return this.klucz == a.getKlucz();
	}

	public String getKlucz() {
		return klucz;
	}

	public double getWartość() {
		return wartość;
	}

	public void setWartość(double wartość) {
		this.wartość = wartość;
	}

}
