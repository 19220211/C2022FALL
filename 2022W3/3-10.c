//https://www.acwing.com/blog/content/27441/
#include<stdio.h>
int main()
{
    float a, s;
    scanf("%f", &a);
    if (a > 4500.00)
        s = (a - 4500.00) * 0.28 + 80.00 + 270.00;
    else if (3000.01 <= a)
        s = (a - 3000.00) * 0.18 + 80.00;
    else if (2000.01 <= a)
        s = (a - 2000.00) * 0.08;
    else
        s = 0.00;
    if (s == 0.00)
        printf("Isento");
    else
        printf("R$ %.2f", s);
    return  0;

}
