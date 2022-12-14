//https://www.acwing.com/blog/content/28176/
#include<stdio.h>
int main()
{
    int b[1000002], e[1000002], x, y, i = 0, j, jl[1000001], lx = 0, ly = 0, m, n = 0, f = 1;
    char c;
    scanf("%d%d", &x, &y);
    b[0] = 0;
    e[0] = 0;
    for (i = 0; i < x + y; i++)
    {
        scanf("%d %c", &jl[i], &c);
        if (i < x)
        {
            if (c == 'R')
            {
                for (j = 0; j < jl[i]; j++)
                {
                    b[lx + 1] = b[lx] + 1;
                    lx++;
                }
            }
            else
            {
                for (j = 0; j < jl[i]; j++)
                {
                    b[lx + 1] = b[lx] - 1;
                    lx++;
                }
            }
        }
        else
        {
            if (c == 'R')
            {
                for (j = 0; j < jl[i]; j++)
                {
                    e[ly + 1] = e[ly] + 1;
                    ly++;
                }
            }
            else
            {
                for (j = 0; j < jl[i]; j++)
                {
                    e[ly + 1] = e[ly] - 1;
                    ly++;
                }
            }
        }
    }
    if (lx > ly)
    {
        m = lx;
        for (i = ly + 1; i <= m; i++)
            e[i] = e[ly];
    }
    else
    {
        m = ly;
        for (i = lx + 1; i <= m; i++)
            b[i] = b[lx];
    }
    for (i = 1; i <= m; i++)
    {
        if (b[i] == e[i])
        {
            if (f == 0)
            {
                n++;
                f = 1;
            }
        }
        else
            f = 0;
    }
    printf("%d", n);
    return 0;
}