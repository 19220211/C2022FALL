#include<stdio.h>
void quicksort(int l, int r);
int n, a[100001];
int main()
{
    int i;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    quicksort(1, n);
    for (i = 1; i <= n; i++)
        printf("%d ", a[i]);
}
void quicksort(int l, int r)
{
    int mid = a[(l + r) / 2];
    int i = l, j = r;
    while (i <= j)
    {
        while (a[i] < mid) i++;
        while (a[j] > mid) j--;
        if (i <= j)
        {
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
            i++;
            j--;
        }
    }
    if (l < j) quicksort(l, j);
    if (i < r) quicksort(i, r);
}
