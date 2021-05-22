#include<stdio.h>
#include<conio.h>
int main()
{
	int n,a[10],ele,flag;
	printf("Enter the size of list:");
	scanf("%d",&n);
	printf("\nEnter the list:\n");
	for(int i=0;i<n;i++)
	{
	scanf("%d",&a[i]);
    }
    printf("\nEnter the element to search for:");
    scanf("%d",&ele);
    for(int i=0;i<n;i++)
	{
	if(ele==a[i])
	{
		printf("\nElement Found at position %d!!", i+1);
		flag=1;
		break;
    }
    flag=0;
	}
	if(flag==0)
	{
		printf("\nElement not found!!");
	}
	getch();
	return 0;
}
    
	
