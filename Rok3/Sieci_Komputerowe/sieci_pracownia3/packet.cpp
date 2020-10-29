//karol_mirek
//301650

#include "packet.h"
#include<iostream>
using namespace std;

extern u_int32_t collected;
extern deque<packet> window;
void send_packets(int sockfd, struct sockaddr_in *server_address,u_int32_t filesize)
{   
        for (u_int32_t i = 0; i < window.size(); i++)
        {
            if (window[i].ready == false )
            {   
                u_int32_t request_length = min(1000, (int)(filesize - (collected + i) * 1000));
                char message[30];
                sprintf(message, "GET %d %d\n",(collected + i)* 1000, request_length);
		        ssize_t message_len = strlen(message);
                struct sockaddr_in server_len;
                if (sendto(sockfd, message, message_len, 0, (struct sockaddr*) server_address, sizeof(server_len)) != message_len) {
    	            fprintf(stderr, "sendto error: %s\n", strerror(errno));
    	            return;
                }
        
            }
        }
}

void prepere_datagram(string data)
{
    string data_string = data;
    int ile = 0;
    string  start_str, length_str;

    if(data_string.compare(0,4,"DATA") != 0)
        return;

    data_string.erase(0,5);
    
    for(char const &c: data_string)
    {
        if(c == ' ')
            break;
        start_str.push_back(c);
        ile++;
    }

    data_string.erase(0,ile+1);
    ile = 0;

    for(char const &c: data_string)
    {
        if(c == '\n')
            break;
        ile++;
        length_str.push_back(c);
    }

    data_string.erase(0,ile+1);

    u_int32_t start, length;

    start = atoi(start_str.c_str());
    length = atoi(length_str.c_str());
 
    int index = start / 1000 - collected;
    if (index < 0){
        return;
    }

    if (window[index].ready == false){
        copy(data_string.begin(), data_string.end(), window[index].data);
        window[index].start = start;
        window[index].length = length;
        window[index].ready = true;
    }
}

void receive_packets(int sockfd, int port, string ip){
    fd_set descriptors;
    FD_ZERO (&descriptors);
    FD_SET (sockfd, &descriptors);
    struct timeval tv; 
    tv.tv_sec  = 0;
    tv.tv_usec = 200000;

    for(;;){
        int ready = select (sockfd+1, &descriptors, NULL, NULL, &tv); 

        if (ready < 0){ 
            fprintf(stderr, "select error\n");
            break;
        }
        if (ready == 0)
            break;   

        struct sockaddr_in  sender; 
        socklen_t sender_len = sizeof(sender);
        char buffer[1101];

        ssize_t datagram_len = recvfrom (sockfd, buffer, 1101, 0, (struct sockaddr*)&sender, &sender_len);

        if (datagram_len < 0) {
            fprintf(stderr, "recvfrom error: %s\n", strerror(errno)); 
            break;
        }

        char sender_ip_str[20]; 
        if(inet_ntop(AF_INET, &(sender.sin_addr), sender_ip_str, sizeof(sender_ip_str)) == NULL){
            fprintf(stderr, "inet_ntop: %s\n", strerror(errno)); 
            exit(EXIT_FAILURE);
        }
        if(string(sender_ip_str)!= ip){
            continue;
        }

        if(port != ntohs(sender.sin_port)){
            continue;
        }
        prepere_datagram(string(buffer, datagram_len));
    }
    
}