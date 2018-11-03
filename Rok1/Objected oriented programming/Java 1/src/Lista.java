//Karol Mirek
//Pracownia PO, czwartek, s.108
//L6, z1, Serializable
//Serializable
//Double Linked List
//2018-04-04 
//Java
//Eclipse 


import java.io.Serializable;
import java.util.NoSuchElementException;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.ObjectOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;

public class Lista<E> implements Serializable{
	//Klasa Lista implementuj¹ca Serializable
 
    private Node head;
    private Node tail;
    private int size;
    
    //Konstruktor
    public Lista() {
        size = 0;
    }
    
    //Klasa dodatkowa która, te¿ implementujê  Serializable
    private class Node implements Serializable {
        E element;
        Node next;
        Node prev;
 
        //Konstruktor
        public Node(E element, Node next, Node prev) {
            this.element = element;
            this.next = next;
            this.prev = prev;
        }
    }
 
    //Rozmiar Listy
    public int size() { return size; }
     
    //Sprawdzamy czy lista jest pusta
    public boolean isEmpty() { return size == 0; }
     
    //Dodajemy pierwszy element listy
    public void addFirst(E element) {
        Node tmp = new Node(element, head, null);
        if(head != null ) {head.prev = tmp;}
        head = tmp;
        if(tail == null) { tail = tmp;}
        size++;
        
    }
     
    //Dodajemy ostatni element listy
    public void addLast(E element) {
         
        Node tmp = new Node(element, null, tail);
        if(tail != null) {tail.next = tmp;}
        tail = tmp;
        if(head == null) { head = tmp;}
        size++;
        
    }

    //Usuwamy pierwszy element listy
    public E removeFirst() {
        if (size == 0) throw new NoSuchElementException();
        Node tmp = head;
        head = head.next;
        head.prev = null;
        size--;
       
        return tmp.element;
    }
     
    //Usuwamy ostatni element listy
    public E removeLast() {
        if (size == 0) throw new NoSuchElementException();
        Node tmp = tail;
        tail = tail.prev;
        tail.next = null;
        size--;
        
        return tmp.element;
    }
    
    //Wypisujemy wszystkie elementy
    public void print() {
    	Node tmp = head;
    	while(tmp != null)
    	{
    		System.out.println(tmp.element);
            tmp = tmp.next;
    	}
    	
    }	
        
}