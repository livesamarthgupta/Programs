#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin>>n>>m;
	
	int arr[n][m];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin>>arr[i][j];
			
	int key;
	cin>>key;
	bool found = false;
			
	int row = 0, col = m - 1;
	while(row < n || col > -1) {
		if(arr[row][col] == key) {
			cout<<"Found at ["<<row<<"]["<<col<<"]"<<endl;
			found = true;
			break;
		} else if(arr[row][col] < key) 
			row++;
		else if(arr[row][col] > key)
			col--;
			
	}
	
	if(!found)	
		cout<<"Not Found"<<endl;
	
	
	
	return 0;
}
