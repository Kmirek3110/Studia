package gra;

import java.util.Random;

public class Kido implements Runnable {
    public int x, y, state = 1;
    int id;
    boolean running = true;
    boolean cos=true;
    int pole=0;

    public Kido(int nr)
    {
        this.id = nr;
        x = (int) Math.floor(Math.random() * Main.szerPlanszy);
        y = (int) Math.floor(Math.random() * Main.wysPlanszy);
        while((MainPanel.checkVis(x,y, nr)) == false)
        {
            x = (int) Math.floor(Math.random() * Main.szerPlanszy);
            y = (int) Math.floor(Math.random() * Main.wysPlanszy);
        }
    }

    @Override
    public void run()
    {
        while (running)
            try
            {
                System.out.println(Thread.currentThread().getName());

                if(state == 1 && cos==true)
                {
                	
                    
                    ruch();
                    pole++;
                    
                    if(pole==3)
                    {
                    state = 2;
                    Thread.currentThread();
				    Thread.sleep((int)(Math.random()* 5000 + 3000));
					cos=false;
                    pole=0;   
						
                    }
                    
                }
                

                    else
                    {
                        int rand = (int) (Math.random() * 4);
                        int nx = (x + MainPanel.c1[rand] + Main.szerPlanszy) % Main.szerPlanszy;
                        int ny = (y + MainPanel.c2[rand] + Main.wysPlanszy) % Main.wysPlanszy;
                        while((MainPanel.checkVis(nx,ny, id)) == false)
                        {
                            rand = (int) Math.floor(Math.random() * 4);
                            nx = (x + MainPanel.c1[rand] + Main.szerPlanszy) % Main.szerPlanszy;
                            ny = (y + MainPanel.c2[rand] + Main.wysPlanszy) % Main.wysPlanszy;
                        }
                        state = 2;
                        Thread.currentThread();
						Thread.sleep((int)(Math.random()* 5000 + 3000));
                        state = 1;
                        for(int px : MainPanel.c1)
                            for(int py : MainPanel.c2)
                            	if(x+px==-1 || y+py==-1)
                            		continue;
                            	else
                            	{
                                if(MainPanel.prezent[x+px][y+py] == true)
                                {
                                    MainPanel.setVis(x, y, 0);
                                    MainPanel.setPrez((x + px + Main.szerPlanszy) % Main.szerPlanszy, (y + py + Main.wysPlanszy) % Main.wysPlanszy, false);
                                    x = (x + px )%Main.szerPlanszy;
                                    y = (y + py)%Main.wysPlanszy;
                                    state = 0;
                                    running = false;
                                    continue;
                                }
                            	}
                        cos=true;
                    }
                 

            }
            catch(InterruptedException ex)
            {
                System.out.println(ex);
                return;
            }
    }

    private synchronized void ruch()
    {
        if(odl(x, y) ==1)
            Main.koniecGry = true;
        boolean ruch = true;
        for(int px : MainPanel.c1)
            for(int py : MainPanel.c2)
                if(ruch == true)
                {
                    int nx = (x + px)%Main.szerPlanszy;
                    int ny = y+ py%Main.wysPlanszy;
                    if(odl(nx, ny) < odl(x, y) && MainPanel.getVis(nx, ny) == 0)
                    {
                        MainPanel.setVis(x, y, 0);
                        x = nx;
                        y = ny;
                        MainPanel.setVis(nx, ny, id);
                        ruch = false;
                    }
                }
    }

    private synchronized double odl(int x, int y) {
        return  Math.sqrt((MainPanel.getMikX()-x)*(MainPanel.getMikX()-x)+(MainPanel.getMikY()-y)*(MainPanel.getMikY()-y));
    }


}