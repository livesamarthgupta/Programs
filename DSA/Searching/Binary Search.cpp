#include<stdio.h>
#include<conio.h>
int main()
{
	int n,a[10],ele,flag,mid,f,l;
	printf("Enter the size of list:");
	scanf("%d",&n);
	printf("\nEnter the list:\n");
	for(int i=0;i<n;i++)
	{
	scanf("%d",&a[i]);
    }
    printf("\nEnter the element to search for:");
    scanf("%d",&ele);
    f=0;
    l=n-1;
    while(f<=l)
    {
    	mid=(f+l)/2;
    	if(a[mid]==ele)
    	{
    		printf("\nElement found at position %d!!",mid+1);
    		flag=1;
    		break;
    	}
    	else if(ele<a[mid])
    		l=mid-1;
    	else if(ele>a[mid])
    	    f=mid+1;
    	    
			flag=0;
    }
    if(flag==0)
    printf("\nElement not found!!");
    getch();
    return 0;
}
