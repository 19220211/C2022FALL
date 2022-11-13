#include<stdio.h>
#include<string.h>
void my_strcpy(char* dest, const char* src);
int main()
{
	char dest[100],src[100];
	gets(src);
	my_strcpy(dest,src);
	return 0;
}

void my_strcpy(char* dest, const char* src)
{
	int i;
	char c;
	for (i = 0; i < strlen(src); i++)
		dest[i] = src[i];
	for (i = 0; i < strlen(src); i++)
	    printf("%c", dest[i]);
	printf("\0");
}