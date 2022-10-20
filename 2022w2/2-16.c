//https://www.acwing.com/blog/content/26490/
#include<stdio.h>
int main()
{
    int a, d[200], i, s;
    scanf("%d", &a);
    for (i = 0; i < 200; i++)
        scanf("%d", &d[i]);
    i = 0;
    while (d[i] <= 0)
        i++;
    s = (a + a + d[i] - 1) * d[i] / 2;
    printf("%d", s);
    return 0;
}