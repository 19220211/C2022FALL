#include<stdio.h>
int add(int n1, int n2);
int main()
{
	int m, n;
	scanf_s("%d%d", &m, &n);
	printf("%d", add(m, n));
	return 0;
}
int add(int n1, int n2)
{
	while (n2 != 0)
	{
		int t = n1 ^ n2;
		n2 = (n1 & n2) << 1;
		n1 = t;
	}
	return n1;
}