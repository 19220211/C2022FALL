#include<stdio.h>
void Move(char s, char t);
void Hanoi(int n, char s, char h, char t);
int main()
{   
	Hanoi(3, 'A', 'B', 'C');
	return 0;
}
void Move(char s, char t)
{
	printf("%c->%c\n", s, t);
}
void Hanoi(int n, char s, char h, char t)
{
	if (n == 1) Move(s, t);
	else
	{
		Hanoi(n-1, s, t, h);
		Move(s, t);
		Hanoi(n-1, h, s, t);
	}
}