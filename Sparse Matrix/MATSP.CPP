#include <conio.h>
#include <stdio.h>

int s[20][3];

void print_matrix()
{
	int i,j,k,flg;
	for(i=0;i<s[0][0];i++)
	{
		for(j=0;j<s[0][1];j++)
		{
			flg=1;
			for(k=1;k<=s[0][2];k++)
			{
				if(s[k][0]==i&&s[k][1]==j)
				{
					flg=0;
					printf("%d\t",s[k][2]);
					break;
				}
			}
			if(flg==1)
			printf("0\t");
		}
		printf("\n\n");
	}
}


void main()
{
	clrscr();
	printf("Enter c:\n");
	scanf("%d",&s[0][0]);
	printf("Enter r:\n");
	scanf("%d",&s[0][1]);
	printf("Enter no of non zero elements:\n");
	scanf("%d",&s[0][2]);
	printf("Enter sparse matrix details:\n");
	int i,j;
	for(i=1;i<=s[0][2];i++)
		for(j=0;j<3;j++)
			scanf("%d",&s[i][j]);
	printf("\nMatrix :\n");
	print_matrix();
	getch();
}
