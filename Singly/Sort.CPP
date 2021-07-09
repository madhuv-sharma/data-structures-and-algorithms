#include<alloc.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>


struct Node
{
    int data;
    struct Node *lnk;
};

void beg(struct Node **p, int data);
void sort(struct Node *p);
void swap(struct Node *a, struct Node *b);
void disp(struct Node *p);


void main()
{
    clrscr();

    int j;

    struct Node *p = NULL;

    for (int i=0; i<8; i++)
    {
	printf("Please enter a value:\n");
	scanf("%d", &j);
	beg(&p, j);

    }
    printf("\n Linked list before sorting ");
    disp(p);

    sort(p);

    printf("\n Linked list after sorting ");
    disp(p);

    getch();
}


void beg(struct Node **p, int data)
{
    struct Node *q = (struct Node*)malloc(sizeof(struct Node));
    q->data = data;
    q->lnk = *p;
    *p = q;
}


void disp(struct Node *p)
{
    printf("\n");
    struct Node *temp = p;
    while (temp!=NULL)
    {
	printf("%d ", temp->data);
	temp = temp->lnk;
    }
}


void sort(struct Node *p)
{
    int b, i;
    struct Node *q;
    struct Node *r = NULL;

    if (p == NULL)
	return;

    do
    {
	b = 0;
	q = p;
	while (q->lnk != r)
	{
	    if (q->data > q->lnk->data)
	    {
		swap(q, q->lnk);
		b = 1;
	    }
	    q = q->lnk;
	}
	r = q;
    }while (b);
}


void swap(struct Node *a, struct Node *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}