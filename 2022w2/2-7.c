#include<stdio.h>
#include<math.h>
int main()
{
unsigned long int a, b, c,d;
scanf("%ld%ld%ld", &a, &b, &c);
(long double)a;
(long double)b;
d = (unsigned long int)pow(a, b) ;
d = d % c;
printf("%ld", d);
return 0;


}