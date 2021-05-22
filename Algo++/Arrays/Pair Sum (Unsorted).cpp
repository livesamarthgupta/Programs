#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0; i < n; i++)
		cin>>arr[i];
	int key;
	cin>>key;
	
		
	unordered_set<int> set;
	set.insert(arr[0]);
	for(int i = 1; i < n; i++) {
		if(set.find(key - arr[i]) != set.end()) {
			cout<<key - arr[i]<<" and "<<arr[i]<<endl;
		} 
		set.insert(arr[i]);
	}
	
	
	return 0;
}
