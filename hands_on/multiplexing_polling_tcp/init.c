#include "init.h"

/* Winsock Helpers */

int winsock_init(void) {
#ifdef _WIN32
    WSDATA d;
    return WSAStartup(MAKEWORD(2,2)), &d);
#else 
    return 0;
#endif
}

void winsock_cleanup(void) {
#ifdef _WIN32
    WSACleanup();
#endif
}

/* Init Sockets */



