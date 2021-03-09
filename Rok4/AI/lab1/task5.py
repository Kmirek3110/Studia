import random


def opt_dist(row, size):
    size = int(size)
    row = [int(x) for x in row]
    suma = sum(row)
    change = 99999
    for i in range(len(row)-size+1):
        window = row[i:i+size]
        _change = size - 2*sum(window) + suma
        if _change < change:
            change = _change

    return change

def correct_rows(img, correct_per_rows):
    for init, row  in enumerate(img):
        if opt_dist(row, correct_per_rows[init]) > 0 :
            return (False, init) 
    
    return (True, -1)

def correct_columns(img, correct_per_columns, rows, columns):
    col_img = [[0 for _ in range(columns)]for _ in range(rows)]
    for x in range(rows):
        for y in range(columns):
            col_img[x][y] = img[y][x]

    for init, column  in  enumerate(col_img):
        if opt_dist(column, correct_per_columns[init]) > 0 :
            return (False, init) 
    
    return (True, -1)
        
def generate_img(rows, columns):
    img = [[0 for _ in range(columns)]for _ in range(rows)]
    for i in range(rows):
        for j in range(columns):
            tmp = random.randint(0, 1)
            if tmp:
                img[i][j] += 1
    return img

def maxime_position(img, correct_rows, correct_columns, idx, columns_wise = False):
    idx = 0 
    best_dist = 999999
    act = 0
    test = []
    for i in range(columns):
        act = img[rows_situation[1]][i]
        img[rows_situation[1]][i] += 1
        img[rows_situation[1]][i] %= 2
        _val  = opt_dist(img[rows_situation[1]], correct_per_rows[rows_situation[1]])
        test.append(_val)
        if _val  < best_dist:
            best_dist = _val
            idx = i
        img[rows_situation[1]][i] = act
    img[rows_situation[1]][idx] += 1
    img[rows_situation[1]][idx] %= 2

def solve():
    output = open("zad5_output.txt", "w")
    
    f = open("zad5_input.txt", 'r')
    input_lines = f.readlines()
    rows, columns = input_lines[0].split()
    rows, columns = int(rows), int(columns)
    correct_per_rows = [0 for _ in range(rows)]
    correct_per_columns = [0 for _ in range(columns)]
    for i in range(1, len(input_lines)):
        if i <= rows:
            correct_per_rows[i-1] = input_lines[i]
        else:
            correct_per_columns[i-rows-1] = input_lines[i]

    img = generate_img(rows, columns)

    turns_to_fix = 10000
    while True:
        rows_situation = correct_rows(img, correct_per_rows)
        column_situation = correct_columns(img, correct_per_columns, rows, columns)
        if rows_situation[0] and correct_columns(img, correct_per_columns, rows, columns)[0]:
            break

        if not rows_situation[0]:
            idx = 0 
            best_dist = 999999
            act = 0
            test = []
            for i in range(columns):
                act = img[rows_situation[1]][i]
                img[rows_situation[1]][i] += 1
                img[rows_situation[1]][i] %= 2
                _val  = opt_dist(img[rows_situation[1]], correct_per_rows[rows_situation[1]])
                test.append(_val)
                if _val  < best_dist:
                    best_dist = _val
                    idx = i
                img[rows_situation[1]][i] = act
            img[rows_situation[1]][idx] += 1
            img[rows_situation[1]][idx] %= 2
   
        else:
            print("start")
            print(column_situation[1])
            for row in img:
                print(row)
            idx = 0 
            best_dist = 999999
            act = 0
            for i in range(rows):
                act = img[i][column_situation[1]]
                img[i][column_situation[1]] += 1
                img[i][column_situation[1]] %= 2
               
                _val  = opt_dist(list(map(list, zip(*img)))[column_situation[1]], correct_per_columns[column_situation[1]])
              
                if _val  < best_dist:
                    best_dist = _val
                    idx = i
                img[i][column_situation[1]] = act
           
            img[idx][column_situation[1]] += 1
            img[idx][column_situation[1]] %= 2
            print("-------------------------")
            for row in img:
                print(row)
            # exit()

        turns_to_fix -= 1
        if turns_to_fix == 0:
            img = generate_img(rows, columns)
            turns_to_fix = 10000
        
    for x in range(rows):
        row = ""
        for y in range(columns):
            if img[x][y] == 0:
                row += '.'
            else:
                row += '#'
        output.write(row +'\n')
    


    output.close()



if __name__ == '__main__':
    solve()