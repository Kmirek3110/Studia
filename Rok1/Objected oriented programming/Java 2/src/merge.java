//Karol Mirek
//Pracownia PO, czwartek, s.108
//L6, z5, MergeSort
//MergeSort
//Klasa sortuj¹ca
//2018-04-04 
//Java
//Eclipse 


class MergeSort extends Thread
//Klasa MergeSort, która u¿ywana Thread
{

    int[] array;
    int start, end;
    
    //Konstruktor
    public MergeSort(int[] a, int s, int e) { array = a; start = s; end = e; }

    //£¹czenie
    private  void merge(int[] temp)
    {
        int i1, i2, a;

        i1 = start;
        i2 = end / 2;
        a = 0;

        //Sprawdzamy w jakiej kolejnosci mamy ³¹czyæ elementy 
        while (i1 < end / 2 && i2 < end) {
            if (array[i1] < array[i2])
                temp[a++] = array[i1++];
            else
                temp[a++] = array[i2++];
        }

        while (i1 < end / 2) {
            temp[a++] = array[i1++];
        }

        while (i2 < end) {
            temp[a++] = array[i2++];
        }

        System.arraycopy(array, start, temp, 0, end - start);
    }

    //Sortowanie przez wstawianie
    private   void insertionSort()
    {
        for (int i = start; i < end; i++)
        {
            int j, v = array[i];

            for (j = i - 1; j >= 0; j--) {
                if (array[j] <= v)
                    break;
                array[j + 1] = array[j];
            }

            array[j + 1] = v;
        }
    }

    //Wymóg Thread metoda run()
    public  void run()
    {
        int[] temp = new int[end];

        if ((end - start) < 2) {
            insertionSort();
            return;
        }

        MergeSort sort1 = new MergeSort(array, start, start + ((end-start)/2));
        MergeSort sort2 = new MergeSort(array, start + ((end-start)/2), end);

        sort1.run();
        sort2.run();
        try {
          sort1.join();
          sort2.join();
        }
        catch (Exception e) {}

        merge(temp);
    }
}