//karol_mirek
//301650

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <string>
#include <deque>
#include <fstream>
#include "helpers.h"
#include "packet.h"

using namespace std;

u_int32_t collected;
u_int32_t packets_to_get;
deque<packet> window;

int main (int argc, char* argv[])
{
	valid_input(argc, argv);

	string ip = string(argv[1]);
	int port = atoi(argv[2]);
	string output_name = argv[3];
	u_int32_t size = atoi(argv[4]);

	packets_to_get = how_many_packets(size);

	int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sockfd < 0) {
		fprintf(stderr, "socket error: %s\n", strerror(errno)); 
		return EXIT_FAILURE;
	}
	struct sockaddr_in server_address;
	bzero (&server_address, sizeof(server_address));
	server_address.sin_family      = AF_INET;
	server_address.sin_port        = htons(port);
	inet_pton(AF_INET, ip.c_str(), &server_address.sin_addr);
	
	collected = 0;
	window_setup();


	ofstream out(output_name, ofstream::binary);
	out.close();

	while(packets_to_get != 0)
	{
		send_packets(sockfd, &server_address, size);
		receive_packets(sockfd, port, ip);
		write_to_file(output_name);	
	}
	return EXIT_SUCCESS;
}
