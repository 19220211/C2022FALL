//https://www.acwing.com/blog/content/28175/
#include<stdio.h>
int q(int, int);
int n, l = 0, a[101], b[101], c[101];
int main()
{
    int i, j, s = 0, max = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < n; i++)
        scanf("%d", &b[i]);
    for (i = 0; i < n; i++)
        c[i] = 0;
    for (i = 0; i < n; i++)
    {
        if (c[i] == 0)
        {
            for (j = 0; j < n; j++)
            {
                if (a[i] == b[j] && i != j)
                {
                    l++;
                    l = q(j, i);
                }
                else if (a[i] == b[j] && i == j)
                {
                    l = 1;
                    s--;
                }
            }
            if (l > max)
                max = l;
            l = 0;
            s++;
        }
    }

    if (s <= 0)
        max = -1;
    printf("%d %d", s, max);
    return 0;
}

int q(int j, int i)
{
    int t;
    for (t = 0; t < n; t++)
    {
        if (a[j] == b[t])
        {
            c[j] = 1;
            if (t == i)
            {
                l++;
                return l;
            }
            else
            {
                l++;
                return q(t, i);
            }
        }

    }
}