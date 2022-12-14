#include<stdio.h>
int bin_insert(int n, int m, int j, int i);
int main() 
{
	int n, m, j, i;
	scanf("%d%d%d%d", &n, &m, &j, &i);
	printf("%d", bin_insert(n, m, j, i));
	return 0;
}
int bin_insert(int n, int m, int j, int i)
{
	m = m << j;
	n = n | m;
	return n;
}