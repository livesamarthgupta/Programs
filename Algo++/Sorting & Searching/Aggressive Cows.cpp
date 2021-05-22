#include<bits/stdc++.h>
using namespace std;

bool isPossible(int x[], int n, int c, int curr_dis) {
	int last_cow = x[0];
	int cnt = 1;
	for(int i = 1; i < n; i++) {
		if(x[i] - last_cow >= curr_dis) {
			last_cow = x[i];
			cnt++;
			if(c == cnt) 	return true;
		} 
	}
	
	return false;
}

int find_max_distance(int x[], int n, int c) {
	int s = 0;
	int e = x[n - 1] - x[0];
	int ans = 0;
	
	while(s <= e) {
		int mid = (s + e) / 2;
		if(isPossible(x, n, c, mid)) {
			ans = mid;
			s = mid + 1;
		} else
		 	e = e - 1;
	}
	
	return ans;
	
}

int main() {
	int n, c;
	cin>>n>>c;
	int x[n];
	for(int i = 0; i < n; i++)
		cin>>x[i];
		
	sort(x, x + n);
	
	cout<<find_max_distance(x, n, c)<<endl;
	
	
	
	return 0;
}
