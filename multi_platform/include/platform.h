#ifndef PLATFORM_H
#define PLATFORM_H

#ifdef _WIN32
    #include <winsock2.h>
    #define CLOSESOCKET closesocket
#else
    #include <unistd.h>
    #define SOCKET int
    #define INVALID_SOCKET -1
    #define CLOSESOCKET close
#endif

#endif
