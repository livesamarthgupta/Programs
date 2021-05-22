#include<bits/stdc++.h>
using namespace std;

void staircaseSearch(int a[][100], int n, int m, int key) {
	
	int i = 0, j = n - 1;
	while(i < m && j > -1) {
		if(a[i][j] == key)
		{
			cout<<"Element found at position ["<<i<<"]["<<j<<"]"<<endl;
			return;
		} else if(a[i][j] < key) {
			i++;
		} else if(a[i][j] > key) {
			j--;
		}
	}
	cout<<"Not Present"<<endl;
}

int main() {
	int a[100][100];
	int n, m;
	cin>>m>>n;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin>>a[i][j];
		}
	}
	
	int key;
	cin>>key;
	
	staircaseSearch(a, n, m, key);
	
	return 0;
}
