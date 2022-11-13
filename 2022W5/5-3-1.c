#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int binary_search_recursive(int arr[], int left, int right, int query);
void BubbleSort(int arr[], int left, int right);
int main()
{
    int arr[50], l, r, q, i, j, d[100];
    scanf("%d%d%d", &l, &r, &q);
    for (i = 0; i < 100; i++)
        d[i] = 0;
    srand(time(NULL));
    for (i = 0; i < 50; i++)
    {
        arr[i] = rand() % 100;
        if (d[arr[i]] == 0)
        {
            printf("%d ", arr[i]);
            d[arr[i]] = 1;
        }
        else
            i--;
    }
    printf("\n");
    BubbleSort(arr, l, r);
    j=binary_search_recursive(arr, l, r, q);
    printf("\n%d", j);
    return 0;
}

int binary_search_recursive(int arr[], int left, int right, int query)
{
    int z, i;
    if (left > right)
    {
        z = -1;
        return z;
    }
    else
    {
        z = (left + right) / 2;
        if (arr[z] > query)
            return binary_search_recursive(arr, left, z-1, query);
        else if (arr[z] < query)
            return binary_search_recursive(arr, z+1, right, query);
        else
            return z;
    }
}

void BubbleSort(int arr[], int left, int right)
{
    int i, j, t;
    for (i = left; i < right; i++)
    {
        for (j = i + 1; j <= right; j++)
        {
            if (arr[i] > arr[j])
            {
                t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
    }
    for (i = 0; i < 50; i++)
        printf("%d ", arr[i]);
}