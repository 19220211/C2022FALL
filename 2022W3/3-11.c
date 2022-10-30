//https://www.acwing.com/blog/content/27442/
#include<stdio.h>
int main()
{
    int n, x, a[100], i, s;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < n; i++)
    {
        for (x = 2, s = 1; x <= a[i] / x; x++)
        {
            if (a[i] % x == 0)
                s = s + x + a[i] / x;
        }
        if (s == a[i] && s != 1)
            printf("%d is perfect\n", a[i]);
        else
            printf("%d is not perfect\n", a[i]);
    }
    return 0;
}