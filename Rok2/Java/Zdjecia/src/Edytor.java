import java.awt.AWTException;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.Rectangle;
import java.awt.Robot;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionListener;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.JButton;
import javax.swing.JColorChooser;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;

public class Edytor extends JFrame {
	/**
	 * 
	 */
	JPanel main=new JPanel();
	
	Paint paint = new Paint();	
	private static final long serialVersionUID = 1L;
	JFrame window = new JFrame("Simple Paint");
	private JButton kolory = new JButton("Zmiana koloru");
	JPanel panelColor = new JPanel();
	private JLabel kor = new JLabel("x a ");
	private JButton zapis = new JButton("Zapisz");
	JScrollPane skrol= new JScrollPane(paint,JScrollPane.VERTICAL_SCROLLBAR_ALWAYS,JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);
	private JButton plus = new JButton("+");
	private JButton minus = new JButton("-");
	private JButton red = new JButton("red");
	private JButton blue = new JButton("blue");
	private JButton yellow = new JButton("yellow");
	private JButton black = new JButton("black");
	
	
	
	
	private ActionListener ust_kol = new ActionListener() {
        public void actionPerformed(ActionEvent ev) {
			Color c= JColorChooser.showDialog(null, "Kolor",Color.BLACK);
			paint.zmiana_kol(c);
        }
    };
    private ActionListener redy = new ActionListener() {
        public void actionPerformed(ActionEvent ev) {
        	
			paint.zmiana_kol(Color.RED);
        }
    };
    private ActionListener yellowy = new ActionListener() {
        public void actionPerformed(ActionEvent ev) {
        	
			paint.zmiana_kol(Color.yellow);
        }
    };
    private ActionListener bluey = new ActionListener() {
        public void actionPerformed(ActionEvent ev) {
        	
			paint.zmiana_kol(Color.blue);
        }
    };
    private ActionListener blacky = new ActionListener() {
        public void actionPerformed(ActionEvent ev) {
        	
			paint.zmiana_kol(Color.BLACK);
        }
    };
    
    
    
       
    private ActionListener zapisz = new ActionListener() {
        public void actionPerformed(ActionEvent ev) {
        	
        	 String[] mozliwosci = {"jpg", "png"};
             String wybor = (String)JOptionPane.showInputDialog(
                 Edytor.this, "Mozliwe Rozszerzenia:", "Wybierz format", 
                 JOptionPane.WARNING_MESSAGE, null,
                 mozliwosci, mozliwosci[0]);
            
             
        	String filename = "poprawionezdjęcie."+wybor;
        	//Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize(); ScreenShot
        	Rectangle screenRectangle = new Rectangle(paint.getWidth(),paint.getHeight());
        	Robot robot = null;
			try {
				robot = new Robot();
			} catch (AWTException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
        	BufferedImage image = robot.createScreenCapture(screenRectangle);
        	
        	
        	try {
        		ImageIO.write(image, wybor, new File(filename));
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
        }
    };
    
    
    private MouseMotionListener myszka= new MouseMotionListener()
    		{

				@Override
				public void mouseDragged(MouseEvent e) {
					kor.setText(Integer.toString(paint.prevX)+","+Integer.toString(paint.prevY));
					
				}

				@Override
				public void mouseMoved(MouseEvent e) {
					kor.setText(Integer.toString(paint.prevX)+","+Integer.toString(paint.prevY));
					
				}
				
			};
    		
			{
				window.setContentPane(main);
			       main.setLayout(new BorderLayout());
			        
			       main.add(panelColor,BorderLayout.NORTH);
			        
			       panelColor.add(kolory);
			       panelColor.add(zapis);
			        
			       zapis.addActionListener(zapisz);
			        
			       panelColor.add(plus);
			       
			       panelColor.add(minus);
			        
			       paint.setLayout(new BorderLayout());
			       paint.add(kor,BorderLayout.SOUTH);
			        
			        
			       panelColor.add(red);
			       panelColor.add(yellow);
			       panelColor.add(black);
		           panelColor.add(blue);
			          
			       main.add(skrol);
			             
			       red.addActionListener(redy);
			       blue.addActionListener(bluey);
			       black.addActionListener(blacky);
			       yellow.addActionListener(yellowy);
			       
			       paint.addMouseMotionListener(myszka);
		           kolory.addActionListener(ust_kol);
				}
	
	public Edytor() {	 
		
        window.setSize(1200,600);
        window.setVisible(true);
    }
	
}
