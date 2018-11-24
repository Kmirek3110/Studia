import java.awt.*;

import java.awt.image.*;
import java.awt.event.*;
import java.io.*;
import javax.imageio.*;

public class MojeOkno extends Frame {
	

	Maze a = new Maze(19);
	
	private static int x0=2,y0=1;
	
    private WindowListener frameList = new WindowAdapter()
    {
        @Override
        public void windowClosing (WindowEvent ev)
        {
            MojeOkno.this.dispose();
        }
    };
    private KeyListener keyList = new KeyAdapter()
    {
        @Override
        public void keyPressed (KeyEvent ev)
        {
            switch (ev.getKeyCode())
            {
            case KeyEvent.VK_W: // klawisz 'W'
            	if(a.data[x0][y0-1]!=0)
            	{
            	y0-=1;
            	plotno.repaint();
            	}
                break;
            case KeyEvent.VK_A: // klawisz 'A'
            	if(a.data[x0-1][y0]!=0)
            	{
            	x0-=1;
            	plotno.repaint();
            	}
            	
                break;
            case KeyEvent.VK_S:// klawisz 'S'
            	if(a.data[x0][y0+1]!=0)
            	{
            	y0+=1;
            	plotno.repaint();
            	}
            	
            	
                break;
            case KeyEvent.VK_D: // klawisz 'D'
            	if(a.data[x0+1][y0]!=0)
            	{
            	x0+=1;
            	plotno.repaint();
            	}
            default: // inne klawisze
                x0+=0;
                y0+=0;
                plotno.repaint();
                break;
            }
        }
    };
    
    private Canvas plotno = new Canvas() {
        @Override
        public void paint(Graphics gr) {
            super.paint(gr);
            gr.setColor(new Color(192, 192, 192));
            
           
           String filename = "eksplorator.jpg";
           try {
			Image badacz = ImageIO.read(new File(filename) );
			for(int y = 0; y < 19; y++) {
                for(int x = 0; x < 19; x++) {
                	if(x==x0 && y==y0)
                	{
                		 gr.drawImage(badacz, x*20,y*20, 20, 20, Color.WHITE, null);
                		
                	}
                else if(a.data[x][y] == a.WALL ) {
                	  gr.setColor(Color.RED);
                	  gr.fillRect(x*20, y*20, 20, 20);
                   } 
                   else if( a.data[x][y]== a.SPACE && x==16 && y==1) {
                	  gr.setColor(Color.YELLOW );
                	  gr.fillRect(x*20, y*20, 20, 20);
                   }
                   else 
                   {
                	   gr.setColor(Color.WHITE);
                 	  gr.fillRect(x*20, y*20, 20, 20);
                   }
                }
                
			}
			
			
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
      
           
        }
       


    };
   

    public MojeOkno()
    {
    	
        super("Maze");
        a.generate();
      
        setSize(400, 400);
        
        add(plotno, BorderLayout.CENTER);
        plotno.addKeyListener(keyList);
        setFocusable(true);
        setVisible(true);
        plotno.requestFocus();
        addWindowListener(frameList);
    }

}
