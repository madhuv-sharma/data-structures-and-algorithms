#include <stdio.h>
#define MAX 10


void addq (int *, int, int *, int *);
int delq (int *, int *, int *);
void display (int *);


void (main)
{
	int arr[MAX];
	int i, front, rear;
	/* initialise data member */
	front = rear = -1;
	for (i = 0; i < MAX; i++)
		arr[i] = 0;
	addq (arr, 14, &front, &rear);
	addq (arr, 22, &front, &rear);
	addq (arr, 13, &front, &rear);
	addq (arr, -6, &front, &rear);
	addq (arr, 25, &front, &rear);
	printf ("\nElements in the circular queue: ");
	display (arr);
	i = delq (arr, &front, &rear);
	printf ("Item deleted: %d", i);
	i = delq (arr, &front, &rear);
	printf ("\nItem deleted: %d", i);
	printf ("\nElements in the circular queue after deletion: ");
	display (arr);
	addq (arr, 21, &front, &rear);
	addq (arr, 17, &front, &rear);
	addq (arr, 18, &front, &rear);
	addq (arr, 9, &front, &rear);
	addq (arr, 20, &front, &rear);

	printf ("Elements in the circular queue after addition: ");
	display (arr);
	addq (arr, 32, &front, &rear);
	printf ("Elements in the circular queue after addition: ");
	display (arr);
}


/* adds an element to the queue */
void addq (int *arr, int item, int *pfront, int *prear)
{
	if ((*prear == MAX - 1 && *pfront == 0) || ( *prear + 1 == *pfront))
	{
		printf ("\nQueue is full.");
		return;
	}
	if (*prear == MAX - 1)
		*prear = 0;
	else
		(*prear)++;

	arr[*prear] = item;

	if (*pfront == -1)
		*pfront = 0;
}


/* removes an element from the queue */
int delq (int *arr, int *pfront, int *prear)
{
	int data;

	if (*pfront == -1)
	{
		printf ("\nQueue is empty.");
		return NULL;
	}

	data = arr[*pfront];
	arr[*pfront] = 0;

	if (*pfront == *prear)
	{
		*pfront = -1;
		*prear = -1;
	}
	else
	{
		if (*pfront == MAX - 1)
			*pfront = 0;
		else
			(*pfront)++;
	}
	return data;
}


/* displays element in a queue */
void display (int * arr)
{
	int i;
	printf ("\n");
	for (i = 0; i < MAX; i++)
		printf ("%d\t", arr[i]);
	printf ("\n");
}