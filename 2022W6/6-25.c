//https://www.acwing.com/blog/content/29073/
#include<stdio.h>
#include<string.h>
int cx(char a[50][50], char M, char O);
int n, m;
int main()
{
    int i, j, c = 0, sum = 0;
    char a[50][50], s[50], M;
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++)
    {
        scanf("%s", s);
        strcpy(a[i], s);
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            M = a[i][j];
            if (M != 'M')
            {
                if (j + 2 < m && a[i][j + 1] == a[i][j + 2] && a[i][j + 1] != M && a[i][j + 1] != 'O')
                    c = cx(a, M, a[i][j + 1]);
                if (c > sum)
                    sum = c;
                if (0 <= j - 2 && a[i][j - 1] == a[i][j - 2] && a[i][j - 1] != M && a[i][j - 1] != 'O')
                    c = cx(a, M, a[i][j - 1]);
                if (c > sum)
                    sum = c;
                if (i + 2 < n && a[i + 1][j] == a[i + 2][j] && a[i + 1][j] != M && a[i + 1][j] != 'O')
                    c = cx(a, M, a[i + 1][j]);
                if (c > sum)
                    sum = c;
                if (0 <= i - 2 && a[i - 1][j] == a[i - 2][j] && a[i - 1][j] != M && a[i - 1][j] != 'O')
                    c = cx(a, M, a[i - 1][j]);
                if (c > sum)
                    sum = c;
                if (j + 2 < m && i + 2 < n && a[i + 1][j + 1] == a[i + 2][j + 2] && a[i + 1][j + 1] != M && a[i + 1][j + 1] != 'O')
                    c = cx(a, M, a[i + 1][j + 1]);
                if (c > sum)
                    sum = c;
                if (0 <= j - 2 && 0 <= i - 2 && a[i - 1][j - 1] == a[i - 2][j - 2] && a[i - 1][j - 1] != M && a[i - 1][j - 1] != 'O')
                    c = cx(a, M, a[i - 1][j - 1]);
                if (c > sum)
                    sum = c;
                if (i + 2 < n && 0 <= j - 2 && a[i + 1][j - 1] == a[i + 2][j - 2] && a[i + 1][j - 1] != M && a[i + 1][j - 1] != 'O')
                    c = cx(a, M, a[i + 1][j - 1]);
                if (c > sum)
                    sum = c;
                if (0 <= i - 2 && j + 2 < m && a[i - 1][j + 1] == a[i - 2][j + 2] && a[i - 1][j + 1] != M && a[i - 1][j + 1] != 'O')
                    c = cx(a, M, a[i - 1][j + 1]);
                if (c > sum)
                    sum = c;
            }
        }
    }
    printf("%d", sum);
    return 0;
}
int cx(char a[50][50], char M, char O)
{
    int i, j, c = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (a[i][j] == M)
            {
                if (j + 2 < m && a[i][j + 1] == O && O == a[i][j + 2])
                    c++;
                if (0 <= j - 2 && a[i][j - 1] == O && O == a[i][j - 2])
                    c++;
                if (i + 2 < n && a[i + 1][j] == O && O == a[i + 2][j])
                    c++;
                if (0 <= i - 2 && a[i - 1][j] == O && O == a[i - 2][j])
                    c++;
                if (j + 2 < m && i + 2 < n && a[i + 1][j + 1] == O && O == a[i + 2][j + 2])
                    c++;
                if (0 <= j - 2 && 0 <= i - 2 && a[i - 1][j - 1] == O && O == a[i - 2][j - 2])
                    c++;
                if (i + 2 < n && 0 <= j - 2 && a[i + 1][j - 1] == O && O == a[i + 2][j - 2])
                    c++;
                if (0 <= i - 2 && j + 2 < m && a[i - 1][j + 1] == O && O == a[i - 2][j + 2])
                    c++;
            }
        }
    }
    return c;
}