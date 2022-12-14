#include<stdio.h>
int merge(int arr[], int l, int m, int r);
int merge_sort(int arr[], int l, int r);
int main()
{
	int arr[40000],n,i,j ;
    scanf_s("%d", &n);
    for (i = 0; i < n; i++)
        scanf_s("%d", &arr[i]);
    printf("%d", merge_sort(arr, 0, n-1));
	return 0;
}
int merge_sort(int arr[], int l, int r)
{
    if (l == r)
        return 0;
    int m = (l + r) / 2;
    return merge_sort(arr, l, m) + merge_sort(arr, m + 1, r) + merge(arr, l, m, r);
}
int merge(int arr[], int l, int m, int r)
{
    int i,j,t,p1=l,p2=m+1,c=0;
    while (p1 <= m && p2 <= r)
    {
        if (arr[p1] > arr[p2])
        {
            c = c + r - p2 + 1;
            p1++;
        }
        else
            p2++;
    }
    for (i = l; i < r; i++)
    {
        for (j = i + 1; j <= r; j++)
        {
            if (arr[i] < arr[j])
            {
                t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
    }
    return c;
}

    
    
