import itertools

import queue
from numpy import zeros

class Nonogram:

    def __init__(self, rows_patterns, cols_patterns):
        self.r_pattern = rows_patterns
        self.c_pattern = cols_patterns
        self.rows_size = len(rows_patterns)
        self.cols_size = len(cols_patterns)
        self.img = zeros(( self.rows_size, self.cols_size)) 
        self.queue_game = queue.Queue()


    def generete_posibilites(self, pattern, size):

        pattern = list(map(int, pattern.split(" ")))

        if len(pattern) == 1:
            zeros = size - sum(pattern)
            return [[0]*i + [1]*pattern[0] + [0]*(zeros-i) for i in range(zeros+1)]
        
        limit = size - pattern[-1]
        ans = []

        for comb in itertools.combinations(range(limit + 1), len(pattern)):
            not_overlapping = True
            for c in range(len(comb) - 1):
                if comb[c] + pattern[c] >= comb[c+1]:
                    not_overlapping = False
                    break
            if not_overlapping:
                t = [0] * size
                for i, c in enumerate(comb):
                    for j in range(c, c + pattern[i]):
                        t[j] = 1
                ans.append(t)
            
        return ans


    def match_point(self, row, pos, current_rows):

        row_point = current_rows[0][pos]
        matches_all_rows = True

        for irow in current_rows:
            if irow[pos] != row_point:
                matches_all_rows = False

        if matches_all_rows:

            self.img[row][pos] = row_point  
            self.c_poss[pos] = [column for column in self.c_poss[pos] if column[row] == row_point]
 
        else: 

            column_point = self.c_poss[pos][0][row]
            matches_all_columns = True

            for icol in self.c_poss[pos]:
                if icol[row] != column_point:
                    matches_all_columns = False

            if matches_all_columns:
                self.img[row][pos] = column_point
                self.r_poss[row] = [crow for crow in self.r_poss[row] if crow[pos] == column_point]

            else:
                self.queue_game.put((row, pos))
        

    def solve(self):
        
        self.r_poss = [self.generete_posibilites(r, self.cols_size) for r in self.r_pattern]
        self.c_poss = [self.generete_posibilites(c, self.rows_size) for c in self.c_pattern] 
         
        for row in range(self.rows_size):
            current_rows = self.r_poss[row]
            for x in range(self.cols_size):
                self.match_point(row, x, current_rows)
            
        while not self.queue_game.empty():
            row, pos = self.queue_game.get()
            current_rows = self.r_poss[row]
            self.match_point(row, pos, current_rows)

        return self.img
       



if __name__ == '__main__':
    with  open("zad_input.txt", 'r') as f:
        rows, cols = [int(x) for x in f.readline().split()]
        cnt = 0
        rows_patterns = []
        cols_patterns = []
        for r in f.readlines():
            if cnt < rows:
                rows_patterns.append(r.rstrip('\n') )
            else:
                cols_patterns.append(r.rstrip('\n') )
            cnt += 1

        game_nonogram = Nonogram(rows_patterns, cols_patterns)
        output = game_nonogram.solve()
     
        outputt = open("zad_output.txt", 'w')
        for row in output:
            line = ""
            for x in row:
                if x == 1:
                    line += "#"
                else:
                    line += "."
            outputt.write(line+"\n")
        outputt.close()    
