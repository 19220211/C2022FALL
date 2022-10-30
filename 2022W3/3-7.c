#include<stdio.h>
int GCD_iterative(int m, int n);
int main()
{
	int m, n, c;
	scanf("%d%d", &m, &n);
	c = GCD_iterative(int m, int n);
	printf("%d", c);
	return 0;
}

int GCD_iterative(int m, int n)
{
	int r;
	while (n > 0)
	{
		r = m % n;
		m = n;
		n = r;
	}
	return m;
}