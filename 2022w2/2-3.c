#include<stdio.h>
#include<math.h>
int main()
{
	double x, a, b, c, m, n;
	scanf("%lf%lf%lf%lf", &x, &a, &b, &c);
	m = x * x * x + 2 * x * x + 3 * x + 1;
	n = sqrt(fabs(x)) != (4 * a) / (b * c);
	printf("%lf,%lf", m, n);
	return 0;
}