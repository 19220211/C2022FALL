//https://www.acwing.com/blog/content/29074/
#include<stdio.h>
int main()
{
    int a[4], b[4], i, j;
    for (i = 0; i < 4; i++)
        scanf("%d%d", &b[i], &a[i]);
    printf("%d\n", a[1] + a[2] + a[3] - b[1] - b[2] - b[3]);
    printf("%d\n", a[2] + a[3] - b[2] - b[3]);
    printf("%d\n", a[3] - b[3]);
    return 0;
}