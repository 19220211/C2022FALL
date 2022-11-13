#include<stdio.h>
int main()
{
	int n, i, j, t,s=0,a[20][20];
	scanf("%d", &n);
	for (i = 0; i <= n - 2; i = i + 2)
	{
		s = s + (n - i) * (n - i) - (n - i - 2) * (n - i - 2);
		a[i / 2 + 1][i / 2 + 1] = s + 1;
	}
	a[0][0] = 1;
	for (i = 0; i <= n - 2; i = i + 2)
	{
		j = i / 2 + 1;
		t = n - i - 1;
		while (t)
		{
			a[i / 2][j] = a[i / 2][j - 1] + 1;
			t--;
			j++;
		}
		j = i / 2 + 1;
		t = n - i - 1;
		while (t)
		{
			a[j][n - i / 2 - 1] = a[j - 1][n - i / 2 - 1] + 1;
			t--;
			j++;
		}
		j = i / 2 + 1;
		t = n - i - 1;
		while (t)
		{
			a[n - i / 2 - 1][n - j - 1] = a[n - i / 2 - 1][n - j] + 1;
			t--;
			j++;
		}
		j = i / 2 + 1;
		t = n - i - 1;
		while (t)
		{
			a[n - j - 1][i / 2] = a[n - j][i / 2] + 1;
			t--;
			j++;
		}
	}
	s = 0;
	for (i = 0; i <= n - 2; i = i + 2)
	{
		s = s + (n - i) * (n - i) - (n - i - 2) * (n - i - 2);
		a[i / 2 + 1][i / 2 + 1] = s + 1;
	}
	a[0][0] = 1;
	if (n % 2 == 0)
		a[n / 2][n / 2] = n * n - 1;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d\t", a[i][j]);
			if ((j+1)% n == 0)
				printf("\n");
		}
	}
	return 0;
}