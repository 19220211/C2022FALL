//https://www.acwing.com/blog/content/27824/
#include<stdio.h>
#include<string.h>
int main()
{
    char p[10000][101], s[101], t[10000][101];
    int sj[10000], i, j, k, l, x, m, g = 0, gs = 0, zs = 0, qd, zd = 0;
    while (gets(s))
    {
        if ('0' <= s[0] && s[0] <= '9' && zs == zd)
        {
            x = 0;
            l = strlen(s);
            for (i = 0; i < l; i++)
                x = x * 10 + (int)(s[i]) - 48;
            sj[g] = x;
            zd = zd + sj[g];
            g++;
        }
        else if (strcmp(s, "stop") == 0)
        {
            if (gs < sj[g - 1])
            {
                zd = zd - sj[g - 1] + gs;
                sj[g - 1] = gs;
            }
            gs = 0;
        }
        else
        {
            strcpy(p[zs], s);
            zs++;
            gs++;
            if (gs == sj[g - 1])
                gs = 0;
        }

    }
    {qd = 0; zd = sj[0]; }
    for (k = 0; k < g; k++)
    {
        for (i = qd; i < zd - 1; i++)
        {
            for (m = i + 1; m < zd; m++)
            {
                if (strlen(p[m]) < strlen(p[i]))
                {
                    strcpy(t, p[m]);
                    strcpy(p[m], p[i]);
                    strcpy(p[i], t);
                }
            }
        }
        if (k < g - 1)
        {
            qd = qd + sj[k];
            zd = zd + sj[k + 1];
        }
    }
    for (j = 0; j < zd; j++)
        puts(p[j]);
    return 0;
}