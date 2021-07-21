#include <iostream>
#include <cstdlib>
#include <ctime>


typedef struct slist_
{
	int val;
	struct slist_ *next; 
} slist;
 

slist *radixsort(slist *L, int t) 
{
	int i, j, d, m=1;
	slist *temp, *head[10], *tail[10];
	for (j=1; j<=t; j++) 
	{ 
		for (i=0; i<=9; i++)
		{
			head[i] = NULL;
			tail[i] = NULL;
		}
		while ( L != NULL ) 
		{
			d = ((int)(L->val/m))%10;
			temp = L;
			L = L->next;
			temp->next = NULL;
			if (head[d]!= NULL)
			{
				tail[d]->next = temp;
 				tail[d] = temp;
			}
			else
			{
				head[d] = temp;  // Point to the new head
				tail[d] = temp;  // Point to the new tail
			}
		}
		d=0;
		while (head[d]==NULL)
			d++;
		L = head[d];
		temp = tail[d];
		d++;
		while (d<10)
		{
			if (head[d]!=NULL)
			{
				temp->next = head[d];
				temp = tail[d];
			}
			d++;
		}
		m = m*10;
	}
	return L;
}


main()
{
	srand( (unsigned int)time(NULL) );
	int i,size=20, *n, max=-1, t=0;
	n = new int[size];
	slist *start=NULL,*end=NULL,*temp;
	for (i=0; i<size; i++)
	{
		n[i] = rand();
	}
	for (i=0; i<size; i++)
	{
		if (n[i] > max)
			max = n[i];
		temp = new slist;
 		temp->val = n[i];
		temp->next = NULL;
		if (start != NULL)
		{
			end->next = temp;
			end = temp;
		}
		else
		{
			start = temp;
			end = temp;
		}
	}
	while (max>0)
	{
		t=t+1;
		max=max/10; 
	}
	start = radixsort(start, t);
	cout << "after radix sort.\n";
	temp = start;
	for (i=0; i<size; i++)
	{
		cout << temp->val << "\n";
		temp = temp->next;
	}
	return 0;
}