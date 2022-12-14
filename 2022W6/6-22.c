//https://www.acwing.com/blog/content/29070/
#include<stdio.h>
#include<string.h>
int main()
{
    char c[50001];
    int i, j = 0, n = 0;
    scanf("%s", c);
    for (i = strlen(c) - 2; i >= 0; i--)
    {
        if (c[i] == ')' && c[i + 1] == ')')
            j++;
        else if (c[i] == '(' && c[i + 1] == '(')
            n = n + j;
    }
    printf("%d", n);
    return 0;
}