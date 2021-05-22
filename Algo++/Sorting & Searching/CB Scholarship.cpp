#include<bits/stdc++.h>
using namespace std;


long long find_max_stud(long long n, long long m, long long x, long long y) {
	long long s = 0;
	long long e = n;
	long long ans = 0;
	
	while(s <= e) {
		long long mid = (s + e) / 2;
		if(mid * x <= m + (y * (n - mid))) {
			ans = mid;
			s = mid + 1;
		} else
			e = mid - 1;
	}
	
	return ans;
}

int main() {
	long long n, m, x, y;
	cin>>n>>m>>x>>y;
	
	cout<<find_max_stud(n, m, x, y)<<endl;
	
	
	
	return 0;
}
