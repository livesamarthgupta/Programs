#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	
	vector<pair<int, int>> factors;
	int cnt = 0;
	
	for(int i = 2; i * i <= n; i++) {
		if(n % i == 0) {
			cnt = 0;
			while(n % i == 0) {
				cnt++;
				n = n / i;
			}
			factors.push_back(make_pair(i, cnt));
		}
	}
	if(n != 1)
		factors.push_back(make_pair(n, 1));
	
	for(auto i = factors.begin(); i != factors.end(); i++)
		cout<<(*i).first<<"^"<<(*i).second<<endl;
	

	return 0;
}
