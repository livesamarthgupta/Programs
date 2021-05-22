#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	
	int num1[n];
	for(int i = 0; i < n; i++)
		cin>>num1[i];
		
	int m;
	cin>>m;
	
	int num2[m];
	for(int i = 0; i < m; i++)
		cin>>num2[i];
		
	reverse(num1, num1 + n);
	reverse(num2, num2 + m);
	
	int minimum = min(m, n);
	int maximum = max(m, n);
	
	vector<int> result;
	
	int carry = 0;
	for(int i = 0; i < minimum; i++){
		result.push_back((num1[i] + num2[i] + carry) % 10);
		carry = (num1[i] + num2[i] + carry) / 10; 
	}
	
	if(minimum == n) {
		for(int i = minimum; i < maximum; i++) {
			result.push_back((num2[i] + carry) % 10);
			carry = (num2[i] + carry) / 10;
		}
			
	} else {
		for(int i = minimum; i < maximum; i++) {
			result.push_back((num1[i] + carry) % 10);
			carry = (num1[i] + carry) / 10;
		}
	}
	
	if(carry != 0)
	result.push_back(carry);
	reverse(result.begin(), result.end());
	
	for(auto i : result)
		cout<<i<<", ";
	cout<<"END"<<endl;
	
	return 0;
}
