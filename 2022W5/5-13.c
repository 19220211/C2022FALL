#include<stdio.h>
#include<stdlib.h>
struct student
{
	char name[10];
	char id[10];
	int score;
};
int main()
{
	struct student stu[100];
	int maxi = 0, mini = 0, n, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%s%s%d", stu[i].name, stu[i].id, &stu[i].score);
	for (i = 0; i < n; i++)
	{
		if (stu[i].score > stu[maxi].score)
			maxi = i;
		else if (stu[i].score < stu[mini].score)
			mini = i;
	}
	printf("%s %s\n", stu[maxi].name, stu[maxi].id);
	printf("%s %s\n", stu[mini].name, stu[mini].id);
	return 0;
}


	
	
