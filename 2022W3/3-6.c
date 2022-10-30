#include<stdio.h>
int GCD_recursive(int m, int n);
int main()
{
	int m, n, c;
	scanf("%d%d", &m, &n);
	c = GCD_recursive(m, n);
	printf("%d", c);
	return 0;
}

int GCD_recursive(int m, int n)
{
	if (n > 0)
		return GCD_recursive(n, m % n);
	else
		return m;
}