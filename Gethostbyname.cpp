/*ʹ��inet_ntop������� ���� ���ʵ�λ�� ����� #define _WINSOCK_DEPRECATED_NO_WARNINGS 
�ļ�������ҳ���C>��Ԥ���������C>����_CRT_SECURE_NO_WARNINGS������
�ļ�������ҳ���C>c/c++��>���棬��SDL����Ϊ��
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
        printf("WSAStartup�޷���ʼ����");
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
    printf("��ʽ��������%s\n��ַ���ȣ�%d\n��ַ���ͣ�%d\n", host->h_name, host->h_length, host->h_addrtype);
    printf("�����ı����б����£�\n");
    for (temp = host->h_aliases; *temp != NULL; temp++)
    {
        printf("%s\n", *temp);
    }
    printf("������IP�б����£�\n");
    for (temp = host->h_addr_list; *temp != NULL; temp++)
    {
        printf("%s\n", inet_ntoa(*(struct in_addr*)(*temp)));
    }
    WSACleanup();
    return 0;
}

*/