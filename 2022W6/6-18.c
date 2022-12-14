#include<stdio.h>
#include<stdlib.h>
struct Node* construct(int arr[], int size);
struct Node* IBH(struct Node* head, struct Node* newp);
void clear(struct Node* head);
void Output(struct Node* head);
struct Node
{
	int val;
	struct Node* next;
};
struct Node* P;
int main()
{
	int arr[4] = { 101,103,105 };
	struct Node* head = construct(arr, 3);
	printf("ɾ��ǰ��\n");
	Output(head);
	clear(head);
	printf("ɾ����\n");
	Output(P);
	return 0;
}
struct Node* construct(int arr[], int size)
{
	struct Node* head, * newp; int i;
	head = NULL;
	for (i = size - 1; i >= 0; i--)
	{
		newp = (struct Node*)malloc(sizeof(struct Node));
		newp->val = arr[i];
		head = IBH(head, newp);
	}
	return head;
}
struct Node* IBH(struct Node* head, struct Node* newp)
{
	newp->next = head;
	head = newp;
	return head;
}
void Output(struct Node* head)
{
	struct Node* p;
	p = head;
	if (p == NULL)
		printf("NULL");
	else
	{
		while (p != NULL)
		{
			printf("%X\t%d\t%X\n", p, p->val, p->next);
			p = p->next;
		}
	}
}
void clear(struct Node* head)
{
	struct Node* q;
	P = head;
	while (P != NULL)
	{
		q = P->next;
		free(P);
		P = q;
	}
}
