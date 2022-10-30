#include<stdio.h>
int fac_bit_count(int n);
int main()
{
	int n,w;
	scanf("%d", &n);
	w= fac_bit_count(n);
	printf("%d", w);
	return 0;
}

int fac_bit_count(int n)
{
    int i, e = 1;
	double p = 1;
	for (i = 2; i <= n; i++)
	{
		p *= i;
		while (p >= 10) p /= 10.0, e++;
	}
	return e;
}