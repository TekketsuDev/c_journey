#include <stdio.h>
#include "platform.h"
#include "sock_init.h"

int main(void) {
    SOCKET s = 0;
    (void)s;

    printf("Hello from %s SOCKET type 0 %s\n",
#ifdef _WIN32
            "Windows",
            "Socket (WinSock)"
#else
            "Linux",
            "int"
#endif
    );

//#ifdef _WIN32    
    sock_init();
//#endif
    return 0;
}
