//https://www.acwing.com/blog/content/27812/
#include<stdio.h>
int Hanoia(int n, char s, char h1, char h2, char t);
int Hanoi(int n, char s, char h, char t);
int b = 0;
int main()
{
	int n, s;
	for (n = 1; n <= 12; n++)
	{
		s = Hanoia(n, 'A', 'B', 'C', 'D');
		printf("%d\n", s);
	}
	return 0;
}
int Hanoia(int n, char s, char h1, char h2, char t)
{
	int a = 0, min = 0, i;

	if (n == 1)
		a++;
	else if (n == 2)
		a = a + 3;
	else
	{
		min = 10000;
		for (i = 1; i < n - 1; i++)
		{
			b = 0;
			a = a + Hanoia(n - i - 1, s, h1, t, h2);
			b = 0;
			a = a + Hanoi(i, s, t, h1);
			a++;
			b = 0;
			a = a + Hanoi(i, h1, s, t);
			b = 0;
			a = a + Hanoia(n - i - 1, h2, s, h1, t);
			if (min > a)
				min = a;
			a = 0;
		}
	}
	min = a + min;
	return min;
}

int Hanoi(int n, char s, char h, char t)
{
	if (n == 1) b++;
	else
	{
		Hanoi(n - 1, s, t, h);
		b++;
		Hanoi(n - 1, h, s, t);
	}

	return b;
}