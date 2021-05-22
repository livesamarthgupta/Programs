#include<stdio.h>
#include<conio.h>
#define mxsize 10
int queue[10],front=0,rear=0;
void insert()
{
	int item;
	if(rear==mxsize)
	{
		printf("Queue is overflow!!");
	}
	else
	{
		printf("Enter an item to insert:");
		scanf("%d",&item);
		if((front==0)&&(rear==0))
		{
			front=1;
			rear=1;
		}
		else
		{
			rear=rear+1;
		}
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
		front=front+1;
	}
}
void traverse()
{
	int i;
	for(i=front;i<=rear;i++)
	{
		printf("%d\n",queue[i]);
	}
}
int main()
{
	int n;
	char ch='y';
	do
	{
		printf("Enter a choice:\n1:Insert\n2:Delete\n3:Traverse\n::");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				insert();
				break;
			case 2:
				del();
				break;
			case 3:
				traverse();
				break;
			default:
				printf("Wrong Choice!!");
		}
		printf("Do you wish to comntinue:(y/n):");
		scanf("%c",&ch);
	}while(ch='y');
getch();
return 0;
}
