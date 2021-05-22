#include<bits/stdc++.h>
using namespace std;

//spiral print of 2D array


void spiralPrint(int a[][100], int m, int n) {
	int startRow = 0;
	int startCol = 0;
	int endRow = m - 1;
	int endCol = n - 1;
	
	
	while(startRow <= endRow && startCol <= endCol) {
		for(int i = startCol; i <= endCol; i++) {
			cout<<a[startRow][i]<<" ";
		}
		startRow++;
		
		for(int i = startRow; i <= endRow; i++){
			cout<<a[i][endCol]<<" ";
		}
		endCol--;
		
		if(startRow < endRow) {
			for(int i = endCol; i >= startCol; i--) {
				cout<<a[endRow][i]<<" ";
			}
		endRow--;
		}
		
		if(startCol < endCol) {
			for(int i = endRow; i >= startRow; i--) {
				cout<<a[i][startCol]<<" ";
			}
		startCol++;
		}
		
	}
	
	
}

int main() {
	int a[100][100];
	int m, n;
	cin>>m>>n;
	
	int val = 1;
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			a[i][j] = val;
			val += 1;
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	
	
	spiralPrint(a, m, n);
	
	
	
	
	return 0;
}
