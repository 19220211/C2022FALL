//https://www.acwing.com/blog/content/27823/
#include<stdio.h>
#include<string.h>
int main()
{
    char s[1000], g[1000];
    int i, j = 0, k, m = 0, len, n;
    while (gets(s))
    {
        j = 0;
        m = 0;
        len = strlen(s);
        for (i = 0; i <= 25; i++)
        {
            for (k = 0; k < len; k++)
            {
                if (s[k] == (char)(97 + i) || s[k] == (char)(65 + i))
                {
                    g[j] = s[k];
                    j++;
                }
            }
        }
        for (n = 0; n < len; n++)
        {
            if ('a' <= s[n] && s[n] <= 'z' || 'A' <= s[n] && s[n] <= 'Z')
            {
                printf("%c", g[m]);
                m++;
            }
            else
                printf("%c", s[n]);
        }
        printf("\n");
    }
    return 0;
}