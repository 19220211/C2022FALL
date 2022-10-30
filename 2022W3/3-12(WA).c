#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int a[10], l = 0, fzd[10], fn[50], n = 0, i, j, e = 0, f = 0, max[10] , g = 0, s, t = 0, h = 0, wz = 0, k = 0, G = 0, pd = 0, d[1000], D[1000], qd = 4, zd = 0;
    char o[10], F[400] ,str[100];
    for (i= 0; i <1000; i++)
      d[i]=0;
    for (i= 0; i < 10; i++)
    {
        fzd[i] = 0; a[i] = 0; max[i] = 0;
    }
    scanf_s("%d", &s);
    
    while (scanf("%s",str) != EOF)
    {
        if ('0' <= str[0] <= '9')
        {
            for (i = 0; i < 3; i++)
            {
                while ('0' <= str[i] <= '9')
                    a[t] = a[t] * 10 + (int)(str[i]);
            }
            for (i = 4; i < strlen(str); i++)
            {
                if (str[i] = '^')
                {
                    i++;
                    while ('0' <= str[i] <= '9')
                    {
                        fzd[t] = fzd[t] * 10 + (int)(str[i]);
                        i++;
                    }
                }
            }
        }
        else if (str[0] == 'F')
        {
            for (i = 0; i <= 2; i = i + 2)
            {
                d[wz] = (int)(str[i]); wz++;
            }
            qd = 4;
            for (i = 4; i <= strlen(str); i++)
            {
                if (str[i] = ' ' || '\0')
                {
                    while (qd <= zd)
                    {
                        d[wz] = d[wz] * 10 + (int)(str[qd]);
                        qd++;
                    }
                    {wz++; qd++; }
                }
                else
                    zd = i;
            }
        }
        else
        {
            d[wz] = (int)(str[0]); wz=wz+4;
        }
        t++;
    }
      

    for (t = 0; t < s; t++)
    {
        {n = 0; e = 0; f = 0; g = 0; wz = 0; G = 0; pd = 0; }
        for (j = 0; j < 50; j++)
            fn[j] = 0;
        for (j = 0; j < 1000; j++)
            D[j] = 0;

        for (wz = 0; wz < 4 * a[t]; wz++)
            D[wz] = d[k + wz];
        if (a[t] % 2 == 1)
            printf("ERR\n");
        else
        {
            h = 4 * a[t];
            for (j = 0; j <= h - 4; j++)
            {
                if (D[j] == (int)('F'))
                {
                    f++;
                    for (i = e + f - 1; i >= 1 + e; i--)
                    {
                        if (fn[i - 1 - e] == 0 && D[4 * (i - 1) + 1] == D[4 * (e + f - 1) + 1])
                            g = 1;
                    }
                }
                else
                {
                    e++;
                    if (g == 0 && G == 0)
                    {
                        for (i = f - 1; i >= 0; i--)
                        {
                            if (fn[i] == 0)
                            {
                                if (0 <= D[4 * (i + e - 1 - pd) + 2] <= 9 && D[4 * (i + e - 1 - pd) + 3] == (int)('n'))
                                    n = n + 1;
                                else if (0 <= D[4 * (i + e - 1 - pd) + 3] <= 9 && 0 <= D[4 * (i + e - 1 - pd) + 2] <= 9)
                                {
                                    if (D[4 * (i + e - 1 - pd) + 2] > D[4 * (i + e - 1 - pd) + 3])
                                    {
                                        n = -1; G = -1;
                                    }
                                    else
                                        n = n + 0;
                                }
                                else
                                {
                                    n = -1; G = -1;
                                }
                            }
                            fn[i] = 1;
                        }
                    }
                    pd++;
                }
                j = j + 3;
                if (f == e && g == 0)
                {
                    if (max[t] < n)
                        max[t] = n;
                    n = 0;
                    G = 0;
                    pd = 0;
                }
            }
            if (f == e && g == 0)
            {
                if (fzd[t] == max[t])
                    printf("YES\n");
                else
                    printf("NO\n");
            }
            else
            {
                printf("ERR\n");
            }
        }
        k = k + 4 * a[t];
    } 
      return 0;
}