#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node
{
	int info;
	struct node *link;
};

int a=1,pos,steps=1;
node *head,*p,*q;

void insert(struct node *t)
{
	    t->link=(node*)malloc(sizeof(node));
		t=t->link;
		printf("Enter the %d element:",++a);
		scanf("%d",t->info);
		t->link=NULL;
}

void del(struct node *t)
{
	p=t;
	printf("Enter the position to delete:");
	scanf("%d",&pos);
	while(steps<pos-1)
	{
		p=p->link;
		steps=steps+1;
	}
	q=p->link;
	printf("Deleted item is %d",q->info);
	p->link=q->link;
}

void display(struct node *t)
{
	printf("Traverse:\n");
	while(t->link==NULL)
	{
		printf("%d\n",t->info);
		t=t->link;
	}
}
	

int main()
{
	int n;
	char ch;
	head=(node*)malloc(sizeof(node));
	printf("Enter the %d element:",a);
	scanf("%d",head->info);
	head->link=NULL;
	do
	{
		printf("\nEnter a choice:\n1:Insert\n2:Delete\n3:Traverse\n::");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				insert(head);
				break;
			case 2:
				del(head);
				break;
			case 3:
				display(head);
				break;
	    }
	    printf("Do you wish to continue:(y/n):");
	    scanf("%d",&ch);
	}while(1);
getch();
return 0;
}
	
	
	
	
		
		
