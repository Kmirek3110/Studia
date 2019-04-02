package gra;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

import javax.swing.JPanel;

public class MainPanel extends JPanel {
    /**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	//Pozycja mikolaja
	static int mPosX = 0,mPosY = 0;
    private int kol, wiersz, x, y;
    private int jednostka;

    private static int vis[][] = new int[100][100];
    public static boolean[][] prezent = new boolean[100][100];
    public static int c1[] = {1, -1, 0, 0}, c2[] = {0, 0, -1, 1};
    
    //Konstruktor
    public MainPanel(int kol, int wiersz, int x, int y) 
    {
        this.setSize(x , y );
        this.kol = kol;
        this.wiersz = wiersz;
        this.x = x ;
        this.y = y ;
        jednostka = x / kol;
        
        
        this.addKeyListener(keyList);
        init();
    }
    //Klawisze
    private KeyListener keyList = new KeyAdapter()
    {
        @Override
        public void keyPressed (KeyEvent ev)
        {
            switch (ev.getKeyCode())
            {
                case KeyEvent.VK_A:
                    mPosX = mPosX - 1 ;
                    break;
                case KeyEvent.VK_D:
                    mPosX = mPosX + 1; 
                    break;
                case KeyEvent.VK_W:
                    mPosY = mPosY - 1 ;
                    break;
                case KeyEvent.VK_S:
                    mPosY = mPosY + 1 ;
                    break;
                case KeyEvent.VK_SPACE:
                    if (Main.lPrezentow > 0) {
                        Main.lPrezentow--;
                        prezent[mPosX][mPosY] = true;
                    }

                    break;
                case KeyEvent.VK_P:
                    Main.koniecGry = false;
                    break;
            }
        }
    };

    //Inicjacja
    void init()
    {
        this.addKeyListener(keyList);
        this.setFocusable(true);
        this.requestFocus();

       
    }

    //Malowanie pola
    @Override
    public void paint(Graphics g)
    {
        super.paint(g);
        if(Main.koniecGry == false)
        {

            for (int i = 0;i<Main.szerPlanszy;i++){
                g.drawLine(0,jednostka*i,Main.szerPlanszy * jednostka,jednostka*i);
                g.drawLine(jednostka*i,0,jednostka*i, Main.wysPlanszy * jednostka);
            }
            g.setColor(Color.RED);
            g.fillRect(mPosX *jednostka/2,mPosY *jednostka/2 ,30,30);
            g.setColor(Color.BLACK);

            for(int i = 0; i < 99; i++)
                for(int j = 0; j < 99; j++)
                    if(prezent[i][j] == true)
                        g.drawString("PREZENT", (int)(i * jednostka/2) ,(int)( j * jednostka/2 )+30);

            
            for(Kido dziecko : MainFrame.dzieci)
            {
                g.drawOval(dziecko.x * jednostka, dziecko.y * jednostka, jednostka, jednostka);
                if(dziecko.state == 0)
                    g.drawLine(dziecko.x * jednostka, dziecko.y * jednostka, dziecko.x * jednostka + jednostka, dziecko.y * jednostka + jednostka);
                if(dziecko.state == 2)
                    g.drawString("spi", dziecko.x * jednostka + 30, dziecko.y * jednostka + 40);
                g.drawString(Integer.toString(dziecko.id), dziecko.x  * jednostka, (dziecko.y + 1) * jednostka);
            }
         
        }
    }


    public static synchronized void setVis(int x, int y, int nr)
    {
        vis[x][y] = nr;
    }

    public static synchronized boolean checkVis(int x, int y, int nr)
    {
        if(vis[x][y] != 0)
            return false;
        else
            vis[x][y] = nr;
        return true;
    }

    public static synchronized int getMikY() {
        return MainPanel.mPosY;
    }

    public static synchronized void setmPosXikY(int mikY) {
        MainPanel.mPosY = mikY;
    }

    public static synchronized int getMikX() {
        return MainPanel.mPosX;
    }

    public static synchronized int getVis(int x, int y)
    {
        return MainPanel.vis[x][y];
    }

    public static synchronized void setPrez(int x, int y, boolean b)
    {
        prezent[x][y] = b;
    }

    public static synchronized boolean getPrez(int x, int y)
    {
        return prezent[x][y];
    }

}