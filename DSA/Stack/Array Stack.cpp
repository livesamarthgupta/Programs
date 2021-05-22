#include<stdio.h>
#include<conio.h>
#define mxsize 10
int stack[10],top=-1;
void push()
{
	int item;
	if(top==mxsize-1)
	printf("Stack is overflow!!");
	else
	{
		printf("Enter item to insert:");
		scanf("%d",&item);
		top=top+1;
		stack[top]=item;
	}
}
void pop()
{
	if(top==-1)
	printf("Stack is underflow!!");
	else
	{
		printf("Item deleted is %d",stack[top]);
		top=top-1;
	}
}
void traverse()
{
	int i;
	for(i=0;i<top;i++)
	{
		printf("%d\n",stack[i]);
	}
}
int main()
{
	int n;
	char ch='y';
	do
	{
		printf("Enter a choice:\n1:Push\n2:Pop\n3:Traverse\n::");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				traverse();
				break;
			default:
				printf("Wrong choice!!");
		}
		printf("Do you wish to continue:(y/n):");
		scanf("%c",&ch);
	}while(ch=='y');
getch();
return 0;
}
			
