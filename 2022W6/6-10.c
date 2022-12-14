#include<stdio.h>
#include<stdlib.h>
struct Node* construct(int arr[], int size);
struct Node* IBH(struct Node*head,struct Node*newp);
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
	struct Node*head= construct(arr,3);
	Output(head);
	head = Delete(head);
	return 0;
}
struct Node* construct(int arr[], int size)
{
	struct Node* head, * newp; int i;
	head = NULL;
	for (i = size-1; i>=0; i--)
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
	while (p != NULL)
	{
		printf("%X\t%d\t%X\n", p, p->val, p->next);
		p = p->next;
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