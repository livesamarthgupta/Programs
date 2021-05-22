#include<bits/stdc++.h>
using namespace std;

bool compare(pair<string, int> emp1, pair<string, int> emp2) {
	if(emp1.second == emp2.second)
		return emp1.first < emp2.first;
	return emp1.second > emp2.second;
}

int main() {
	int x;
	cin>>x;
	
	int n;
	cin>>n;
	vector<pair<string, int>> emp;
	for(int i = 0; i < n; i++) {
		string name;
		int sal;
		cin>>name;
		cin>>sal;
		if(sal >= x) {
			emp.push_back(make_pair(name, sal));
		}
	}
	
	sort(emp.begin(), emp.end(), compare);
	
	for(auto i = emp.begin(); i != emp.end(); i++) {
		cout<<(*i).first<<" ";
		cout<<(*i).second<<endl;
	}
	
	
	
	return 0;
}
