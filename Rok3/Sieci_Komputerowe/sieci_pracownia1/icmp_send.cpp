//Karol Mirek
//301650
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <netinet/ip_icmp.h>
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>
#include <assert.h>
#include "icmp_send.h"

u_int16_t compute_icmp_checksum (const void *buff, int length)
{
	u_int32_t sum;
	const u_int16_t* ptr = (u_int16_t *)buff;
	assert(length % 2 == 0);
	for (sum = 0; length > 0; length -= 2)
		sum += *ptr++;
	sum = (sum >> 16) + (sum & 0xffff);
	return (u_int16_t)(~(sum + (sum >> 16)));
}

void sendIcmpPackets(sockaddr_in &recipient, int sockfd, int pid, short try_n)
{
	icmp icmp_packet;
	icmp_packet.icmp_type = ICMP_ECHO;
	icmp_packet.icmp_code = 0;
	icmp_packet.icmp_hun.ih_idseq.icd_id = htons(pid);
    icmp_packet.icmp_hun.ih_idseq.icd_seq = htons(try_n);
    icmp_packet.icmp_cksum = 0;
    icmp_packet.icmp_cksum = compute_icmp_checksum (
        (u_int16_t*)&icmp_packet, sizeof(icmp_packet));

    ssize_t bytes_sent = sendto (
        sockfd,
        &icmp_packet,
        sizeof(icmp_packet),
        0,
        (struct sockaddr*)&recipient,
        sizeof(recipient)
    );
    
    if(bytes_sent < 0){
        fprintf(stderr, "sendto error: %s\n", strerror(errno)); 
        exit(EXIT_FAILURE);
        }
}
