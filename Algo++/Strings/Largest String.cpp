#include<bits/stdc++.h>
using namespace std;

int main() {
	char ch[1000];
	char largest[1000];
	
	int l = 0;
	int largest_len = 0;
	
	int n;
	cin>>n;
	cin.get();
	
	for(int i = 0; i < n; i++) {
		cin.getline(ch, 1000);
		l = strlen(ch);
		if(l > largest_len) {
			largest_len = l;
			strcpy(largest, ch);
		}
	}
	
	cout<<largest<<" and "<<largest_len<<endl;
	
	return 0;
}
