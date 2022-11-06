//https://www.acwing.com/blog/content/27814/
int duplicateInArray(int* nums, int numsSize) {
    int i, j, f = 0, g = -1;
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] > numsSize - 1 || nums[i] < 0)
            f = 1;
    }
    if (numsSize == 1 || numsSize == 0)
        f = 1;
    if (f != 1)
    {
        for (i = 0; i < numsSize - 1; i++)
        {
            for (j = i + 1; j < numsSize; j++)
            {
                if (nums[i] == nums[j])
                {
                    g = nums[i];
                    i = numsSize;
                    j = numsSize;
                }
            }
        }
    }

    return g;
}