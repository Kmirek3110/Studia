import java.awt.EventQueue;
import javax.swing.JFrame;

public class main {
	public static void main(String[] args)
	{
		String plik="";
		String klasa="Ksiazka";
		EventQueue.invokeLater(
				new Runnable()
				{
					public void run()
					{
						JFrame ex;
						if(klasa == "Ksiazka")
							ex = new EdytorKs(plik);
		            	else 
		            		ex = new EdytorWc(plik);
		            	
		                ex.setVisible(true);
					}
				});
		
		
		
	}
}