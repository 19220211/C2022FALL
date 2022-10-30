//https://www.acwing.com/blog/content/27440/
#include<stdio.h>
int main()
{
    double N;
    int d[12] = { 0 }, i, n[12] = { 10000,5000,2000,1000,500,200,100,50,25,10,5,1 }, a;
    scanf("%lf", &N);
    a = (int)(100 * N + 0.5);
    for (i = 0; i < 12; i++)
    {
        while (a >= n[i])
        {
            a = a - n[i];
            d[i]++;
        }
    }
    printf("NOTAS:\n");
    for (i = 0; i < 6; i++)
        printf("%d nota(s) de R$ %.2f\n", d[i], (float)(n[i]) / 100.0);
    printf("MOEDAS:\n");
    for (i = 6; i < 12; i++)
        printf("%d moeda(s) de R$ %.2f\n", d[i], (float)(n[i]) / 100.0);
    return 0;
}