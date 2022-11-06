//https://www.acwing.com/blog/content/27819/
#include<stdio.h>
int main()
{
    int i;
    float a[100];
    for (i = 0; i < 100; i++)
        scanf("%f", &a[i]);
    for (i = 0; i < 100; i++)
    {
        if (a[i] - 10 < 1e-6)
            printf("A[%d] = %.1f\n", i, a[i]);
    }
    return 0;
}