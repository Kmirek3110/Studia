
def read_input():
    pattern = []
    output = open("zad4_output.txt", "w")
    
    f = open("zad4_input.txt", 'r', encoding='utf-8')
    
    for line in f.readlines():
        pattern, block_size = line.split(" ")
        block_size = int(block_size)
        ans = opt_dist(pattern, block_size)
        output.write(str(ans)+"\n")
    output.close()


def opt_dist(row, size):
    row = [int(x) for x in row]
    suma = sum(row)
    change = 99999
    for i in range(len(row)-size+1):
        window = row[i:i+size]
        _change = size - 2*sum(window) + suma
        if _change < change:
            change = _change

    return change




if __name__ == '__main__':
    read_input()