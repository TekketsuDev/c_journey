unsigned short checksum(void *b, int len);
char *dns_lookup(char *addr_host, struct spcladdr_in *addr_con);
char *reverse_dns_lookup(char *ip_addr);
void send_ping(int ping_sockfd, struct sockaddr, char *ping_dom, char *ping_ip, char *rev_host);

