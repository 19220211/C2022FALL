/*使用inet_ntop函数替代 或者 在适当位置 定义宏 #define _WINSOCK_DEPRECATED_NO_WARNINGS 
文件的属性页—–>“预处理器”–>将“_CRT_SECURE_NO_WARNINGS”加上
文件的属性页—–>c/c++—>常规，将SDL检查改为否
*/
/*
#include <winsock2.h>  
#include <ws2tcpip.h>  
#include <stdio.h>  
#include <stdlib.h>  
#include <iostream>  
#pragma comment(lib, "ws2_32.lib")  

#define _WINSOCK_DEPRECATED_NO_WARNINGS



int main()
{
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        printf("WSAStartup无法初始化！");
        return 0;
    }
    char** temp;
    const char* hostname = "image.baidu.com";

    struct hostent* host = gethostbyname(hostname);
    if (host == NULL) {
        printf("gethostbyname failed: %d\n", WSAGetLastError());
        WSACleanup();
        return 0;
    }
    printf("正式主机名：%s\n地址长度：%d\n地址类型：%d\n", host->h_name, host->h_length, host->h_addrtype);
    printf("主机的别名列表如下：\n");
    for (temp = host->h_aliases; *temp != NULL; temp++)
    {
        printf("%s\n", *temp);
    }
    printf("主机的IP列表如下：\n");
    for (temp = host->h_addr_list; *temp != NULL; temp++)
    {
        printf("%s\n", inet_ntoa(*(struct in_addr*)(*temp)));
    }
    WSACleanup();
    return 0;
}

*/