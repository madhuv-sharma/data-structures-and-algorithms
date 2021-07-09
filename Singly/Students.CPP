#include<alloc.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct Student
{
	int rno;
	char nm[30];
	int mks;
};


struct Node
{
	struct Student* s;
	struct Node* lnk ;
};


void append(struct Node **, struct Student);
void addatbeg(struct Node **, struct Student);
void addafter(struct Node *, int, struct Student);
void disp(struct Node *);
int count(struct Node *);
void del(struct Node **, int);


void main()
{
	clrscr();

	struct Node *p ;
	p = NULL;

	struct Student s;

	printf ("\nNo. of elements in the Linked List = %d", count(p));

	s.rno = 1;
	strcpy(s.nm, "AB");
	s.mks = 36;
	append(&p, s);

	s.rno = 2;
	strcpy(s.nm, "DEF");
	s.mks = 92;
	append(&p, s);

	disp(p);

	s.rno = 0;
	strcpy(s.nm, "XYZ");
	s.mks = 86;
	addatbeg(&p, s);

	disp(p);

	s.rno = 4;
	strcpy(s.nm, "ZA");
	s.mks = 89;
	addafter(p, 1, s);

	disp(p);
	printf ("\nNo. of elements in the Linked List = %d", count(p)) ;

	del(&p, 0);
	del(&p, 1);
	del(&p, 10);

	disp(p);
	printf ("\nNo. of elements in the Linked List = %d", count(p)) ;

	getch();
}


void append(struct Node **q, struct Student x)
{
	struct Node *temp, *r;

	if(*q == NULL)
	{
		temp = (struct Node *)malloc(sizeof(struct Node)) ;
		temp -> s -> rno = x.rno;
		strcpy(temp -> s -> nm, x.nm);
		temp -> s -> mks = x.mks;
		temp -> lnk = NULL ;
		*q = temp ;
	}
	else
	{
		temp = *q;

		while(temp -> lnk != NULL)
			temp = temp -> lnk;

		r = (struct Node *)malloc(sizeof(struct Node));
		r -> s -> rno = x.rno;
		strcpy(r -> s -> nm, x.nm);
		r -> s -> mks = x.mks;
		r -> lnk = NULL;
		temp -> lnk = r;
	}
}

void addatbeg(struct Node **q, struct Student x)
{
	struct Node *temp;

	temp = (struct Node *)malloc(sizeof(struct Node));

	temp -> s -> rno = x.rno;
	strcpy(temp -> s -> nm, x.nm);
	temp -> s -> mks = x.mks;
	temp -> lnk = *q ;
	*q = temp ;
}


void addafter (struct Node *q, int loc, struct Student x)
{
	struct Node *temp, *r;
	int i;

	temp = q;
	for(i = 0 ; i < loc ; i++)
	{
		temp = temp -> lnk;

		if (temp == NULL)
		{
			printf ("\nThere are less than %d elements in list", loc);
			return ;
		}
	}

	r = (struct Node *)malloc(sizeof(struct Node));
	r -> s -> rno = x.rno;
	strcpy(r -> s -> nm, x.nm);
	r -> s -> mks = x.mks;
	r -> lnk = temp -> lnk;
	temp -> lnk = r;
}


void disp (struct Node *q)
{
	printf ("\n") ;

	while (q != NULL)
	{
		printf ("%d\t%s\t%d\n", q -> s -> rno, q -> s -> nm, q -> s -> mks);
		q = q -> lnk;
	}
}


int count (struct Node * q)
{
	int c=0;

	while (q != NULL)
	{
		q = q -> lnk;
		c++;
	}
	return c;
}


void del(struct Node **q, int num)
{
	struct Node *old, *temp;

	temp = *q;

	while(temp != NULL)
	{
		if(temp -> s -> rno == num)
		{
			if(temp == *q)
				*q = temp -> lnk;
			else
				old -> lnk = temp -> lnk;
			free(temp);
			return ;
		}
		else
		{
			old = temp;
			temp = temp -> lnk;
		}
	}
	printf ("\nElement %d not found", num);
}