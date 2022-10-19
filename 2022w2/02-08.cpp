#include <stdio.h>
#include <time.h>
#include<math.h>
int main() {
	clock_t start_clock, end_clock;
	double elapsed_time;
	int i;
	start_clock = clock();

	for (i = 1; i <= 2; ++i)
	{
		    unsigned long int a, b, c, d;
			scanf("%ld%ld%ld", &a, &b, &c);
				if (b % 2 == 0)
				{
					(long double)a;
					(long double)b;
					d = (unsigned long int)pow(a * a, b / 2);
				}
				else
				{
					(long double)a;
					(long double)b;
					d = (unsigned long int)pow(a * a, (b - 1) / 2) * a;
				}
			  d = d % c;
			  printf("%ld\n", d);
	}
		end_clock = clock();
	elapsed_time = (double)(end_clock - start_clock) / CLOCKS_PER_SEC;
	printf("%.6lf", elapsed_time);
	return 0;
}