#include<bits/stdc++.h>
using namespace std;

int main() {
	string str;
	cin>>str;
	
	int freq[26] = {0};
	for(int i = 0; i < str.size(); i++) {
		freq[str[i] - 'a']++;
	}
	
	int max = 0;
	int maxIndex = 0;
	
	for(int i = 0; i < 26; i++) {
		if(freq[i] > max) {
			max = freq[i];
			maxIndex = i;
		}
	}
	
	char res = 'a' + maxIndex;
	cout<<res<<endl;
}
