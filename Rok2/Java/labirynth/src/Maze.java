import javax.swing.*;
import java.awt.*;

public class Maze {

    public static final int WALL = 0;
    public static final int SPACE = 1;
    

    public byte[][] data;
    private int a;
    private java.util.Random rand = new java.util.Random();

    public Maze(int a) {
       this.a = a;
       data = new byte[a][a];
    }

    private void carve(int x, int y) {

       final int[] upx = { 1, -1, 0, 0 };
       final int[] upy = { 0, 0, 1, -1 };

       int dir = rand.nextInt(4);
       int count = 0;
       while(count < 4) {
          final int x1 = x + upx[dir];
          final int y1 = y + upy[dir];
          final int x2 = x1 + upx[dir];
          final int y2 = y1 + upy[dir];
          if(data[x1][y1] == WALL && data[x2][y2] == WALL) {
             data[x1][y1] = SPACE;
             data[x2][y2] = SPACE;
             carve(x2, y2);
          } else {
             dir = (dir + 1) % 4;
             count += 1;
          }
       }
    }

    public void generate() {
       for(int x = 0; x < a; x++) {
          data[x] = new byte[a];
          for(int y = 0; y < a; y++) {
             data[x][y] = WALL;
          }
       }
       for(int x = 0; x < a; x++) {
          data[x][0] = SPACE;
          data[x][a - 1] = SPACE;
       }
       for(int y = 0; y < a; y++) {
          data[0][y] = SPACE;
          data[a - 1][y] = SPACE;
       }

       data[2][2] = SPACE;
       carve(2, 2);

       data[2][1] = SPACE;
       data[a - 3][1] = SPACE;
    }

  
    
    
 }