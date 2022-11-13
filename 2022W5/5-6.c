#include<stdio.h>
#include<string.h>
void k_reverse(char* str, int k);
int main()
{
	int k;
	char str[100];
	scanf("%d", &k);
	gets(str);
	k_reverse(str,k);
	return 0;
}


void k_reverse(char* str, int k)
{
	int l, i,j, n;
	char c;
	l = strlen(str);
	n = l / k;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < k/2; j++)
		{
			c = str[i * k + j];
			str[i * k + j] = str[(i + 1) * k - j - 1];
			str[(i + 1) * k - j - 1] = c;
		}
	}
	puts(str);
}