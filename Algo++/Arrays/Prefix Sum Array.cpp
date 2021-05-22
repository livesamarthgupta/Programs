#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin>>n>>m;
	
	int arr[n][m];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin>>arr[i][j];
			

	//Making Prefix sum array
	for(int i = 0; i < n; i++) {
		for(int j = 1; j < m; j++) {
			arr[i][j] += arr[i][j - 1];
		}
	}
	
	for(int j = 0; j < m; j++) {
		for(int i = 1; i < n; i++) {
			arr[i][j] += arr[i - 1][j];
		}
	}
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			cout<<arr[i][j];
			cout<<endl;
	}
		
	
	
	return 0;
}
