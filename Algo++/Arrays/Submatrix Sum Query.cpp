#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin>>n>>m;
	
	int arr[n][m];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin>>arr[i][j];
			

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
		
	
	int q;
	cin>>q;
	
	while(q > 0) {
		q--;
		int li, lj, ri, rj;
		cin>>li>>lj>>ri>>rj;
		int sum;
		if(li != 0 || lj != 0)
			sum = arr[ri][rj] - arr[li - 1][rj] - arr[ri][lj - 1] + arr[li - 1][lj - 1];
		else
			sum = arr[ri][rj];
		cout<<sum<<endl;
	}
	
	
	
	return 0;
}
