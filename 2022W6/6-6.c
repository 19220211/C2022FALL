#include<stdio.h>
#include<string.h>
int count_substr(const char* str, const char* substr);
int main()
{
	char str[100], substr[100];
	gets(str);
	gets(substr);
	printf("%d", count_substr(str, substr));
	return 0;
}
int count_substr(const char* str, const char* substr)
{
	int i, j, w = 0;
	for (i = 0; i < strlen(str) - strlen(substr) + 1; i++)
	{
		for (j = 0; j < strlen(substr); j++)
		{
			if (str[i] == substr[j])
				i++;
			else
			{
				i++; break;
			}
		}
		if (j == strlen(substr))
			w++;
		i--;
	}
	return w;
}