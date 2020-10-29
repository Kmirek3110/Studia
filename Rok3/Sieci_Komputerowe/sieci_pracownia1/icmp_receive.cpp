//Karol Mirek
//301650

#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <netinet/ip_icmp.h>
#include <stdbool.h>
#include <string.h>
#include "icmp_receive.h"
#include <string>
#include <sys/time.h>
#include <iostream>


struct packet rec_pack(int sockfd, int pid){

    struct sockaddr_in sender;
    socklen_t sender_len = sizeof(sender);
    u_int8_t buffer[IP_MAXPACKET + 1];

    int packet_len = recvfrom (sockfd, buffer, IP_MAXPACKET, 0, (struct sockaddr*)&sender, &sender_len);

    if (packet_len < 0)
    {
        struct packet rec = {-99, -99, -99, "brak"};
        return rec;
    }

    char sender_ip[20];
    inet_ntop(AF_INET, &(sender.sin_addr), sender_ip, sizeof(sender_ip));
    struct ip* ip_header = (struct ip*) buffer;
	ssize_t ip_header_len = 4 * ip_header->ip_hl;
    struct icmp* icmp_header = (struct icmp*) (buffer + ip_header_len);
    
    if(icmp_header -> icmp_type == ICMP_TIME_EXCEEDED)
    {
        struct ip* helper_id_header = (struct ip*) ((ssize_t)(void*)icmp_header + (ssize_t)sizeof(struct icmphdr));
        ssize_t helper_id_header_len = 4 * helper_id_header->ip_hl;
        icmp_header = (struct icmp*) ((ssize_t)(void*)helper_id_header  + helper_id_header_len);

        int ident = ntohs(icmp_header -> icmp_hun.ih_idseq.icd_id);
        int seq = ntohs(icmp_header -> icmp_hun.ih_idseq.icd_seq);

        if (ident == pid)
        {
            struct packet rec = {pid, seq, ICMP_TIME_EXCEEDED, sender_ip};
            return rec;
        }
    }
    else if (icmp_header->icmp_type == ICMP_ECHOREPLY && ntohs(icmp_header -> icmp_hun.ih_idseq.icd_id)== pid)
    {
        int seq = ntohs(icmp_header -> icmp_hun.ih_idseq.icd_seq);
        struct packet rec = {pid, seq, ICMP_ECHOREPLY, sender_ip};
        return rec;
    }
    struct packet rec = {-99, -99, -99, "brak"};
    return rec;
}

bool Finished(std::string sender, std::string ip)
{
    if(sender.compare(ip)!=0)
    {
        return false;
    }
    return true;
}

void output(int time, char ip[3][20]) {

    if(time == -2)
        printf("*\n");
    else 
    {
        printf("%s", ip[0]);
        if (strcmp(ip[0],ip[1]) != 0)
            printf(" %s", ip[1]);
        if (strcmp(ip[0],ip[2]) != 0 && strcmp(ip[1],ip[2]) != 0)
            printf(" %s", ip[2]);
    }
    if(time==-1)
        printf("   ???\n");
    else if(time >= 0) 
        printf("   %d ms\n", time);
    }

bool receive(int sockfd, int id_num, int ttl, char final[20]){
 
    fd_set descriptors;
    FD_ZERO (&descriptors);
    FD_SET (sockfd, &descriptors);

    char rec_ip[3][20]={"", "" ""};
    int answers = 0,total_time = 0;
    int avg_time;

    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    
    while(answers < 3)
    {
		int ready = select(sockfd+1, &descriptors, NULL, NULL, &timeout);

        if (ready < 0) 
        {
			fprintf(stderr, "select error: %s\n", strerror(errno)); 
            exit(EXIT_FAILURE);
		}
        if(ready==0)
            break; 

        struct packet packet = rec_pack(sockfd, id_num);   
        if (packet.id == id_num && (packet.error == 0 || packet.error == 11) && packet.seq  == ttl)
        {   
            total_time += 1000000 - timeout.tv_usec;      
            strcpy(rec_ip[packet.seq % 3],packet.IP.c_str());
            answers++;
        }                     
    }
    if (answers == 3)
    {
        avg_time = total_time / 3000;
        
    }
    else
    {
        if (answers == 0)
        {
            avg_time = -2;  
        }
        else
        {
            avg_time = -1; 
        }   
    }

    output(avg_time, rec_ip);

    for(int i=0; i<3; i++)
    {   
        if (Finished(rec_ip[i], final)==true)
        {
            return false;
        }
    }
    return true;
}
