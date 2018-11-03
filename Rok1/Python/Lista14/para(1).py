import time

file = open('slowa.txt')

chars = 'aąbcćdeęfghijklłmnńoóprsśtuwyzźż'

def get_end_pos(s_pos, list):
	for i in range(s_pos+1, len(list)):
		if len(list[s_pos]) != len(list[i]):
			return i
	return len(list)

def is_shift(word1, word2):
	shift = word1[0] - word2[0]
	for i in range(1,len(word1)):
		if word1[i] - word2[i] != shift:
			return False
	return True

def decode(word):
	word_str = [chars[i] for i in word]
	return ''.join(word_str)

def format_time(t):
	t = int(t)
	h = int(t/3600)
	t = t%3600
	m = int(t/60)
	t = t%60
	s = t
	if h < 10:
		h = '0'+str(h)
	else:
		h = str(h)
	if m < 10:
		m = '0'+str(m)
	else:
		m = str(m)
	if s < 10:
		s = '0'+str(s)
	else:
		s = str(s)
	return h+':'+m+':'+s

print('Reading file...', end = ' ', flush = True)

words = file.readlines()

print('Done')
print('Formatting words...', end = ' ', flush = True)

words_cut = []

for word in words:
	word = word.lower()
	word = word.replace('\n','')
	append_flag = True
	for char in word:
		if char not in chars:
			append_flag = False
	if append_flag:
		words_cut.append(word)
words_cut = list(set(words_cut))

print('Done')
print('Converting to numeric...', end = ' ', flush = True)

words_num = []

for word in words_cut:
	word_num = [chars.find(char) for char in word]
	words_num.append(word_num)

print('Done')
print('Sorting...', end = ' ', flush = True)

words_num.sort(key = len, reverse = True)

print('Done')
print('Classification...' , end = ' ', flush = True)

start_pos = 0
words_class = []

while start_pos != len(words_num):
    end_pos = get_end_pos(start_pos,words_num)
    new_class = set([tuple(words_num[i]) for i in range(start_pos,end_pos)])
    words_class.append(new_class)
    start_pos = end_pos

print('Done')
print('Ready with ' + str(len(words_num)) + ' elements')

start_time = time.time()
found = False

for word_class in words_class:
    for e in word_class:
        break
    print('Checking ' + str(len(word_class)) + ' elements of length ' + str(len(e)) + ' ... ', end = ' ', flush = True)
    class_start = time.time()
    for word in word_class:
        for shift in range(1,len(chars)):
            shifted_word = tuple([(v+shift)%len(chars) for v in word])
            if shifted_word in word_class:
                end_time = time.time()
                print('Found')
                print(decode(word) + ' ' + decode(shifted_word) + ', shift: ' + str(shift))
                print('In time: ' + format_time(end_time-start_time))
                found = True
                break
        if found:
            break
    if found:
        break
    class_end = time.time()
    print('checked in: ' + format_time(class_end-class_start))
