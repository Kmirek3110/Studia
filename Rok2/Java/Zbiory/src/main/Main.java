package main;

import struktury.Para;
import struktury.ZbiorNaTablicy;
import struktury.ZbiorNaTablicyDynamicznej;

public class Main {
	public static void main(String args[]) {
		Para a = new Para("test", 1.23);
		Para b = new Para("test1", 21.23);
		Para c = new Para("test2", 123.32);
		Para d = new Para("test3", 1232.32);
		Para e = new Para("test4", 1235.32);
		ZbiorNaTablicyDynamicznej test = new ZbiorNaTablicyDynamicznej(2);
		ZbiorNaTablicy pod = new ZbiorNaTablicy(3);
		Para a1 = new Para("test", 1.235);
		Para b2 = new Para("test1", 21.235);
		Para c3 = new Para("test2", 123.325);
		Para d4 = new Para("test3", 1232.325);
		try {
			test.wstaw(a);
			System.out.println("Dynamiczna tablica");
			System.out.println(test.czytaj("test"));
			test.wstaw(b);
			System.out.println(test.czytaj("test1"));
			test.ustaw(c);
			System.out.println(test.czytaj("test2"));
			test.ustaw(d);
			System.out.println(test.czytaj("test3"));
			test.ustaw(e);
			System.out.println(test.czytaj("test4"));
			System.out.println(test.ile());
			test.czysc();
			System.out.println(test.ile() + "\n");

			System.out.println("Zwykla tablica");
			pod.wstaw(a1);
			System.out.println(pod.czytaj("test"));
			pod.wstaw(b2);
			System.out.println(pod.czytaj("test1"));
			pod.wstaw(c3);
			System.out.println(pod.czytaj("test2"));

			pod.wstaw(d4);

		} catch (Exception error) {
			System.out.println(error);
		}

	}
}
