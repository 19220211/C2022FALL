#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void InsertionSort(int arr[], int left, int right);
int main()
{    
    int arr[50], l, r,i,j;
    scanf("%d%d", &l, &r);
    srand(time(NULL));
    for (i = 0; i <50; i++)
    {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    printf("\n");
    InsertionSort(arr, l, r);
    return 0;
}

void InsertionSort(int arr[], int left, int right)
{
    int i;
    for (i = left; i < right; i++)
    {
        int end = i;
        int x = arr[end + 1];
        while (end >= 0)
        {
            if (arr[end] > x)
            {
                arr[end + 1] = arr[end];
                --end;
            }
            else
            {
                break;
            }
        }
        arr[end + 1] = x;
    }
    for (i = 0; i < 50; i++)
        printf("%d ", arr[i]);
}