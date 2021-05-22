#include<stdio.h>
#include<conio.h>
#include<string.h>
int front=0,rear=0;
char queue[10];
int mxsize;
void insert(char a)
{
		if((front==0)&&(rear==0))
		{
			front=1;
			rear=1;
		}
		else
		{
			rear=(rear+1)%mxsize;
		}
		queue[rear]=a;
}
void del()
{
	    if(front==rear)
		{
			front=0;
			rear=0;
		}
		else
		front=(front+1)%mxsize;
}
int traverse(char a)
{
	int i;
	for(i=0;i<=mxsize;i++)
	{
		if(queue[i]==a)
		return 1;
	}
}
int main()
{
	int t=0,count=0,n;
	char a[20],i;
	printf("Enter the no. of frames:");
	scanf("%d",&mxsize);
	printf("Enter the string(Max 20):");
	scanf("%s",&a);
	n=strlen(a);
	for(int j=0;j<n;j++)
	{
		i=a[j];
		t=traverse(i);
		if(t!=1)
		{
			if(front!=(rear+1)%mxsize)
			{
				insert(i);
			}
			else
			{
				del();
				insert(i);
			}
			count++;
		}
	}
	printf("Total Page fault:%d",count);
	getch();
	return 0;
}
