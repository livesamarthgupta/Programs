#include<stdio.h>
#include<conio.h>

int main()
{
	int arr[3][3],tran[3][3];
	printf("Enter elements of array:\n");
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	printf("Transpose of Matrix:\n");
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			tran[i][j]=arr[j][i];
			printf("%d\t",tran[i][j]);
		}
		printf("\n");
	}
	getch();
	return 0;
}
