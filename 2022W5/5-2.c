#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int is_sorted(int arr[], int left, int right);
void BubbleSort(int arr[], int left, int right);
int main()
{
    int arr[50], l, r, i, j, t;
    scanf("%d%d", &l, &r);
    srand(time(NULL));
    for (i = 0; i < 50; i++)
    {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    printf("\n");
    BubbleSort(arr, l, r);
    t = is_sorted(arr, l, r);
    if (t == 0)
        printf("\nyes");
    else
        printf("\nno");
    return 0;
}

int is_sorted(int arr[], int left, int right)
{
    int i, j = 0;
    for (i = left; i < right; i++)
    {
        if (arr[i] > arr[i + 1])
            j = 1;
    }
    return j;
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
    for(i=0;i<50;i++)
        printf("%d ",arr[i]);
}