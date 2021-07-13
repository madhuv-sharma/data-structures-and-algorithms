// Designed in Turbo C++

#include <stdio.h>
#include <conio.h>

#define MAX 10

struct stack
{
	int arr[MAX];
	int top;
};

void initstack(struct stack *);
void push(struct stack *, int item);
int pop(struct stack *);

void main()
{
	struct stack s;
	int i;
	clrscr();
	initstack(&s);
	push(&s, 11);
	push(&s, 23);
	push(&s, -8);
	push(&s, 16);
	push(&s, 27);
	push(&s, 14);
	push(&s, 20);
	push(&s, 39);
	push(&s, 2);
	push(&s, 15);
	push(&s, 7);
	i = pop(&s);
	printf("\n\nItem popped: %d", i);
	i = pop(&s);
	printf("\nItem popped: %d", i);
	i = pop(&s);
	printf("\nItem popped: %d", i);
	i = pop(&s);
	printf("\nItem popped: %d", i);
	i = pop(&s);
	printf("\nItem popped: %d", i);
	getch();
}


void initstack(struct stack *s)
{
	s -> top = -1;
}


void push(struct stack *s, int item)
{
	if(s -> top == MAX - 1)
	{
		printf("\nStack is full.");
		return;
	}
	s -> top++;
	s -> arr[s ->top] = item;
}


int pop(struct stack *s)
{
	int data ;
	if(s -> top == -1)
	{
		printf("\nStack is empty.");
		return NULL;
	}
	data = s -> arr[s -> top];
	s -> top--;
	return data;
}
