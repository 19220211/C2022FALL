//https://www.acwing.com/blog/content/27822/
#include<stdio.h>
#include<string.h>
int main()
{
    int i, j, l, k;
    char s[20], c;
    scanf("%s", s);
    l = strlen(s);
    for (i = 0; i < l; i++)
    {
        {c = s[i]; k = i; }
        for (j = i + 1; j < l; j++)
        {
            if (c > s[j])
            {
                c = s[j];
                k = j;
            }
        }
        {s[k] = s[i]; s[i] = c; }
    }
    for (i = 0; i < l; i++)
        printf("%c", s[i]);
}