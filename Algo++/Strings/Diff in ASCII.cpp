#include<bits/stdc++.h>
using namespace std;

int main() {
	string str;
	cin>>str;
	
	int diff[str.size() - 1];
	int index = 0;
	for(int i = 1; i < str.size(); i++) {
		diff[index++] = str[i] - str[i - 1];
	}
	
	index = 0;
	for(int i = 0; i < str.size(); i++) {
		cout<<str[i];
		if(i != str.size() - 1)
		cout<<diff[index++];
	}
	cout<<endl;
	
	
	
	return 0;
}
