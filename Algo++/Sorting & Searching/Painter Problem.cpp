#include<bits/stdc++.h>
using namespace std;


bool isPossible(int board[], int n, int painters, long long curr_time) {
	long long painter = board[0];
	int cnt = 1;
	for(int i = 1; i < n; i++) {
		if(painter + board[i] > curr_time) {
			cnt++;
			if(cnt > painters) return false;
			painter = board[i];
		} else {
			painter += board[i];
		}
	}
	return true;
}


int time_taken(int board[], int n, int painters) {
	int s = board[n - 1];
	long long sum = 0;
	for(int i = 0; i < n; i++)
		sum += board[i];
	long long e = sum;
	int ans = s;
	
	while(s <= e) {
		long long mid = s + (e - s) / 2;
		if(isPossible(board, n, painters, mid)) {
			ans = mid % 10000003;
			e = mid - 1;
		} else
		 	s = mid + 1;
	}
	
	return ans;
}



int main() {
	int n, k, t;
	cin>>n>>k>>t;
	int board[n];
	for(int i = 0; i < n; i++) {
		cin>>board[i];
		board[i] = board[i] * t;
	}
	sort(board, board + n);
		
	cout<<time_taken(board, n, k)<<endl;
	
	
	return 0;
}
