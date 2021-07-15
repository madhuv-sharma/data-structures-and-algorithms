// Designed in Turbo C++

#include <alloc.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *link;
};

struct queue
{
	struct Node *front;
	struct Node *rear;
};

void initqueue(struct queue*);
void addq(struct queue*, int);
int delq(struct queue*);
void delqueue(struct queue*);

void main()
{
	clrscr();
	struct queue a;
	int i;

	initqueue(&a);
	addq(&a, 11);
	addq(&a, -8);
	addq(&a, 23);
	addq(&a, 19);
	addq(&a, 15);
	addq(&a, 16);
	addq(&a, 28);
	i = delq(&a);
	printf("\nItem extracted: %d", i);
	i = delq(&a);
	printf("\nItem extracted: %d", i);
	i = delq(&a);
	printf("\nItem extracted: %d", i);
	delqueue(&a);
	getch();
}


void initqueue(struct queue *q)
{
	q -> front = q -> rear = NULL;
}


void addq(struct queue *q, int item)
{
	struct Node *temp;
	temp = (struct Node *) malloc(sizeof(struct Node));
	if(temp == NULL)
		printf("\nQueue is full.");
	temp -> data = item;
	temp -> link = NULL;
	if(q -> front == NULL)
	{
		q -> rear = q -> front = temp;
		return;
	}
	q -> rear -> link = temp;
	q -> rear = q -> rear -> link;
}


int delq(struct queue *q)
{
	struct Node *temp;
	int item;
	if(q -> front == NULL)
	{
		printf("\nQueue is empty.");
		return NULL;
	}
	item = q -> front -> data;
	temp = q -> front;
	q -> front = q -> front -> link;
	free(temp);
	return item;
}


void delqueue(struct queue *q)
{
	struct Node *temp;
	if(q -> front == NULL)
		return ;
	while(q -> front != NULL)
	{
		temp = q -> front;
		q -> front = q -> front -> link;
		free(temp);
	}
}