//karol_mirek
//301650

#include "helpers.h"
#include "packet.h"
#include<arpa/inet.h>


using namespace std;

extern u_int32_t collected;
extern u_int32_t packets_to_get;
extern deque<packet> window;

u_int32_t how_many_packets(u_int32_t size)
{
	if(size < 1000)
		return 1;
	if(size%1000 == 0)
		return size/1000;
	return (size/1000)+1;
}

void window_setup()
{
	int window_size = min((u_int32_t) 700, packets_to_get);
	for (int i = 0; i < window_size; i++){
		packet input;
		input.ready = false;
		window.push_back(input);
	}
}

bool is_number(std::string str)
{
	string::const_iterator it = str.begin();
	while(it != str.end() && isdigit(*it)) ++it;
	return !str.empty() && it == str.end();
}

void valid_input(int length, char* argv[])
{
	if (length != 5)
	{
		fprintf(stderr, "Inncorect number of arguments.\n" );
		exit(EXIT_FAILURE);
	}
	string ip = string(argv[1]);
	string port = string(argv[2]);
	string size = string(argv[4]);

	struct sockaddr_in sa;
	
	if(inet_pton(AF_INET, ip.c_str(), &(sa.sin_addr)) != 1 )
	{
		fprintf(stderr,"Inncorect ip address");
		exit(EXIT_FAILURE);
	}
	if (!is_number(port))
	{
		fprintf(stderr, "Port must be a number.\n");
		exit(EXIT_FAILURE);
	}
	if (!is_number(size))
	{
		fprintf(stderr, "Filesize must be a positive number.\n");
		exit(EXIT_FAILURE);
	}

	int size_i = atoi(size.c_str());

	if(size_i>10001000){
		fprintf(stderr, "File size is too big. Max size is 10001000 bytes\n"); 
		exit(EXIT_FAILURE);
	}

}


void write_to_file(string filename)
{
	while(window.empty() == false)
	{
		packet packet = window.front();
		if(packet.ready == true)
		{
			ofstream out(filename, ofstream::binary | ofstream::app);
			out.write(packet.data, packet.length);
			out.close();
			window.pop_front();
			collected ++;
			packets_to_get --;
			if (window.size() < packets_to_get)
			{
				packet.ready = false;
				window.push_back(packet);
			}
		}
		 else 
		{
			break;
		}
	}
}