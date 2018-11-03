package struktury;

public class ZbiorNaTablicy extends Zbior {
	static int counter = 0;
	int n;
	Para[] tablica = new Para[n];

	public ZbiorNaTablicy(int n) {
		if (n < 2)
			this.n = 2;
		else
			this.n = n;
		this.tablica = new Para[n];

	}

	@Override
	public Para szukaj(String k) throws Exception {

		for (int i = 0; i < n; i++) {
			if (tablica[i].getKlucz() == k)
				return tablica[i];

		}
		throw new Exception("Ni ma");
	}

	@Override
	public void wstaw(Para p) throws Exception {
		if (counter >= n)
			throw new Exception("Brak miejsca");
		boolean istnieje = false;
		for (int i = 0; i < counter; i++) {
			if (tablica[i].equals(p))
				istnieje = true;

		}
		if (istnieje)
			System.out.println("Istnije juz para z takim kluczem");
		else {

			tablica[counter] = p;
			counter++;
		}

	}

	@Override
	public double czytaj(String k) throws Exception {
		for (int i = 0; i < counter; i++) {
			if (tablica[i].getKlucz() == k)
				return tablica[i].getWartość();

		}
		throw new Exception("Brak PARY");

	}

	@Override
	public void ustaw(Para p) throws Exception {
		boolean zrobione = false;
		for (int i = 0; i < counter; i++) {
			if (tablica[i].equals(p)) {
				tablica[i] = p;
				zrobione = true;
			}
		}
		if (zrobione == false)
			wstaw(p);

	}

	@Override
	public void czysc() {

		for (int i = 0; i < n; i++) {
			tablica[i] = null;
		}
		counter = 0;

	}

	@Override
	public int ile() {

		return counter;
	}

}
