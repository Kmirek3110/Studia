import numpy as np 
import matplotlib.pyplot as plt  
import matplotlib.animation as animation 
  

white = 1
black = 0
directions = ["left","up","right","bottom"]
dir_val = 1
direction = directions[dir_val]
x, y = 50, 50

  
def update(frameNumber, img, grid, N):
    global x,y,dir_val,direction 
    newGrid = grid.copy()
    if grid[x,y] == white:
        newGrid[x,y] = black
        if direction == "left":
            y -= 1
        elif direction == "up":
            x -=1
        elif direction == "right":
            y +=1
        else :
            x+=1
        dir_val -= 1 
        if dir_val < 0:
            dir_val = 3
        direction = directions[dir_val]
    else:
        newGrid[x,y] = white
        if direction == "left":
            y += 1
        elif direction == "up":
            x +=1
        elif direction == "right":
            y -=1
        else :
            x-=1
        dir_val += 1 
        if dir_val > 3:
            dir_val = 0
        direction = directions[dir_val]
        
    img.set_data(newGrid) 
    grid[:] = newGrid[:] 
    return img, 
  
def main(): 
    global x,y 
    N = 100
    updateInterval = 50
    grid = np.ones((N,N))
    grid[x,y]=black
  
    fig, ax = plt.subplots() 
    img = ax.imshow(grid, interpolation='nearest') 
    ani = animation.FuncAnimation(fig, update, fargs=(img, grid, N, ), 
                                  frames = 10, 
                                  interval=updateInterval, 
                                  save_count=50) 
  
    plt.show() 
  
if __name__ == '__main__': 
    main() 