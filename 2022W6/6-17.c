#include<stdio.h>
#include<stdlib.h>
struct Node* construct(int arr[], int size);
struct Node* IBH(struct Node* head, struct Node* newp);
struct Node* merge(struct Node* head1, struct Node* head2);
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
	int a[4] = { 100,102,104 };
	struct Node* head1= construct(arr, 3);
	struct Node* head2 = construct(a, 3);
	printf("归并前：\n");
	Output(head1);
	Output(head2);
	struct Node* head=merge(head1,head2);
	printf("归并后：\n");
	Output(head);
    clear(head);
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
struct Node* merge(struct Node* head1, struct Node* head2)
{
	struct Node* p, * q, * r, * head;
	p = head1->next;
	q = head2->next;
	if (head1->val <= head2->val)
	{
		head = head1;
		r = head;
		r->next = head2;
		r = head2;
	}
	else
	{
		head = head2;
		r = head;
		r->next = head1;
		r = head1;
	}
	while (p != NULL && q != NULL)
	{
		if (p->val <= q->val)
		{
			r->next = p;
			r = p;
			p = p->next;
		}
		else
		{
			r->next = q;
			r = q;
			q = q->next;
		}
	}
	if (p != NULL)
		r->next = p;
	else
		r->next = q;
	return head;
}