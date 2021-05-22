#include<bits/stdc++.h>
using namespace std;


bool compare(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		vector<pair<int, int>> activity;
		for(int i = 0; i < n; i++) {
			int first;
			cin>>first;
			int second;
			cin>>second;
			activity.push_back(make_pair(first, second));
		}
		
		sort(activity.begin(), activity.end(), compare);
		int end = activity[0].second;
		int count = 1;
		for(int i = 1; i < n; i++)  {
			if(activity[i].first > end) {
				end = activity[i].second;
				count++;
			}
		}
		cout<<count<<endl;
	}
	
	
	return 0;
}
