#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int a[1000],b[1000],c[1001], i, j,jw=0,n;
    scanf("%d", &n);
    srand(time(NULL));
    for (i = 0; i <n; i++)
    {
        a[i] = rand() % 10;
        b[i] = rand() % 10;
    }
    for (i = 0; i <n; i++)
    {
        c[i] = (a[i] + b[i] + jw) % 10;
        if (a[i] + b[i] + jw >= 10)
            jw = 1;
        else
            jw = 0;
    }
    c[n] = jw;
    for (i = n-1; i >=0; i--)
        printf("%d",a[i]);
        printf("\n");
    for (i =n-1; i >=0; i--)
        printf("%d", b[i]);
        printf("\n");
    for (i = n; i >=0; i--)
        printf("%d", c[i]);
        printf("\n");
    return 0;
}