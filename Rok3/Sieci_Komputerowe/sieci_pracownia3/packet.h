//karol_mirek
//301650

#ifndef PACKET_H
#define PACKET_H

#include "helpers.h"
using namespace std;
void send_packets(int sockfd, struct sockaddr_in *server_address, u_int32_t filesize);
void receive_packets(int sockfd, int port, string ip);
string get_request(u_int32_t start,u_int32_t len);


struct packet
{
	bool ready;
    int start;
	int	length;
	char data[1000];
};


#endif
