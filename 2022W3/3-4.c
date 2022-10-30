#include<stdio.h>
int is_pow2(int n);
int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", is_pow2(n));
	return 0;
}

int is_pow2(int n)
{
	return !((n - 1) & n) - 1;
}