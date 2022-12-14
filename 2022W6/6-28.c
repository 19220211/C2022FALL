//https://www.acwing.com/blog/content/29075/
#include<stdio.h>
int main()
{
    int i, j, c[3], m[3], a, b;
    for (i = 0; i < 3; i++)
        scanf("%d%d", &c[i], &m[i]);
    for (i = 0; i < 100; i++)
    {
        {a = i % 3; b = (i + 1) % 3; }
        if (m[a] + m[b] <= c[b])
        {
            m[b] = m[a] + m[b];
            m[a] = 0;
        }
        else
        {
            m[a] = m[a] + m[b] - c[b];
            m[b] = c[b];
        }
    }
    for (i = 0; i < 3; i++)
        printf("%d\n", m[i]);
    return 0;
}