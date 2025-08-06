#include <sys/socket.h>
#include <stdio.h>
#include <netdb.h>
#include <stdlib.h>
#include <ifaddrs.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    struct ifaddrs *address_l;


    if (getifaddrs(&address_l) == -1)
    {
        perror("getifaddrs");
        return EXIT_FAILURE;
    }
    struct ifaddrs *address = address_l;

    while (address)
    {
        if (address->ifa_addr && address->ifa_addr->sa_family == AF_INET)
        {
            printf("Interface:%s\n", address->ifa_name);
            printf("Family: %d\n", address->ifa_addr->sa_family);

            char host_buff[INET_ADDRSTRLEN];
            int result = getnameinfo(
                    address->ifa_addr, 
                    sizeof(struct sockaddr_in), 
                    host_buff, 
                    sizeof(host_buff), 
                    NULL, 0, 
                    NI_NUMERICHOST
                );
            
            printf("\t%s", host_buff);
        }
        address = address->ifa_next;
    }
    freeifaddrs(address_l);

    return EXIT_SUCCESS;
    
}
