#include<bits/stdc++.h>
using namespace std;

bool myCompare(string X, string Y) {
	string XY = X.append(Y);
	string YX = Y.append(X);
	
	return XY.compare(YX) > 0 ? true : false;
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		vector<string> s;
		int n;
		cin>>n;
		for(int i = 0; i < n; i++) {
			string temp;
			cin>>temp;
			s.push_back(temp);
		}
		sort(s.begin(), s.end(), myCompare);
		for(auto str: s)
			cout<<str;
		cout<<endl;
	}
}
