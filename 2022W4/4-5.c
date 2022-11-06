//https://www.acwing.com/blog/content/27813/
#include<stdio.h>
int zha(int, int);
int zhb(int, int, int);
int main()
{
	int a, b, c, i, j = 0, k, n, q[100], w[100], e[100], s = 0;
	scanf("%d", &n);
	for (a = 0; a <= 6; a++)
	{
		for (b = 0; b <= 10; b++)
		{
			for (c = 0; c <= 20; c++)
			{
				if (3 * a + 2 * b + c == n)
				{
					j++;
					q[j] = a;
					w[j] = b;
					e[j] = c;
				}
			}
		}
	}
	for (i = 1; i <= j; i++)
	{
		if (q[i] == 0 && w[i] == 0 && e[i] != 0 || q[i] == 0 && w[i] != 0 && e[i] == 0 || q[i] != 0 && w[i] == 0 && e[i] == 0)
			s++;
		else if (q[i] == 0 && w[i] != 0 && e[i] != 0)
			s = s + zha(w[i], e[i]);
		else if (q[i] != 0 && w[i] != 0 && e[i] == 0)
			s = s + zha(w[i], q[i]);
		else if (q[i] != 0 && w[i] == 0 && e[i] != 0)
			s = s + zha(q[i], e[i]);
		else
			s = s + zhb(q[i], w[i], e[i]);
	}
	printf("%d", s);
}

int zha(int m, int n)
{
	int t;
	if (m < n)
	{
		t = m;
		m = n;
		n = t;
	}
	if (n == 1)
		t = m + 1;
	else if (n == 2)
		t = m + 1 + (m + 1) * m / 2;
	else if (n == 3)
		t = m + 1 + (m + 1) * m + (m + 1) * m * (m - 1) / 6;
	else if (n == 4)
		t = m + 1 + (m + 1) * m * 3 / 2 + (m + 1) * m * (m - 1) / 2 + (m + 1) * m * (m - 1) * (m - 2) / 24;
	else if (n == 5)
		t = m + 1 + 2 * (m + 1) * m + (m + 1) * m * (m - 1) + (m + 1) * m * (m - 1) * (m - 2) / 6 + (m + 1) * m * (m - 1) * (m - 2) * (m - 3) / 120;
	else
		t = m + 1 + (m + 1) * m * 5 / 2 + (m + 1) * m * (m - 1) * 5 / 3 + (m + 1) * m * (m - 1) * (m - 2) * 5 / 12 + (m + 1) * m * (m - 1) * (m - 2) * (m - 3) / 24 + (m + 1) * m * (m - 1) * (m - 2) * (m - 3) * (m - 4) / 720;
	return t;
}

int zhb(int f, int g, int h)
{
	int y;
	if (f < g)
	{
		y = f;
		f = g;
		g = y;
	}
	if (g < h)
	{
		y = g;
		g = h;
		h = y;
	}
	if (f < g)
	{
		y = f;
		f = g;
		g = y;
	}
	y = zha(f, g) * zha(f + g, h);
	return y;
}