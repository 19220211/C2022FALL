//https://www.acwing.com/blog/content/29078/
#include<stdio.h>
#include<math.h>
int main()
{
    int i, j, x[100000], y[100000], n, s = 0, c = 0, m = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d%d", &x[i], &y[i]);
    for (i = 0; i < n - 1; i++)
        s += abs(x[i] - x[i + 1]) + abs(y[i] - y[i + 1]);
    for (i = 0; i < n - 2; i++)
    {
        c += abs(x[i] - x[i + 1]) + abs(y[i] - y[i + 1]) + abs(x[i + 2] - x[i + 1]) + abs(y[i + 2] - y[i + 1]) - abs(x[i] - x[i + 2]) - abs(y[i] - y[i + 2]);
        if (c > m)
            m = c;
        c = 0;
    }
    printf("%d\n", s - m);
    return 0;
}