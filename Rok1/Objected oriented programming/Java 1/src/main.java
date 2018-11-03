//Karol Mirek
//Pracownia PO, czwartek, s.108
//L6, z1, Serializable
//Serializable
//Main
//2018-04-04 
//Java
//Eclipse 

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.ObjectOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;



public class main {
	//Klasa g³ówna
	public static void main(String a[]) throws FileNotFoundException,
	IOException,ClassNotFoundException{
        //tworzymy now¹ listê
        Lista<Integer> test = new Lista<Integer>();
        //dodajemy elementy
        test.addFirst(10);
        test.addFirst(34); 
        test.addFirst(12);
        test.addLast(56);      
        test.addLast(364); 
        //usuwamy elementy
        test.removeFirst();      
        test.removeLast();       
        test.print();
        //tworzymy objekt typu OuputStream
        ObjectOutputStream out = 
        		new ObjectOutputStream(new FileOutputStream("Lista.txt"));
        //zapisujemy w objekcie nasz¹ listê
        out.writeObject(test);
        test.addFirst(14);
        //czytamy z pliku listê
        System.out.println("Teraz czytamy obiekt z pliku");
        ObjectInputStream in =
        		new ObjectInputStream (new FileInputStream("Lista.txt"));
        Lista<Integer> test2=(Lista<Integer>) in.readObject();
        //wypisujemy i sprawdzamy czy dzia³a
        test2.print();
        System.out.println("Zmieniona lista 1");
        test.print();
	}
	
}