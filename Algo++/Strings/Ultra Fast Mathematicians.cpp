#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	cin.get();
	while(t--) {
		string str1, str2;
		cin>>str1;
		cin>>str2;
		
		char ch1;
		char ch2; 
		
		string res = "";
		
		for(int i = 0; i < str1.size(); i++) {
			ch1 = str1[i];
			ch2 = str2[i];
			
			if(ch1 != ch2)
			res += ch1;
			else 
			res += '0';
		}
		
		cout<<res<<endl;
	}
	
	
	return 0;
}
