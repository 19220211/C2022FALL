//https://www.acwing.com/blog/content/29076/
#include<stdio.h>
#include<math.h>
int main()
{
    int i, j, c, d, x[100], y[100], n, a, b, s = 0, m = 0, t;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d%d", &x[i], &y[i]);
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (x[i] == x[j])
            {
                b = abs(y[i] - y[j]);
                for (c = 0; c < n; c++)
                {
                    if (x[c] != x[i] && x[c] != x[j] && (y[c] == y[i] || y[c] == y[j]))
                    {
                        a = abs(x[c] - x[i]);
                        s = a * b;
                    }
                    if (s > m)
                        m = s;
                }
            }
        }
    }
    printf("%d\n", m);
    return 0;
}