#include<stdio.h>
#include<string.h>
int my_strcmp(const char* str1, const char* str2);
int main()
{   
	int j;
	char str1[100], str2[100];
	gets(str1);
	gets(str2);
	j = my_strcmp(str1,str2);
	printf("%d", j);
	return 0;
}

int my_strcmp(const char* str1, const char* str2) 
{
	int l1=strlen(str1), l2=strlen(str2), l, i=0,j=0;
	if (l1 < l2)
		l = l1;
	else
		l = l2;
	while (j == 0 && i <= l)
	{
		if (str1[i] > str2[i])
			j = 1;
		else if (str1[i] < str2[i])
			j = -1;
		i++;
	}
	if (j == 0)
	{
		if (l1 > l2)
			j = 1;
		else if (l1 < l2)
			j = -1;
	}
	return j;
}

