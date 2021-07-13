// Designed in Turbo C++

#include <alloc.h>
#include <conio.h>
#include <stdio.h>

struct Node
{
	int data;
	struct Node *link;
};

void push(struct Node **, int);
int pop(struct Node **);
void delstack(struct Node **);

void main()
{
	struct Node *s = NULL;
	int i;
	clrscr();
	push(&s, 14);
	push(&s, -3);
	push(&s, 18);
	push(&s, 29);
	push(&s, 31);
	push(&s, 16);
	i = pop(&s);
	printf("\nItem popped: %d", i);
	i = pop(&s);
	printf( "\nItem popped: %d", i);
	i = pop(&s);
	printf("\nItem popped: %d", i);
	delstack(&s);
	getch();
}


void push(struct Node **top, int item)
{
	struct Node *temp;
	temp = (struct Node *) malloc(sizeof(struct Node));

	if(temp == NULL)
		printf("\nStack is full.");
	temp -> data = item;
	temp -> link = *top;
	*top = temp;
}


int pop(struct Node **top)
{
	struct Node *temp;
	int item;
	if(*top == NULL)
	{
		printf("\nStack is empty.");
		return NULL;
	}
	temp = *top;
	item = temp -> data;
	*top = (*top) -> link;
	free(temp);
	return item;
}


void delstack(struct Node **top)
{
	struct Node *temp;
	if(*top == NULL)
		return;
	while(*top != NULL)
	{
		temp = *top;
		*top = (*top) -> link;
		free(temp);
	}
}