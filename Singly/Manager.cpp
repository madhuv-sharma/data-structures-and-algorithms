#include <alloc.h>
#include <conio.h>
#include <stdio.h>


struct Node
{
	int data;
	struct Node* lnk;
};


void append(struct Node **, int);
void addatbeg(struct Node **, int);
void addafter(struct Node *, int, int);
void disp(struct Node *);
int count(struct Node *);
void del(struct Node **, int);


void main( )
{
	clrscr();

	struct Node *p;
	p = NULL;  /* empty lnked list */

	printf("\nNo. of elements in the Linked List = %d", count ( p )) ;
	append(&p, 14) ;
	append(&p, 30) ;
	append(&p, 25) ;
	append(&p, 42) ;
	append(&p, 17) ;

	disp (p) ;

	addatbeg (&p, 999) ;
	addatbeg (&p, 888) ;
	addatbeg (&p, 777) ;

	disp (p) ;

	addafter (p, 7, 0) ;
	addafter (p, 2, 1) ;
	addafter (p, 5, 99) ;

	disp (p) ;
	printf ("\nNo. of elements in the Linked List = %d", count(p)) ;

	delete(&p, 99) ;
	delete(&p, 1) ;
	delete(&p, 10) ;

	disp(p) ;
	printf ("\nNo. of elements in the Linked List = %d", count(p)) ;

	getch();
}


/* adds a Node at the end of a lnked list */
void append (struct Node **q, int num)
{
	struct Node *temp, *r ;

	if (*q == NULL) /* if the list is empty, create first Node */
	{
		temp = (struct Node*) malloc(sizeof(struct Node)) ;
		temp -> data = num ;
		temp -> lnk = NULL ;
		*q = temp ;
	}
	else
	{
		temp = *q ;

		/* go to last Node */
		while (temp -> lnk != NULL)
			temp = temp -> lnk ;

		/* add Node at the end */
		r = (struct Node*) malloc(sizeof(struct Node)) ;
		r -> data = num ;
		r -> lnk = NULL ;
		temp -> lnk = r ;
	}
}


/* adds a new Node at the beginning of the lnked list */
void addatbeg (struct Node **q, int num)
{
	struct Node *temp ;

	/* add new Node */
	temp = (struct Node*) malloc(sizeof(struct Node)) ;

	temp -> data = num ;
	temp -> lnk = *q ;
	*q = temp ;
}


/* adds a new Node after the specified number of Nodes */
void addafter (struct Node *q, int loc, int num)
{
	struct Node *temp, *r ;
	int i ;

	temp = q ;
	/* skip to desired portion */
	for (i = 0 ; i < loc ; i++)
	{
		temp = temp -> lnk ;

		/* if end of lnked list is encountered */
		if (temp == NULL)
		{
			printf ("\nThere are less than %d elements in list", loc) ;
			return ;
		}
	}

	/* insert new Node */
	r = (struct Node*) malloc (sizeof(struct Node)) ;
	r -> data = num ;
	r -> lnk = temp -> lnk ;
	temp -> lnk = r ;
}


/* displays the contents of the lnked list */
void disp (struct Node *q)
{
	printf ("\n") ;

	/* traverse the entire lnked list */
	while (q != NULL)
	{
		printf ("%d ", q -> data) ;
		q = q -> lnk ;
	}
}


/* counts the number of Nodes present in the lnked list */
int count (struct Node * q)
{
	int c = 0 ;

	/* traverse the entire lnked list */
	while (q != NULL)
	{
		q = q -> lnk ;
		c++ ;
	}

	return c ;
}


/* deletes the specified Node from the lnked list */
void del (struct Node **q, int num)
{
	struct Node *old, *temp ;

	temp = *q ;

	while (temp != NULL)
	{
		if (temp -> data == num)
		{
			/* if Node to be deleted is the first Node in the lnked list */
			if (temp == *q)
				*q = temp -> lnk ;

			/* deletes the intermediate Nodes in the lnked list */
			else
				old -> lnk = temp -> lnk ;

			/* free the memory occupied by the Node */
			free (temp) ;
			return ;
		}
		/* traverse the lnked list till the last Node is reached */
		else
		{
			old = temp ;  /* old points to the previous Node */
			temp = temp -> lnk ;  /* go to the next Node */
		}
	}
	printf ("\nElement %d not found", num) ;
}