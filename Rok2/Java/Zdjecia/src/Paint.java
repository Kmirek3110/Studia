import java.awt.*;
import java.awt.event.*;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.*;

public class Paint extends JPanel implements MouseListener, MouseMotionListener{
	String filename ="test.jpg";
    private BufferedImage image;
    public int prevX, prevY;     
    public Color a =new Color(255,0,0);
    
    private boolean dragging;      
    
    private Graphics graphicsForDrawing; 
     
	private static final long serialVersionUID = 1L;
	 Paint() {
   	  try {                
             image = ImageIO.read(new File(filename));
          } catch (IOException ex) {
               
          }
            
     }
	 
	 public void paintComponent(Graphics g)     
     {
        super.paintComponent(g);  
        g.drawImage(image, 0, 0, this);
        addMouseListener(this);
        addMouseMotionListener(this);
        
     }
	 
	 private void setUpDrawingGraphics() {
         graphicsForDrawing = getGraphics();
        graphicsForDrawing.setColor(a);
 
      }
	@Override
	public void mouseDragged(MouseEvent evt) {
		if (dragging == false)
            return;  // Nothing to do because the user isn't drawing.
		int x = evt.getX();   // x-coordinate of mouse.
        int y = evt.getY();
        graphicsForDrawing.drawLine(prevX, prevY, x, y);  // Draw the line.
        
        prevX = x;  // Get ready for the next line segment in the curve.
        prevY = y;
		
	}
	public void zmiana_kol(Color a)
	{
		this.a=a;
	}
	
	@Override
	public void mouseMoved(MouseEvent arg0) {
		// TODO Auto-generated method stub
		
	}
	@Override
	public void mouseClicked(MouseEvent arg0) {
		// TODO Auto-generated method stub
		
	}
	@Override
	public void mouseEntered(MouseEvent arg0) {
		// TODO Auto-generated method stub
		
	}
	@Override
	public void mouseExited(MouseEvent arg0) {
		// TODO Auto-generated method stub
		
	}
	@Override
	public void mousePressed(MouseEvent evt) {
		
		int x = evt.getX();   // x-coordinate where the user clicked.
        int y = evt.getY();   // y-coordinate where the user clicked.
        if (dragging == true)  // Ignore mouse presses that occur
            return;
            
        prevX = x;
        prevY = y;
        dragging = true;
        setUpDrawingGraphics();
       
        	
	}
	@Override
	public void mouseReleased(MouseEvent arg0) {
		if (dragging == false)
            return;  // Nothing to do because the user isn't drawing.
         dragging = false;
         
         graphicsForDrawing = null;
		
	} 

}
