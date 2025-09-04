#include <errno.h>
#include <ifaddrs.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

float ping_interface(const char *interface_name, const char *target_ip);

int main(int argc, char *argv[]) {
  struct ifaddrs *address_l;

  if (getifaddrs(&address_l) == -1) {
    perror("getifaddrs");
    return EXIT_FAILURE;
  }
  struct ifaddrs *address = address_l;

  while (address) {
    if (address->ifa_addr && address->ifa_addr->sa_family == AF_INET) {

      if (strstr(address->ifa_name, "tun") != NULL) {

        printf("%s", address->ifa_name);
        char host_buff[INET_ADDRSTRLEN];
        int result =
            getnameinfo(address->ifa_addr, sizeof(struct sockaddr_in),
                        host_buff, sizeof(host_buff), NULL, 0, NI_NUMERICHOST);

        printf(",%s\n", host_buff);

        // Call from test_interface.c
        ping_interface(address->ifa_name, host_buff);
      }
      // printf("Family: %d\n", address->ifa_addr->sa_family);
    }
    address = address->ifa_next;
  }
  freeifaddrs(address_l);

  return EXIT_SUCCESS;
}
