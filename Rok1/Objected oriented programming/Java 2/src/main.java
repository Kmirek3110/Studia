//Karol Mirek
//Pracownia PO, czwartek, s.108
//L6, z5, MergeSort
//MergeSort
//Main
//2018-04-04 
//Java
//Eclipse 
public class main {
	//Klasa g³ówna
	public static void main(String[] args)
	{
		int[] T= new int[20000];
		for(int i=0;i<20000;i++)
		{
			T[i]=20000-i;	
			
		}
		//int[] T = {2,34,12,16,40,36,18,13,4,23,10,59,75,39,49,48,14,50,98,72};
		//Tworzymy tablicê do sortowania

        MergeSort sort = new MergeSort(T, 0, T.length); sort.start();
        //Tworzymy nowy obiekt
        
        try
        {
        	sort.join();
        }
        //Zg³aszamy wyj¹tki
        catch(Exception e) {}

        //Wypisujêmy wynik
        for(int i = 0; i < T.length; i++) System.out.println(T[i]);
	}
	

}
