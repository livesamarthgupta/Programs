#include<bits/stdc++.h>
using namespace std;

//rotate 90 degree anti-cloclwise
//for clockwise first swap and then reverse

rotateMatrix(int a[][100], int n) {
	for(int i = 0; i < n; i++)
		reverse(a[i], a[i]+n);
		
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i < j)
				swap(a[i][j], a[j][i]);
		}
	}
}


int main() { 
	int a[100][100];
	int n;
	cin>>n;
	
	int val = 1;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			a[i][j] = val;
			val++;
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	
	rotateMatrix(a, n);
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}

	return 0;
}
