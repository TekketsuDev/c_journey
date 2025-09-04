#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <net/if.h>
#include <ifaddrs.h>
#include <errno.h>

#define PACKET_SIZE 64
#define TIMEOUT 1

struct ping_pkt {
    struct icmphdr hdrd;
    char msg 
