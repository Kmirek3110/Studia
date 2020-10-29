#karol_mirek
#301650

CC= g++

CFLAGS= -std=c++17 -Wall -Wextra -Werror

NAME= transport

$(NAME): main.o packet.o helpers.o
	$(CC) $(CFLAGS) main.o packet.o helpers.o -o $(NAME)
main.o: main.cpp
	$(CC) -c $(CFLAGS) main.cpp -o main.o
packet.o: packet.cpp packet.h
	$(CC) -c $(CFLAGS) packet.cpp -o packet.o
helpers.o: helpers.cpp helpers.h
	$(CC) -c $(CFLAGS) helpers.cpp -o helpers.o


clean: 
	rm -rf *o
distclean:
	rm -rf *o $(NAME)