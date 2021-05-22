#include<bits/stdc++.h>

using namespace std;

int sorted[100];

int main(){
	int n;
	int X;
	int maximum;
	cout<<"Enter no. of elements:";
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>X;
		++sorted[X];
		maximum = max(maximum, X);
	}
	
	
	for(int i = 0; i <= maximum; i++)
	{
		if(sorted[i] > 0)
		{
			for(int j = 0; j < sorted[i]; j++)
			cout<<i<<" ";
		}
	}

	return 0;
}

