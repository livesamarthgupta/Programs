#include<bits/stdc++.h>
using namespace std;

int main() {
	string str;
	cin>>str;
	
	for(int i = 0; i < str.size(); i++) {
		if(i != 0 && (str[i] >= 'A' && str[i] <= 'Z'))
			cout<<endl;
		cout<<str[i]; 
	}
	
	
	return 0;
}
