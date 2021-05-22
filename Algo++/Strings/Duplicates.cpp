#include<bits/stdc++.h>
using namespace std;

void removeDuplicates(char ch[]) {
	
	int l = strlen(ch);
	int prev = 0;
	for(int curr = 1; curr < l; curr++) {
		if(ch[prev] != ch[curr]) {
			prev++;
			ch[prev] = ch[curr];
		}
	}
	ch[prev + 1] = '\0';
	return;
}

int main() {
	char ch[1000];
	cin>>ch;
	removeDuplicates(ch);
	cout<<ch<<endl;
	
	return 0;
}
