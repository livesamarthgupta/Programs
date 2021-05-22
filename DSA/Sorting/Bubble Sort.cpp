#include<stdio.h>
#include<conio.h>

int main()
{
	int arr[100],n,i,j,t;
	printf("Enter the size of list:");
	scanf("%d",&n);
	printf("\nEnter the elements in the list:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				t=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=t;
			}
		}
	}
	printf("\nElements in sorted form:\n");
	for(i=0;i<n;i++)
	{
		printf("%d",arr[i]);
	}
	getch();
	return 0;
}
