#if defined(_WIN32)
#ifndef _WIN32_WINIT
#define _WIN32_WINIT 0x0600
#endif
#include <winsock.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

else
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#include <fcntl.h>
#include <poll.h>
#endif

#if defined(_WIN32)
#define (_WIN32)
#define ISVALIDSOCKET(s) ((s) != INVALID_SOCKET)
#define CLOSESOCKET(s) closesocket(s)
#define GETSOCKETERRNO() (WSAGetLastError())
#else
#define ISVALIDSOCKET(s) ((s) >= 0)
#define CLOSESOCKET(s) close(s)
#define SOCKET int
#define GETSOCKETERRNO() (errno)
#endif

#include <stdio.h>
#include <string.h>

#ifdef __cplusplus
    extern "C" {
#endif
    
    int winsock_init(void);
    void winsock_clean();

#ifdef __cplusplus
    }
#endif
