//Karol Mirek
//301650

#ifndef __ICMP_SEND_H
#define __ICMP_SEND_H


u_int16_t compute_icmp_checksum (const void *buff, int length);
void sendIcmpPackets(sockaddr_in &recipient, int sockfd, int id_num, short try_n);



#endif