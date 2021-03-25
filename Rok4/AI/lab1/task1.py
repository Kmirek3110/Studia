import os
import queue

class Board_State:
    def __init__(self, wk, wt, bk, turn):
        self.wk = wk
        self.wt = wt
        self.bk = bk
        self.turn = turn

    def posInt(self, s):
        column = ord(s[0]) - ord('a')
        row = ord(s[1]) - ord('1')
        return column, row


    def posStr(self, col, row):
        return str(chr(col + ord('a'))) + str(chr(row + ord('1')))

    def rook_reach(self):
        rook_control = [self.wt]
        col, row = self.posInt(self.wt)

        for i in range(row, -1, -1):
            if (col, i) == self.posInt(self.wk):
                break
            rook_control.append(self.posStr(col, i))
        
        for i in range(row, 8):
            if (col, i) == self.posInt(self.wk):
                break
            rook_control.append(self.posStr(col, i))

        for i in range(col, -1, -1):
            if (i, row) == self.posInt(self.wk):
                break
            rook_control.append(self.posStr(i, row))
        
        for i in range(col, 8):
            if (i, row) == self.posInt(self.wk):
                break
            rook_control.append(self.posStr(i, row))
            

        return set(rook_control)


    def isCheckmate(self):             
        white_king_atacks = self.kingAttacks(self.wk)

        
        escape_blocks = self.kingAttacks(self.bk)
        
        rook_control = self.rook_reach()
        
        if self.bk in white_king_atacks or self.bk in rook_control:
            if self.wt not in escape_blocks:
                if escape_blocks - (rook_control.union(white_king_atacks)) == set():
                    return True
        return False



    def kingAttacks(self, king):
        king_reach = []
        col, row = self.posInt(king)

        if col > 0 and row > 0:
            king_reach.append(self.posStr(col - 1, row - 1))  
        if row > 0:
            king_reach.append(self.posStr(col, row - 1))       
        if row > 0 and col < 7:
            king_reach.append(self.posStr(col + 1, row - 1))  
        if col > 0:
            king_reach.append(self.posStr(col - 1, row))       
        if col < 7:    
            king_reach.append(self.posStr(col + 1, row))       
        if col > 0 and row < 7:
            king_reach.append(self.posStr(col - 1, row + 1))  
        if row < 7:   
            king_reach.append(self.posStr(col, row + 1))       
        if row < 7 and col < 7 :      
            king_reach.append(self.posStr(col + 1, row + 1))   

        return set(king_reach)



    def generate_moves(self):
        moves = []

        rook_positions = self.rook_reach() - set([self.wk, self.bk])
        if self.turn == "black":
            moves_black_king = self.kingAttacks(self.bk) - self.kingAttacks(self.wk) - rook_positions
            for move in moves_black_king:
                 moves.append((self.wk, self.wt, move, "white"))
            return moves

        moves_white_king = self.kingAttacks(self.wk) - self.kingAttacks(self.bk) - set(self.wt)

        for move in moves_white_king:
            moves.append((move, self.wt, self.bk, "black"))

        for move in rook_positions:
            moves.append((self.wk, move, self.bk, "black"))

        return moves

        
def solve(setup):
    initState = (setup[1], setup[2], setup[3], setup[0])
    board = Board_State(setup[1], setup[2], setup[3], setup[0])
    game_queue = queue.Queue()
    game_queue.put(initState)
  
    states = { initState: (0, initState) }
        
    while game_queue.empty() == False:
        state = game_queue.get()
        board.wk, board.wt, board.bk, board.turn = state
        if board.isCheckmate():
            while states[state][0] != 0:
                print(states[state][1])
                state = states[state][1]
            break
        depth, _ = states[state]
        for move in board.generate_moves():
            if move not in states:
                states[move] = (depth + 1,  state)
                game_queue.put(move)
        
    return depth


    
if __name__ == "__main__":
    with open("zad1_input.txt","r") as input:
        output = open("zad1_output.txt", "w")
        for setup in input.readlines():
            x = solve(setup.split())
        output.write(str(x)+'\n')
        input.close() 
        output.close()
   
