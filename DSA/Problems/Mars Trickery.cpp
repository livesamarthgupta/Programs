#include<iostream>

using namespace std;
int A[100], B[100], auxB, Aelements, queries;
int main(){
	int left, right, X;
	cout<<"Enter no. of elements:";
	cin>>Aelements;
	for(int i = 0; i < Aelements; i++)
	cin>>A[i];
	cout<<"Enter no. of queries:";
	cin>>queries;
	for(int i = 0; i < queries; i++)
	{
		cin>>left>>right>>X;
		B[left] += X;
		B[right + 1] -= X;
	}
	for(int i = 0; i < Aelements; i++)
	{
		auxB += B[i];
		A[i] += auxB;
		cout<<A[i]<<" ";
	}

	return 0;
}

