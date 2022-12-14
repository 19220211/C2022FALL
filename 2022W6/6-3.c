#include<stdio.h>
int sum(int n);
int main() 
{
	int n;
	scanf("%d", &n);
	printf("%d", sum(n));
	return 0;
}
int sum(int n)
{
	int s = n;
	s && (s += sum(n - 1));
	return s;
}