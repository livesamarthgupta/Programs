#include<bits/stdc++.h>
using namespace std;

int find_max_base(long long n, long long k) {
	long long s = 0; 
	long long e = n;
	int answer = 1;
	
	while(s <= e) {
		long long mid = (s + e) / 2;
		if(pow(mid, k) <= n) {
			answer = mid;
			s = mid + 1;
		} else
			e = mid - 1;
	}
	
	return answer;
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		long long n, k;
		cin>>n>>k;
		
		cout<<find_max_base(n, k)<<endl;
	}
	
	
	return 0;
}
