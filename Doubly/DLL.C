// Designed in Turbo C++

#include <alloc.h>
#include <conio.h>
#include <stdio.h>


struct dNode
{
	int data;
	struct dNode *prv, *nxt;
};


void append(struct dNode **, int);
void addatbeg(struct dNode **, int);
void addafter(struct dNode *, int, int);
void disp(struct dNode *);
void revdisp(struct dNode *);
int count(struct dNode *);
void del(struct dNode **, int);


void main()
{
	clrscr();

	struct dNode *p;
	p = NULL;
	printf("\nNo. of elements in the Linked List = %d", count(p));

	append(&p, 14);
	append(&p, 30);
	append(&p, 25);
	append(&p, 42);
	append(&p, 17);
	disp(p);

	addatbeg(&p, 999);
	addatbeg(&p, 888);
	addatbeg(&p, 777);
	disp(p);

	addafter(p, 7, 0);
	addafter(p, 2, 1);
	addafter(p, 5, 99);
	disp(p);
	printf("\nNo. of elements in the Linked List = %d", count(p));

	del(&p, 99);
	del(&p, 1);
	del(&p, 10);
	disp(p);
	printf("\nNo. of elements in the Linked List = %d", count(p));

	getch();
}


void append(struct dNode **q, int num)
{
	struct dNode *temp, *r;

	if (*q == NULL)
	{
		temp = (struct dNode*) malloc(sizeof(struct dNode)) ;
		temp -> prv = NULL;
		temp -> data = num;
		temp -> nxt = NULL;
		*q = temp;
	}
	else
	{

		temp = *q;

		while (temp -> nxt != NULL)
			temp = temp -> nxt;

		r = (struct dNode*) malloc(sizeof(struct dNode));
		r -> prv = temp;
		r -> data = num;
		r -> nxt = NULL;
		temp -> nxt = r;
	}
}


void addatbeg(struct dNode **q, int num)
{
	struct dNode *temp;

	temp = (struct dNode*) malloc(sizeof(struct dNode));
	temp -> prv = NULL;
	temp -> data = num;
	temp -> nxt = *q;
	(*q) -> prv = temp;
	*q = temp;
}


void addafter(struct dNode *q, int loc, int num)
{
	struct dNode *temp, *r;
	int i;

	temp = q;
	for (i = 0 ; i < loc ; i++)
	{
		temp = temp -> nxt;
		if (temp == NULL)
		{
			printf("\nThere are less than %d elements in list", loc);
			return;
		}
	}

	r = (struct dNode*) malloc(sizeof(struct dNode));
	r -> prv = temp;
	r -> data = num ;
	r -> nxt = temp -> nxt;
	temp -> nxt = r;
}


void disp(struct dNode *q)
{
	printf("\n");

	while (q != NULL)
	{
		printf("%d ", q -> data);
		q = q -> nxt;
	}
}


void revdisp(struct dNode *q)
{
	printf("\n");

	while (q != NULL)
		q = q -> nxt;
	while (q != NULL)
	{
		printf("%d ", q -> data);
		q = q -> prv;
	}
}


int count(struct dNode * q)
{
	int c = 0;

	while (q != NULL)
	{
		q = q -> nxt;
		c++;
	}

	return c;
}


void del(struct dNode **q, int num)
{
	struct dNode *old, *temp, *third;

	temp = *q ;

	while (temp != NULL)
	{
		if (temp -> data == num)
		{
			if (temp == *q)
			{
				*q = temp -> nxt;
				(*q) -> prv = NULL;
			}
			else
			{
				old -> nxt = temp -> nxt;
				third -> prv = old;
			}
			free(temp);
			return;
		}
		else
		{
			old = temp;
			temp = temp -> nxt;
			third = temp -> nxt;
		}
	}
	printf ("\nElement %d not found", num);
}