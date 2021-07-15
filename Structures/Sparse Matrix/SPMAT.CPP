
#include <conio.h>
#include <stdio.h>

#define MAX 10


void pr_sp(int b[MAX][3]);
void cr_sp(int a[10][10], int r, int c, int b[MAX][3]);


void main()
{
    clrscr();
    int a[10][10], b[MAX][3], i, j, r, c;
    printf("\nEnter number of rs and cs of matrix: ");
    scanf("%d %d", &r, &c);
    printf("\nEnter elements of matrix\n");
    for (i = 0; i < r; i++)
    {
	for (j = 0; j < c; j++)
	{
	    printf("[%d][%d]: ", i, j);
	    scanf("%d", &a[i][j]);
	}
    }
    cr_sp(a, r, c, b);
    pr_sp(b);
    getch();
}


void cr_sp(int a[10][10], int r, int c, int b[MAX][3])
{
    int i, j, k;
    k = 1;
    b[0][0] = r;
    b[0][1] = c;
    for (i = 0; i < r; i++)
    {
	for (j = 0; j < c; j++)
	{
	    if (a[i][j] != 0)
	    {
		b[k][0] = i;
		b[k][1] = j;
		b[k][2] = a[i][j];
		k++;
	    }
	}
	b[0][2] = k - 1;
    }
}

void pr_sp(int b[MAX][3])
{
    int i, c;
    c = b[0][2];
    printf("\nSparse form - \n");
    for (i = 0; i <= c; i++)
    {
	printf("%d\t%d\t%d\n", b[i][0], b[i][1], b[i][2]);
    }
}
