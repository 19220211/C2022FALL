//https://www.acwing.com/blog/content/27821/
#include<stdio.h>
void copy(int a[], int b[], int size);
int m;
int main()
{
    int i, n, s, a[100], b[100];
    scanf("%d%d%d", &n, &m, &s);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < m; i++)
        scanf("%d", &b[i]);
    copy(a, b, s);
    return 0;
}
void copy(int a[], int b[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", a[i]);
    for (i = size; i < m; i++)
        printf("%d ", b[i]);
}