#include<stdio.h>
#include<conio.h>

int main()
{
	int arr1[3][3],arr2[3][3],sum[3][3]={0},mul[3][3]={0};
	printf("Enter the first 2D array(max size 10):\n");
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			scanf("%d",&arr1[i][j]);
		}
	}
	printf("Enter the second 2D array(max size 10):\n");
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			scanf("%d",&arr2[i][j]);
		}
	}
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			sum[i][j]=arr1[i][j]+arr2[i][j];
		}
	}
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			for(int k=0;k<3;k++)
			{
				mul[i][j]=mul[i][j]+arr1[i][k]*arr2[k][j];
			}
		}
	}
	printf("SUM OF 2D ARRAYS:\n");
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			printf("%d\t",sum[i][j]);
		}
		printf("\n");
	}
	printf("MULTIPLICATION OF 2D ARRAYS:\n");
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			printf("%d\t",mul[i][j]);
		}
		printf("\n");
	}
	getch();
	return 0;
}
