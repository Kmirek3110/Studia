import os
import queue
import random
import numpy

import itertools
   
_dirs = {'U': (0, -1), 'D': (0, 1), 'R': (1, 0), 'L': (-1, 0)}
MOVES = ["U", "D", "L", "R"]
# MOVES = ["L"]

class Maze:
    def __init__(self, input):
        # print(input)
        self.img = input
        # print(self.img)
        # self.mazey, self.mazex = numpy.array(input).shape
        self.starts, self.goals = self.readMap(input)
        # print(self.mazex, self.mazey)

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
                
                
    
    def solve(self):

        minimal_moves = 100000000000
        initState = tuple(self.starts)
        for _ in range(13):
            no = 7
            seq = random.choices(MOVES, k=3)
            greedy_seq = seq[0] * no + seq[1] * no + seq[2] * no
            positions, amount_of_starts = self.moves(initState, greedy_seq)
    
            if amount_of_starts < minimal_moves:
                minimal_moves = amount_of_starts
                best_seq = greedy_seq
                best_positions = positions
            
        game_queue = queue.Queue()
        game_queue.put((best_positions, best_seq))

        visited = set()
        visited.add(tuple(best_positions))
               
      
        while not game_queue.empty():

            state = game_queue.get()
            curr_moves = state[1]

            if all(s in self.goals for s in state[0]):
                return curr_moves
            
            if len(state[0]) != len(set(state[0])):
                visited.clear()
                visited.add(tuple(set(state[0])))
                game_queue.queue.clear()
                game_queue.put((set(state[0]), curr_moves))
                

            for move in MOVES:
                list_states = []
                for s in set(state[0]):
                    x = s[0] + _dirs[move][0]
                    y = s[1] + _dirs[move][1]
                    if(self.img[y][x] == "#"):
                        list_states.append((s[0], s[1]))
                    else:
                        list_states.append((x,y))

                if tuple(list_states) not in visited:
                    visited.add(tuple(list_states))
                    moves = curr_moves + move
                    game_queue.put((list_states, moves))


if __name__ == '__main__':
    with  open("zad_input.txt", 'r') as f:
        maze = [list(line.strip('\n')) for line in f]
       
        Game_maze = Maze(maze)
        x = Game_maze.solve()
        print(len(x))
        print(x)
        output = open("zad_output.txt", 'w')
        output.write(x)
