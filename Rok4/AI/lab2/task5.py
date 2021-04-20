import os
import queue
import random
import numpy
import heapq as H
import math
import itertools
   
_dirs = {'U': (0, -1), 'D': (0, 1), 'R': (1, 0), 'L': (-1, 0)}
MOVES = ["U", "D", "L", "R"]
# MOVES = ["L"]

class Maze:
    def __init__(self, input):
        self.img = input
        self.starts, self.goals = self.readMap(input)


    def readMap(self, input):
        starts = []
        goals = []

        for iterx, row in enumerate(input):
            for itery, field in enumerate(row):

                if field == "S":
                    starts.append((itery, iterx))

                elif field == "G":
                    goals.append((itery, iterx))

                elif field == "B":
                    starts.append((itery, iterx))
                    goals.append((itery, iterx))

        return starts, goals

    def introduce(self):
        print("Maze")
        for r in self.img:
            print("".join(r))

        print("Start positions")
        for s in self.starts:
            print(s)

        print("Goal positions")
        for g in self.goals:
            print(g)
    
    def moves(self, initState, seq):
        test = [0 for _ in initState]
        for move in seq:
            for state in range(len(initState)):
                x = initState[state][0] + _dirs[move][0]
                y = initState[state][1] + _dirs[move][1]
                if(self.img[y][x] == "#"):
                    test[state] = ( initState[state][0], initState[state][1])
                else:
                    test[state] = (x,y)

        return (list(set(test)), len(list(set(test))))

    def heuristic(self, state, cost=1):
        

        max_close = -1
        # bonus = 0
        # for (x,y) in state:
        #    if ((self.img[y+1][x] == "#" or self.img[y-1][x] == "#" ) and
        #    (self.img[y][x+1] == "#" or  self.img[y][x-1] == "#") and (x,y) not in self.goals):
        #     bonus += 1

        for s in state:
            closest = 9999
            for g in self.goals:
                dist = abs(s[0] - g[0])**2 + abs(s[1] - g[1])**2
                if math.sqrt(dist) < closest:
                    closest = math.sqrt(dist)
            if max_close < closest:
                max_close = closest
 
        return max_close  * cost 

    def heuristic1(self, state, cost=1):
        
        # max_close = -1
        avg = 0

        for s in state:
            closest = 9999
            for g in self.goals:
                dist = abs(s[0] - g[0])**2 + abs(s[1] - g[1])**2
                if math.sqrt(dist) < closest:
                    closest = math.sqrt(dist)
            avg += closest
 
        return avg // len(state) * cost

    def heuristic2(self, state, cost=1):
        
        max_close = -1

        for s in state:
            closest = 9999
            for g in self.goals:
                dist = abs(s[0] - g[0]) + abs(s[1] - g[1])
                if dist < closest:
                    closest = dist
            if max_close < closest:
                max_close = closest
 
        return max_close  * cost

    def combine(self, state):
        return max(self.heuristic(state, cost=1.45), self.heuristic2(state)) 

    def solve(self):
            
        # game_queue = PriorityQueue()
        # game_queue.put((0, tuple(self.starts), ""))
        queue = [(0, tuple(self.starts), "")]

        cost_so_far: Dict[tuple, float] = {}
        cost_so_far[tuple(self.starts)] = 0

        # cnt = 0
        while queue:
     
            # cnt += 1
            _, state, curr_moves = H.heappop(queue)
            
            # if all(s in self.goals for s in state):
            #         print(curr_moves)
            #         return curr_moves

            # print("curr_moves",curr_moves)              
            for move in MOVES:

                list_states = set()

                for s in set(state):
                    x = s[0] + _dirs[move][0]
                    y = s[1] + _dirs[move][1]

                    if(self.img[y][x] == "#"):
                        # continue
                        list_states.add((s[0], s[1]))
                    else:
                        list_states.add((x,y))
                    
                # print(list_states, self.heuristic(list_states), move)
                # if state in list_states:
                #     continue

                new_cost = cost_so_far[state] + 1
                list_states = tuple(list_states)
                if all(s in self.goals for s in list_states):
                    print(curr_moves + move)
                    return curr_moves + move

                if list_states not in cost_so_far or new_cost < cost_so_far[list_states]:
                    cost_so_far[list_states] = new_cost
                    # priority  = new_cost +  self.combine(list_states)
                    priority  = new_cost +  self.heuristic2(state,1.5)
                    # priority  = new_cost +  self.heuristic(state, 1.45)

                    # cost 1,45 optimal(highest possible)
                    # higher values speed up process but give to long solutions
                    H.heappush(queue,(priority, list_states, curr_moves + move))
                    # came_from[list_states] = (state, move) 


if __name__ == '__main__':
    with  open("zad_input.txt", 'r') as f:
        maze = [list(line.strip('\n')) for line in f]
       
        Game_maze = Maze(maze)
        # Game_maze.introduce()
        x = Game_maze.solve()
        output = open("zad_output.txt", 'w')
        output.write(x)