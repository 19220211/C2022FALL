#include<stdio.h>
#include<stdlib.h>
struct Node* construct(int arr[], int size);
struct Node* IBH(struct Node* head, struct Node* newp);
struct Node* ddelete(struct Node* head, struct Node* target);
struct Node* Delete(struct Node* head);
void Output(struct Node* head);
struct Node
{
	int val;
	struct Node* next;
};
int main()
{
	int arr[4] = { 101,103,105 };
	struct Node* head = construct(arr, 3);
	struct Node* target = (struct Node*)malloc(sizeof(struct Node));
	printf("É¾³ýÇ°£º\n");
	Output(head);
	target->val = 101;
	head = ddelete(head, target);
	printf("É¾³ýºó£º\n");
	Output(head);
	head = Delete(head);
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
struct Node* Delete(struct Node* head)
{
	struct Node* p, * q;
	p = head;
	while (p != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	return NULL;
}
struct Node* ddelete(struct Node* head, struct Node* target)
{
	struct Node* p, * prev;
	p = head; prev = NULL;
	while (p != NULL)
	{
		if (p->val == target->val)
			break;
		prev = p;	p = p->next;
	}
	if (p == NULL)
		return head;
	if (p == head)
		head = head->next;
	else
		prev->next = p->next;
	free(p);
	return head;
}