#include<stdio.h>
#include<string.h>
void reverse(char* str);
int main()
{
	char s1[100];
	scanf("%s", s1);
	reverse(s1);
	return 0;
}

void reverse(char* str)
{
	int l = strlen(str), i;
	for (i = 0; i < l; i++)
		printf("%c", str[l - i - 1]);
}