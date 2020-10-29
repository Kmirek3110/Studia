//Karol Mirek
//301650
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netinet/ip_icmp.h>
#include <unistd.h>
#include <stdbool.h>
#include <arpa/inet.h>
#include "icmp_send.h"
#include "icmp_receive.h"
#include <string>



int main(int argc, char** argv)
{	
	int max_ttl = 30;
	int pid = getpid();
	if (argc != 2) printf("Zla ilosc argumentow!\n");
	
	int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (sockfd < 0) {
		fprintf(stderr, "socket error: %s\n", strerror(errno)); 
		return EXIT_FAILURE;
	}	
	

	short seq[3] = {0,0,0};

	for(int ttl=1; ttl<=max_ttl; ttl++){

		seq[0]++;
		seq[1]++;
		seq[2]++;	

		if(setsockopt(sockfd, IPPROTO_IP, IP_TTL, &ttl, sizeof(int)) < 0){
			fprintf(stderr, "setsockopt error: %s\n", strerror(errno)); 
			return EXIT_FAILURE;
		}
		
		struct sockaddr_in recipient;
    	bzero (&recipient, sizeof(recipient));
    	recipient.sin_family = AF_INET;

    	if(inet_pton(AF_INET, argv[1], &recipient.sin_addr)!= 1){
        	fprintf(stderr, "inet_pton error: %s\n", strerror(errno)); 
        	exit(EXIT_FAILURE);
		}

		for(int i=0; i<3; i++){
			sendIcmpPackets(recipient, sockfd,  pid, seq[i]);
		}
		if(receive(sockfd, pid, ttl, argv[1]) == false)
			break;

	}
	if(close(sockfd) < 0) {
		fprintf(stderr, "close error: %s\n", strerror(errno)); 
		return EXIT_FAILURE;
	}	
	return EXIT_SUCCESS;
	
}
	