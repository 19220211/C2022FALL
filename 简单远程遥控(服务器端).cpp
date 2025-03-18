/*
#include <winsock2.h>  
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <io.h>  
#include <direct.h>  

#pragma comment(lib, "Ws2_32.lib")  

#define PORT 12345  
#define BUFFER_SIZE 1024
#define MAX_PATH 260  

#define _CRT_SECURE_NO_WARNINGS


void handle_command(SOCKET client_socket, char* command) {
    char args[3][BUFFER_SIZE];  // 创建一个二维字符数组来存储参数  
    int argc = sscanf(command, "%1023s %1023s %1023s", args[0], args[1], args[2]);

    // 打印解析出的参数，用于调试  
    printf("argc: %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("args[%d]: %s\n", i, args[i]);
    }

    if (strcmp(args[0], "put") == 0 && argc == 3) {
        FILE* local_file = fopen(args[1], "rb");
        if (local_file == NULL) {
            send(client_socket, "Error: Cannot open local file\n", strlen("Error: Cannot open local file\n"), 0);
            return;
        }
        FILE* remote_file = fopen(args[2], "wb");
        if (remote_file == NULL) {
            fclose(local_file);
            send(client_socket, "Error: Cannot create remote file\n", strlen("Error: Cannot create remote file\n"), 0);
            return;
        }
        char buffer[BUFFER_SIZE];
        size_t bytes_read;
        while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, local_file)) > 0) {
            send(client_socket, buffer, bytes_read, 0);
            fwrite(buffer, 1, bytes_read, remote_file);
        }
        fclose(local_file);
        fclose(remote_file);
        send(client_socket, "File transfer complete\n", strlen("File transfer complete\n"), 0);
    }
    else if (strcmp(args[0], "get") == 0 && argc ==3) {
        FILE* remote_file = fopen(args[1], "rb");
        if (remote_file == NULL) {
            send(client_socket, "Error: Cannot open remote file\n", strlen("Error: Cannot open remote file\n"), 0);
            return;
        }
        FILE* local_file = fopen(args[2], "wb");
        if (local_file == NULL) {
            fclose(remote_file);
            send(client_socket, "Error: Cannot create local file\n", strlen("Error: Cannot create local file\n"), 0);
            return;
        }
        char buffer[BUFFER_SIZE];
        size_t bytes_read;
        while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, remote_file)) > 0) {
            send(client_socket, buffer, bytes_read, 0); // Echo the data back to client for verification (optional)  
            fwrite(buffer, 1, bytes_read, local_file);
        }
        fclose(remote_file);
        fclose(local_file);
        send(client_socket, "File transfer complete\n", strlen("File transfer complete\n"), 0);
    }
    else if (strcmp(args[0], "dir") == 0 && argc == 2) {
        WIN32_FIND_DATA findFileData;
        wchar_t wArgs1[BUFFER_SIZE];
        MultiByteToWideChar(CP_ACP, 0, args[1], -1, wArgs1, BUFFER_SIZE);
        wcscat(wArgs1, L"\\*");  // 添加通配符以匹配所有文件和文件夹  

        HANDLE hFind = FindFirstFile(wArgs1, &findFileData);
        if (hFind == INVALID_HANDLE_VALUE) {
            send(client_socket, "Error: Invalid directory\n", strlen("Error: Invalid directory\n"), 0);
            return;
        }
        else {
            do {
                char filename[MAX_PATH];
                strcpy(filename, args[1]);

                // 检查是否是当前目录或上级目录，并跳过它们  
                if (wcscmp(findFileData.cFileName, L".") == 0 || wcscmp(findFileData.cFileName, L"..") == 0) {
                    continue;  // 跳过当前目录和上级目录  
                }

                if (strcmp(args[1], ".") != 0 && strcmp(args[1], "..") != 0) {
                    strcat(filename, "\\");
                }

                char convertedFileName[MAX_PATH];
                wcstombs(convertedFileName, findFileData.cFileName, MAX_PATH);
                strcat(filename, convertedFileName);

                // 检查是文件还是文件夹  
                if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
                    strcat(filename, "\\");
                    send(client_socket, filename, strlen(filename), 0);
                    send(client_socket, " <DIR>\n", strlen(" <DIR>\n"), 0);
                }
                else {
                    char fileType[10];
                    if (strstr(convertedFileName, ".exe")) strcpy(fileType, "EXE");
                    else if (strstr(convertedFileName, ".txt")) strcpy(fileType, "TXT");
                    else strcpy(fileType, "???");  // 未知类型  

                    char fullOutput[MAX_PATH + 10];
                    snprintf(fullOutput, sizeof(fullOutput), "%s %s\n", filename, fileType);
                    send(client_socket, fullOutput, strlen(fullOutput), 0);
                }
            } while (FindNextFile(hFind, &findFileData) != 0);
            FindClose(hFind);
            send(client_socket, "directory\n", strlen("directory\n"), 0);
        }
    }
    else if (strcmp(args[0], "quit") == 0) {
        send(client_socket, "quit\n", strlen("quit\n"), 0);
    }
    else {
        send(client_socket, "Unknown command\n", strlen("Unknown command\n"), 0);
    }
}

int main() {
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    SOCKET server_socket = socket(AF_INET, SOCK_STREAM, 0);
    SOCKADDR_IN server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (SOCKADDR*)&server_addr, sizeof(server_addr));
    listen(server_socket, 5);

    printf("TCP Server start…\n");
    sockaddr_in addrClient;
    int addrClientlen = sizeof(addrClient);
       
    SOCKET client_socket = accept(server_socket, (sockaddr FAR*)&addrClient, &addrClientlen);

    char buffer[BUFFER_SIZE];
    while (1) {
        ZeroMemory(buffer, BUFFER_SIZE);
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE - 1, 0);
        if (bytes_received <= 0) break;
        buffer[bytes_received] = '\0';

        SYSTEMTIME st;
        GetLocalTime(&st);
        char sDataTime[30];
        sprintf(sDataTime, "%4d-%2d-%2d %2d:%2d:%2d", st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);
        printf("%s,Recv From Client [%s:%d] :%s\n", sDataTime, inet_ntoa(addrClient.sin_addr), addrClient.sin_port, buffer);
        handle_command(client_socket, buffer);
    }

    closesocket(client_socket);
    closesocket(server_socket);
    WSACleanup();
    return 0;
}
*/

