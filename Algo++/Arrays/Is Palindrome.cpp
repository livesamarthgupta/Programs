#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0; i < n; i++)
		cin>>arr[i];
		
	int f = 0, l = n - 1;
	bool isPalin = true;
	while(f <= l) {
		if(arr[f] != arr[l]) {
			cout<<"false"<<endl;
			isPalin = false;
			break;
		}
		f++;
		l--;
	}
	
	if(isPalin)
		cout<<"true"<<endl;
	
	
	return 0;
}
