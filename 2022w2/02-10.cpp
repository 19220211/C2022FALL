//https://www.acwing.com/blog/content/26484/
#include<stdio.h>
#include<math.h>
int main()
{
    int a, b, c, d;
    scanf("%d%d%d", &a, &b, &c);
    d = (a + b + fabs(a - b)) / 2;
    d = (c + d + fabs(c - d)) / 2;
    printf("%d eh o maior", d);
    return 0;
}