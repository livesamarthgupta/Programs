#include<bits/stdc++.h>
using namespace std;

int main() {
	int N, M, K, S;
	cin>>N>>M>>K>>S;
	
	char arr[N][M];
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			cin>>arr[i][j];
			
			
	bool success = true;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			
			if(S < K) {
				success = false;
				break;
			}
			
			if(arr[i][j] == '.') {
				S -= 2;
			} 
			else if(arr[i][j] == '*') {
				S += 5;
			} 
			else {
				break;
			}
			
			if(j != M - 1) {
				S -= 1;
			}
		}
	}
	
	if(success) {
		cout<<"Yes"<<endl;
		cout<<S<<endl;
	} else 
		cout<<"No"<<endl;
		
	return 0;
}
