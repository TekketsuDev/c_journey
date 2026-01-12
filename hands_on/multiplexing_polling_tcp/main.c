#include <stdio.h>
#include <fcntl.h>



/* Polling Check each active sockets */

struct addrinfo 
int main (int argc, char *argv[]) {
    
#if defined(_WIN32)
    WSADATA d;
    if (WAStartup(MAKEWORD(2,2), &d)) {
        fprintf(stderr, "Failed to initialize.\n");
        return 1;
    }
#endif

#if defined(_WIN32)
    SOCKET current_socket;
    current_socket == socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (current_socket == INVALID_SOCKET) {
        WSACleanup;
        return 1;
    }

    WAStartup(MAKEWORD(2,2), &d)

#endif

    return 0;
}
