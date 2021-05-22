#include<stdio.h>
#include<conio.h>
int main()
{
	int n,a[10],temp,j;
	printf("Enter the size of list:");
	scanf("%d",&n);
	printf("\nEnter the elements of list:\n");
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(int i=1;i<n;i++)
	{
		temp=a[i];
		j=i-1;
		while(temp<a[j]&&j>=0)
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=temp;
	}
	printf("List After Sorting:\n");
	for(int i=0;i<n;i++)
	printf("%d\t",a[i]);
	getch();
	return 0;
}
