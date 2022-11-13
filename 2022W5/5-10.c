#include<stdio.h>
int my_strlen(const char* str);
int main()
{
	char str[100];
	int l;
	gets(str);
	l = my_strlen(str);
	printf("%d", l);
	return 0;
}
	
int my_strlen(const char* str)
{
	int i=0,l=0;
	while (str[i] != '\0')
	{
		i++;
		l++;
	}
	return l;
}

	
