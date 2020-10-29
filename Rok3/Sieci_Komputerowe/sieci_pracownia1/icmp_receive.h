//Karol Mirek
//301650
#ifndef __ICMP_RECEIVE_H
#define __ICMP_RECEIVE_H
#include <string>
bool receive(int sockfd, int id_num, int ttl, char final_ip[20]);
struct packet rec_pack(int sockfd, int pid);
struct packet {
        int id;
        int seq;
        int error;
        std::string IP;
};
void output(int time, char sender[3][20]);
bool Finished(std::string sender, std::string ip);
#endif