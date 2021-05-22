#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin>>n>>m;
	
	int arr[n][m];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin>>arr[i][j];
	
	int startRow = 0;
	int startCol = 0;
	int endRow = n - 1;
	int endCol = m - 1;
	
	while(startRow <= endRow && startCol <= endCol) {
		
		for(int i = startRow; i <= endRow; i++)
			cout<<arr[i][startCol]<<", ";
		startCol++;
		
		for(int i = startCol; i <= endCol; i++)
			cout<<arr[endRow][i]<<", ";
		endRow--;
		
		if(startCol <= endCol) {
			for(int i = endRow; i >= startRow; i--)
				cout<<arr[i][endCol]<<", ";
			endCol--;
		}
		
		
		if(startRow <= endRow) {
			for(int i = endCol; i >= startCol; i--)
				cout<<arr[startRow][i]<<", ";
			startRow++;
		}
		
		
	}
	cout<<"END"<<endl;
	
	return 0;
}
