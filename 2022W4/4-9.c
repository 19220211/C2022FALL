//https://www.acwing.com/blog/content/27817/
#include<stdio.h>
void reverse(int a[], int size);
int main()
{
    int a[1000], n, s, j;
    scanf("%d", &n);
    scanf("%d", &s);
    for (j = 0; j < n; j++)
        scanf("%d", &a[j]);
    reverse(a, s);
    for (j = 0; j < n; j++)
        printf("%d ", a[j]);
    return 0;
}
void reverse(int a[], int size)
{
    int i, t;
    for (i = 0; i < size / 2; i++)
    {
        t = a[i];
        a[i] = a[size - i - 1];
        a[size - i - 1] = t;
    }
}