#Karol Mirek
#301650

CC= g++

CFLAGS= -std=c++17 -Wall -Wextra -Werror

NAME= traceroute

$(NAME): main.o icmp_receive.o icmp_send.o
	$(CC) $(CFLAGS) main.o icmp_receive.o icmp_send.o -o $(NAME)
main.o: main.cpp
	$(CC) -c $(CFLAGS) main.cpp -o main.o
icmp_receive.o: icmp_receive.cpp icmp_receive.h
	$(CC) -c $(CFLAGS) icmp_receive.cpp -o icmp_receive.o
icmp_send.o: icmp_send.cpp icmp_send.h
	$(CC) -c $(CFLAGS) icmp_send.cpp -o icmp_send.o

clean: 
	rm -rf *o
distclean:
	rm -rf *o $(NAME)