//https://www.acwing.com/blog/content/27815/
void reOrderArray(int* array, int length) {
    int i, j = 0, d[100];
    for (i = 0; i < length; i++)
    {
        if (array[i] % 2 == 1)
        {
            d[j] = array[i];
            j++;
        }
    }
    for (i = 0; i < length; i++)
    {
        if (array[i] % 2 == 0)
        {
            d[j] = array[i];
            j++;
        }
    }
    for (i = 0; i < j; i++)
        array[i] = d[i];
}