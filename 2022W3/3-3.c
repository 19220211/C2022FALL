#include<stdio.h>
void print_hex(int a);
int main()
{
	int a;
	scanf("%d", &a);
	print_hex(a);
	return 0;
}

void print_hex(int a)
{
	char d[100];
	int n, b[100], i = 0, j;
	n=a;
	while (n > 0)
	{
		n= n/ 16;
		i++;
	}
	n = a;
	for (j = 0; j < i; j++)
	{
		b[j] = n % 16;
		n = n / 16;
	}
	for (j = 0; j < i; j++)
	{
		if (b[j] >= 0 && b[j] <= 9)
			d[j] = (char)(b[j] + 48);
		else
			d[j] = (char)(b[j] + 55);
	}
	for (j = i - 1; j >= 0; j--)
		printf("%c", d[j]);
}