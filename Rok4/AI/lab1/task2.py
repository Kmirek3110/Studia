zad2_words = set()
input_string = ""
max_word_length = 0
solution = []


def solve():
    global zad2_words, max_word_length, input_string
    output = open("zad2_output.txt", "w")
    with open("slowa.txt", 'r') as f:
        for word in f:
            word = word.replace('\n', '')
            if len(word) > max_word_length:
                max_word_length = len(word)
            zad2_words.add(word)
    
    if len(input_string) < max_word_length:
        max_word_length = len(input_string)
    for line in input_string:
        line = line.strip()
        correct = generate_solution(line, min(max_word_length, len(line)))
        output.write(correct+'\n')
    output.close()


def read_input_string():
    global input_string
    f = open("zad2_input.txt", 'r', encoding='utf-8')
    input_string = f.readlines()


def generate_solution(line, max_word_length):
    global zad2_words
    
    possibilites = [False for _ in range(len(line))]
    words_in_text = []

    # print(line)

    for i in range(len(line), 0, -1):
        for j in range(0, len(line), 1):
            if i == len(line) or possibilites[i]:
                if line[j:i] in zad2_words:
                    words_in_text.append((j, i, line[j:i], (i-j)**2))
                    possibilites[j] = True  


    test = [(0,"", 0) for _ in range(1, len(line)+2)]
    for i in range(1, len(line)+1):
        for start, end, word, dist in reversed(words_in_text):
            if end == i:
                if test[i][2] == 0 or test[i][2] < dist + test[start][2]:
                    test[i] = tuple([start, test[start][1] +" "+ word, dist + test[start][2]])

    # print(test[len(line)][1].strip())
    return test[len(line)][1].strip()


read_input_string()
solve()
    # print_solution()