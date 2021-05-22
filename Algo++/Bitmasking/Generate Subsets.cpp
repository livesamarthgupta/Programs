#include<bits/stdc++.h>
using namespace std;


void filterChars(char a[], int i) {
	int j = 0;
	while(i > 0) {
		int last_bit = i & 1;
		i = i >> 1;
		if(last_bit)
			cout<<a[j];
		j++;
	}
	cout<<endl;
}

void printSubsets(char s[]) {
	int n = strlen(s);
	
	for(int i = 0; i < (1 << n); i++) {
		filterChars(s, i);
	}
}

int main() {
	char s[1000];
	cin>>s;
	printSubsets(s);
	
	return 0;
}
