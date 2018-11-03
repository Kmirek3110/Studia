package struktury;

public abstract class Zbior {

	/** metoda ma szukać pary z określonym kluczem */
	public abstract Para szukaj(String k) throws Exception;

	/** metoda ma wstawiać do zbioru nową parę */
	public abstract void wstaw(Para p) throws Exception;

	/** metoda ma odszukać parę i zwrócić wartość związaną z kluczem */
	public abstract double czytaj(String k) throws Exception;

	/** metoda ma wstawić do zbioru nową albo zaktualizować parę */
	public abstract void ustaw(Para p) throws Exception;

	/** metoda ma usunąć wszystkie pary ze zbioru */
	public abstract void czysc();

	/** metoda ma podać ile par jest przechowywanych w zbiorze */
	public abstract int ile();

	{
		/* ... */ }
}