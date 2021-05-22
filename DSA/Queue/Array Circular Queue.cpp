#include<stdio.h>
#include<conio.h>
#define mxsize 10
int queue[10],front=0,rear=0;
void insert()
{
	int item;
	if(front==(rear+1)%mxsize)
	{
		printf("Queue is overflow!!");
	}
	else
	{
		printf("Enter any item to insert:");
		scanf("%d",&item);
		if((front==0)&&(rear==0))
		{
			front=1;
			rear=1;
		}
		else
		rear=(rear+1)%mxsize;
		queue[rear]=item;
	}
}
void del()
{
	if((front==0)&&(rear==0))
	{
		printf("Queue is underflow!!");
	}
	else
	{
		printf("Deleted item is %d",queue[front]);
		if(front==rear)
		{
			front=0;
			rear=0;
		}
		else
		front=(front+1)%mxsize;
	}
}
int main()
{
	int n;
	char ch;
	do
{
	printf("Enter a choice:\n1:Insert\n2:Delete\n::");
	scanf("%d",&n);
	switch(n)
	{
		case 1:
			insert();
			break;
		case 2:
			del();
			break;
		default:
			printf("Wrong choice!!");
	}	
	printf("Do you wish to continue(y/n):");
	scanf("%c",&ch);
	
}while(ch=='y');
getch();
return 0;
}
