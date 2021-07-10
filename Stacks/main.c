// Designed in Turbo C++

#include <alloc.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

int count = 0;


struct Stack
{
	int arr[10];
	int top;
};


int isfull(struct Stack *s)
{
	if (s -> top == 9)
	{
		printf("STACK FULL");
		return 1;
	}
	else
		return 0;
}


int isempty(struct Stack *s)
{
	if (s -> top == -1)
	{
		printf("\nStack is Empty!\n");
		return 1;
	}
	else
		return 0;
}


void push(struct Stack *s, int data)
{
	if (!(isfull(s)))
	{
		s -> top++;
		s -> arr[s->top] = data;
	}
	count++;
}


void pop(struct Stack *s)
{
	if (!(isempty(s)))
	{
		printf("%d has been popped", s -> arr[s -> top]);
		s -> top--;
	}
	count--;
	printf("\n");
}


void printStack(struct Stack *s)
{
	printf("\nStack: ");
	for (int i = 0; i < count; i++)
		printf("%d ", s -> arr[i]);
	printf("\n");
}


void main()
{
	clrscr();

	struct Stack *s = (struct Stack *) malloc(sizeof(struct Stack));
	s -> top = -1;

	printf("\nPushing 1, 2, 3 and 4:\n");
	push(s, 1);
	push(s, 2);
	push(s, 3);
	push(s, 4);
	printStack(s);

	printf("\nAfter popping out twice\n");
	pop(s);
	pop(s);
	printStack(s);
	
	getch();
}
