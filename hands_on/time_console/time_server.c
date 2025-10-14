#if defined(_WIN32)
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0600
#endif
#include <winsock.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")
#else
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#endif

#if defined(_WIN32)
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
#include <time.h>


//typdef struct AddrInfo
int main() {

#if defined(_WIN32)
    WSADATA d;
    if (WSAStartup(MAKEWORD(2, 2), &d)) {
        fprintf(stderr, "Failed to initialize.\n");
        return 1;
    }
#endif

    printf("Configuring local address...\n");
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    struct addrinfo *bind_address;
    getaddrinfo(0, "8080", &hints, &bind_address);

    // Create Socket
    printf("Creating socket...\n");
    SOCKET socket_listen;
    socket_listen = socket(
            bind_address->ai_family,
            bind_address->ai_socktype,
            bind_address->ai_protocol);

    if (!ISVALIDSOCKET(socket_listen)) {
        fprintf(stderr, "socket() failed, (%d)\n", GETSOCKETERRNO());
        return 1;
    }

    // Bind Socket
    printf("Creating socket...\n");
    if (bind(socket_listen,bind_address->ai_addr, bind_address->ai_addrlen)) {
        fprintf(stderr, "bind() failed, (%d)\n", GETSOCKETERRNO());
        return 1;
    }
    freeaddrinfo(bind_address);

    //Listen Socket
    printf("Listening ...\n");

    int SYS_MAXCONN = 
#ifdef _WIN32
        SOMAXCONN;
#else
        4096;
#endif

    if (listen(socket_listen, SYS_MAXCONN) < 0) {
        fprintf(stderr,"listen() failed. (%d)\n", GETSOCKETERRNO());
        return 1;
    }

    // Wait for connection 
    printf("Waiting for connection...\n");
    struct sockaddr_storage client_address;
    socklen_t client_len = sizeof(client_address);
    SOCKET socket_client = accept(
            socket_listen, 
            (struct sockaddr*) &client_address, 
            &client_len);

    if(!ISVALIDSOCKET(socket_client)) {
        fprintf(stderr, "accept() failed. (%d)\n", GETSOCKETERRNO());
        return 1;
    }

    //Client Accepts
    printf("Client is connected..");
    char address_buffer[100];
    getnameinfo((struct sockaddr*)&client_address,
            client_len,
            address_buffer,
            sizeof(address_buffer), 0, 0,
            NI_NUMERICHOST);
    printf("%s\n", address_buffer);

    //Read Request
    printf("Reading request...\n");
    char request[1024];
    int bytes_recived = recv(socket_client,
            request,
            1024,
            0);
    printf("Recived %d bytes.\n", bytes_recived);

    //Send response
    
    ///Generate Header
    const char *header =
        "HTTP/1.1 200 OK\r\n"
        "Connection: close\r\n"
        "Context-Type: text/plain; charset=utf-8\r\n"
        "Transfer-Encoding: chunked\r\n"
        "Cache-Control: no-cache\r\n"
        "\r\n";

    printf("Setting Headers...\n");
    send(socket_client,header, (int)strlen(header),0);

    for (int i = 0; i < 10; i++) {
    sleep(1);

    time_t timer; time(&timer);
    char *time_msg = ctime(&timer);   // incluye '\n' al final

    char line[160];
    int n = snprintf(line, sizeof(line), "Local time is: %s", time_msg);
    if (n < 0) break;

    // tamaño del chunk en HEX, sin espacios ni signos
    char chunk_hdr[32];
    int ch = snprintf(chunk_hdr, sizeof(chunk_hdr), "%X\r\n", (unsigned)n);

    // Orden exacto: tamaño\r\n + datos + \r\n
    send(socket_client, chunk_hdr, ch, 0);
    send(socket_client, line, n, 0);
    send(socket_client, "\r\n", 2, 0);
}

// 3) Fin de chunks
send(socket_client, "0\r\n\r\n", 5, 0); 
   
    printf("Closing connection..\n");
    CLOSESOCKET(socket_client);

    printf("Closing listening socket...\n");
    CLOSESOCKET(socket_listen);

#if defined(_WIN32)
    WSACleanup();
#endif

    printf("Fineshed.\n");
    return 0;
}
