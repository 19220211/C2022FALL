//https://www.acwing.com/blog/content/27825/
#include<stdio.h>
#include<string.h>
int main()
{
    char s[100];
    int l, i;
    gets(s);
    l = strlen(s);
    for (i = 0; i < l - 1; i++)
        printf("%c", (char)((int)(s[i]) + (int)(s[i + 1])));
    printf("%c", (char)((int)(s[0]) + (int)(s[l - 1])));
    return 0;
}