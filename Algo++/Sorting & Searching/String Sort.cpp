#include<bits/stdc++.h>
using namespace std;

bool compare(string str1, string str2) {
	if(str1.find(str2) == 0) {
		return str1.length() > str2.length();
	} else
		return str1 < str2;
}

int main() {
	int n;
	cin>>n;
	
	string str[n];
	for(int i = 0; i < n; i++)
		cin>>str[i];
		
	sort(str, str+n, compare);
	
	for(int i = 0; i < n; i++)
		cout<<str[i]<<endl;
	
	
	return 0;
}
