#include<bits/stdc++.h>
using namespace std;

// subarrays are continuous elements

int main() {
	
	int arr[] = {1, 2, 3, 4};
	
	for(int i = 0; i < 4; i++) {
		for(int j = i; j < 4; j++) {
			for(int k = i; k <= j; k++) {
				cout<<arr[k]<<",";
			}
			cout<<endl;
		}
	}
	
	return 0;
}
