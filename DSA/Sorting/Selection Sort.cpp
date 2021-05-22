#include<bits/stdc++.h>
int main()
{
	int n,a[10],pos,small,tmp;
	printf("Enter the size of list:");
	scanf("%d",&n);
	printf("\nEnter the list:\n");
	for(int i=0;i<n;i++)
	{
	scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++)
    {
    	small=a[i];
    	pos=i;
    	for(int j=i+1;j<n;j++)
    	{
    		if(small>a[j])
    		{
    			small=a[j];
    			pos=j;
    		}
		}
		tmp=a[i];
		a[i]=a[pos];
		a[pos]=tmp;
	}
	printf("\nArray After Sorting:\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	//getch();
	return 0;
}
