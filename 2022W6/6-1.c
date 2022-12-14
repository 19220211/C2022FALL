#include<stdio.h>
int s(int n);
int mian()
{
	int n;
	scanf("%d", &n);
	printf("%d", s(n));
	return 0;
}
int s(int n)
{
	if (n == 1)
		return 1;
	else
	{
		if (n % 2 == 0)
			return s(n / 2) + n * n / 4;
		else
			return s(n - 1) + n;
	}
}