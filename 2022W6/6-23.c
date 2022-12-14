//https://www.acwing.com/blog/content/29071/
#include<stdio.h>
#include<string.h>
int main()
{
    int i = 0, j, x, y, fx, c = 0, m = 0, N, M;
    char a[1000][1000], s[1000];
    scanf("%d%d", &N, &M);
    for (i = 0; i < N; i++)
    {
        scanf("%s", s);
        strcpy(a[i], s);
    }
    {i = 0; fx = 1; }
    for (j = 0; j < M; j++)
    {
        {x = j; y = i; }
        while (0 <= x && x < M && 0 <= y && y < N)
        {
            if (a[y][x] == '/')
            {
                if (fx == 1)
                {
                    x--; c++; fx = 4;
                }
                else if (fx == 2)
                {
                    x++; c++; fx = 3;
                }
                else if (fx == 3)
                {
                    y--; c++; fx = 2;
                }
                else
                {
                    y++; c++; fx = 1;
                }
            }
            else
            {
                if (fx == 1)
                {
                    x++; c++; fx = 3;
                }
                else if (fx == 2)
                {
                    x--; c++; fx = 4;
                }
                else if (fx == 3)
                {
                    y++; c++; fx = 1;
                }
                else
                {
                    y--; c++; fx = 2;
                }
            }
        }
        if (c > m)
            m = c;
        c = 0;
        fx = 1;
    }
    {i = N - 1; fx = 2; }
    for (j = 0; j < M; j++)
    {
        {x = j; y = i; }
        while (0 <= x && x < M && 0 <= y && y < N)
        {
            if (a[y][x] == '/')
            {
                if (fx == 1)
                {
                    x--; c++; fx = 4;
                }
                else if (fx == 2)
                {
                    x++; c++; fx = 3;
                }
                else if (fx == 3)
                {
                    y--; c++; fx = 2;
                }
                else
                {
                    y++; c++; fx = 1;
                }
            }
            else
            {
                if (fx == 1)
                {
                    x++; c++; fx = 3;
                }
                else if (fx == 2)
                {
                    x--; c++; fx = 4;
                }
                else if (fx == 3)
                {
                    y++; c++; fx = 1;
                }
                else
                {
                    y--; c++; fx = 2;
                }
            }
        }
        if (c > m)
            m = c;
        c = 0;
        fx = 2;
    }
    {j = 0; fx = 3; }
    for (i = 0; i < N; i++)
    {
        {x = j; y = i; }
        while (0 <= x && x < M && 0 <= y && y < N)
        {
            if (a[y][x] == '/')
            {
                if (fx == 1)
                {
                    x--; c++; fx = 4;
                }
                else if (fx == 2)
                {
                    x++; c++; fx = 3;
                }
                else if (fx == 3)
                {
                    y--; c++; fx = 2;
                }
                else
                {
                    y++; c++; fx = 1;
                }
            }
            else
            {
                if (fx == 1)
                {
                    x++; c++; fx = 3;
                }
                else if (fx == 2)
                {
                    x--; c++; fx = 4;
                }
                else if (fx == 3)
                {
                    y++; c++; fx = 1;
                }
                else
                {
                    y--; c++; fx = 2;
                }
            }
        }
        if (c > m)
            m = c;
        c = 0;
        fx = 3;
    }
    {j = M - 1; fx = 4; }
    for (i = 0; i < N; i++)
    {
        {x = j; y = i; }
        while (0 <= x && x < M && 0 <= y && y < N)
        {
            if (a[y][x] == '/')
            {
                if (fx == 1)
                {
                    x--; c++; fx = 4;
                }
                else if (fx == 2)
                {
                    x++; c++; fx = 3;
                }
                else if (fx == 3)
                {
                    y--; c++; fx = 2;
                }
                else
                {
                    y++; c++; fx = 1;
                }
            }
            else
            {
                if (fx == 1)
                {
                    x++; c++; fx = 3;
                }
                else if (fx == 2)
                {
                    x--; c++; fx = 4;
                }
                else if (fx == 3)
                {
                    y++; c++; fx = 1;
                }
                else
                {
                    y--; c++; fx = 2;
                }
            }
        }
        if (c > m)
            m = c;
        c = 0;
        fx = 4;
    }
    printf("%d", m);
    return 0;
}