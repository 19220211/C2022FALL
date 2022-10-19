//https://www.acwing.com/blog/content/26489/
#include<stdio.h>
int main()
{
    int i, n, d[50];
    scanf("%d", &n);
    d[0] = 0;
    d[1] = 1;
    for (i = 0; i < n; i++)
        d[i + 2] = d[i + 1] + d[i];
    for (i = 0; i < n; i++)
        printf("%d ", d[i]);
    return 0;
}