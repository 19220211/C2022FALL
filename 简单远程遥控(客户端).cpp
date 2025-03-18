/*
#include <winsock2.h>  
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <string>
#include <iostream>
#include <ctime>

#pragma comment(lib, "Ws2_32.lib")  

#define SERVER_IP "127.0.0.1"  
//#define SERVER_IP "10.20.42.61"
#define PORT 12345  
#define BUFFER_SIZE 1024

void send_command(SOCKET socket, char* command) {
    send(socket, command, strlen(command), 0);
    char response[BUFFER_SIZE];
    int bytes_received=0;
    printf("Recv From Server:\n");
    while (bytes_received != SOCKET_ERROR) {
        bytes_received = recv(socket, response, BUFFER_SIZE - 1, 0);
        if (bytes_received == 0 || bytes_received == WSAECONNRESET) {
            break;
        }
        response[bytes_received] = '\0';
        printf("%s", response);
        if (strstr(response, "File transfer complete\n") != NULL|| strstr(response, "directory\n") != NULL|| strstr(response, "quit\n") != NULL|| strstr(response, "Unknown command\n") != NULL)
            break;
    }
}

int main() {
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
    SOCKET socket = ::socket(AF_INET, SOCK_STREAM, 0);
    SOCKADDR_IN server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    connect(socket, (SOCKADDR*)&server_addr, sizeof(server_addr));
    char command[BUFFER_SIZE];
    while (1) {
        printf("\nEnter command: ");
        fgets(command, BUFFER_SIZE, stdin);
        command[strcspn(command, "\n")] = '\0';  // Remove newline character  
        send_command(socket, command);
        if (strcmp(command, "quit") == 0) {
                      break;
        }
    }
    closesocket(socket);
    WSACleanup();
    return 0;
}

*/