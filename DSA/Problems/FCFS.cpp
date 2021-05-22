#include<stdio.h>
#include<conio.h>
int main()
{
	int p,bt[10],wt[10],tat[10];
	int avgwt=0,avgtat=0;
	printf("Enter no. of process(Max 10):");
	scanf("%d",&p);
	for(int i=0;i<p;i++)
	{
		printf("Enter burst time for process %d:",i+1);
		scanf("%d",&bt[i]);
	}
	wt[0]=0;
	printf("\n\nWaiting time of proces 0:%d\n\n",wt[0]);
	for(int i=1;i<p;i++)
	{
		wt[i]=wt[i-1]+bt[i-1];
		printf("Waiting time for proces %d:%d\n\n",i+1,wt[i]);
		avgwt=avgwt+wt[i];
	}
	for(int i=0;i<p;i++)
	{
		tat[i]=wt[i]+bt[i];
		printf("Turnaround time for proces %d:%d\n\n",i+1,tat[i]);
		avgtat=avgtat+tat[i];
	}
	avgwt/=p;
	avgtat/=p;
	printf("Average Waiting Time:%d\n",avgwt);
	printf("Average Turnaround Time:%d\n",avgtat);
	getch();
	return 0;
}
	
	
