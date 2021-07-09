//Designed in Turbo C++

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


void main()
{
	clrscr();

	struct Node *p;
	p = NULL; //empty linked list

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

	delete(&p, 99);
	delete(&p, 1);
	delete(&p, 10);

	disp(p);
	printf("\nNo. of elements in the Linked List = %d", count(p));

	getch();
}


// To append a Node to the Linked List
void append(struct Node **q, int num)
{
	struct Node *temp, *r;

	if(*q == NULL) // To create first Node to an empty Linked List
	{
		temp = (struct Node*) malloc(sizeof(struct Node));
		temp -> data = num;
		temp -> lnk = NULL;
		*q = temp;
	}
	else
	{
		temp = *q;

		// To go to the last Node
		while (temp -> lnk != NULL)
			temp = temp -> lnk;

		// To add a Node at the end
		r = (struct Node*) malloc(sizeof(struct Node));
		r -> data = num;
		r -> lnk = NULL;
		temp -> lnk = r;
	}
}


// To add a new Node at the beginning of the linked list
void addatbeg(struct Node **q, int num)
{
	struct Node *temp;

	// To add a new Node
	temp = (struct Node*) malloc(sizeof(struct Node));

	temp -> data = num;
	temp -> lnk = *q;
	*q = temp;
}


// To add a new Node after the specified number of Nodes
void addafter(struct Node *q, int loc, int num)
{
	struct Node *temp, *r;
	int i;

	temp = q;
	// To skip to desired portion
	for(i = 0 ; i < loc ; i++)
	{
		temp = temp -> lnk;

		// If end of the linked list is encountered
		if(temp == NULL)
		{
			printf("\nThere are less than %d elements in list", loc);
			return;
		}
	}

	// To insert new Node
	r = (struct Node*) malloc (sizeof(struct Node));
	r -> data = num;
	r -> lnk = temp -> lnk;
	temp -> lnk = r;
}


// To display the contents of the linked list
void disp(struct Node *q)
{
	printf("\n");

	// To traverse the entire linked list
	while(q != NULL)
	{
		printf("%d ", q -> data);
		q = q -> lnk;
	}
}


// To count the number of Nodes present in the linked list
int count(struct Node * q)
{
	int c = 0;

	// To traverse the entire linked list
	while(q != NULL)
	{
		q = q -> lnk;
		c++;
	}

	return c;
}


// To delete the specified Node from the linked list
void del(struct Node **q, int num)
{
	struct Node *old, *temp;

	temp = *q;

	while(temp != NULL)
	{
		if(temp -> data == num)
		{
			// If Node to be deleted is the first Node in the linked list
			if (temp == *q)
				*q = temp -> lnk;

			// To delete the intermediate Nodes in the linked list
			else
				old -> lnk = temp -> lnk;

			// To free the memory occupied by the Node
			free(temp);
			return;
		}
		// To traverse the linked list till the last Node is reached
		else
		{
			old = temp;  // 'old' points to the previous Node
			temp = temp -> lnk;  // To go to the next Node
		}
	}
	printf("\nElement %d not found", num);
}