#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void SelectionSort(int arr[], int left, int right);
int main()
{
    int arr[50], l, r, i, j;
    scanf("%d%d", &l, &r);
    srand(time(NULL));
    for (i = 0; i < 50; i++)
    {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    printf("\n");
    SelectionSort(arr, l, r);
    return 0;
}


void SelectionSort(int arr[], int left, int right)
{
    int i,j,c,k;
    for (i = left; i < right; i++)
    {
        {c = arr[i]; k = i; }
        for (j = i + 1; j < right; j++)
        {
            if (c > arr[j])
            {
                c = arr[j];
                k = j;
            }
        }
        {arr[k] = arr[i]; arr[i] = c; }
    }
    for (i = 0; i <50; i++)
        printf("%d ", arr[i]);
}