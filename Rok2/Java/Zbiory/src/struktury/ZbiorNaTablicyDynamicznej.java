package struktury;

public class ZbiorNaTablicyDynamicznej extends ZbiorNaTablicy {

	public ZbiorNaTablicyDynamicznej(int n) {
		super(n);

	}

	void Zwieksz(Para[] a) {
		Para[] b = new Para[2 * n];
		for (int i = 0; i < n; i++) {
			b[i] = a[i];
		}
		this.tablica = b;
		this.n = 2 * n;
		System.out.println("Zwiekszamy ilosc miejsc na " + n);

	}

	@Override
	public void wstaw(Para p) throws Exception {
		if (counter >= n)
			Zwieksz(tablica);
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

}
