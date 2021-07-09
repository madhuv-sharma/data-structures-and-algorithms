#include <stdio.h>
#include <conio.h>
#include <string.h>
struct dNode
{
	int data;
	struct dNode *nxt, *prv;
};
void main()
{
	clrscr();
	struct dNode *p, N1, N2, N3, N4, N5, N6, N7;
	p=NULL;
	N1.prv = NULL;
	N1.data = 1;
	N1.nxt = &N2;
	N2.prv = &N1;
	N2.data = 2;
	N2.nxt = &N3;
	N3.prv = &N2;
	N3.data = 3;
	N3.nxt = &N4;
	N4.prv = &N3;
	N4.data = 4;
	N4.nxt = NULL;
	p = &N1;
	printf("Original:\n");
	while(p != NULL)
	{
		printf("%d\n", p->data);
		p = p->nxt;
	}
	p = &N4;
	printf("Rev:\n");
	while(p != NULL)
	{
		printf("%d\n", p->data);
		p = p->prv;
	}
	/**
	printf("\nAdding in the beginning:\n");
	N5.data = 5;
	strcpy(N5.name, "I J");
	N5.nxt = &N1;
	p = &N5;
	while(p != NULL)
	{
		printf("%d\t%s\n", p->data, p->name);
		p = p->nxt;
	}
	printf("\nAdding in b/w:\n");
	p = &N5;
	N2.nxt = &N6;
	N6.data = 6;
	strcpy(N6.name, "K L");
	N6.nxt = &N3;
	while(p != NULL)
	{
		printf("%d\t%s\n", p->data, p->name);
		p = p->nxt;
	}
	printf("\nDeleting first:\n");
	p=&N1;
	while(p != NULL)
	{
		printf("%d\t%s\n", p->data, p->name);
		p = p->nxt;
	}
	printf("\nDeleting middle and end:\n");
	p=&N1;
	N2.nxt = &N3;
	N4.nxt = NULL;
	while(p!=NULL)
	{
		printf("%d\t%s\n", p->data, p->name);
		p=p -> nxt;
	}*/
	getch();
}

