#include<bits/stdc++.h>
using namespace std;

int main() {
	long long int n;
	cin>>n;
	
	long long int temp = n;
	int size = 0;
	while(temp > 0) {
		temp = temp / 10;
		size++;
	}
	
	long long int rev = 0;
	for(int i = 1; i <= size; i++) {
		auto digit = n % 10;
		if(i == size && digit == 9) {
			rev = rev * 10 + digit;
		}
		else if((9 - digit < digit))
			rev = (rev * 10) + (9 - digit);
		else 
			rev = rev * 10 + digit;
		n = n / 10;
	}
	
	long long int result = 0;
	for(int i = 0; i < size; i++) {
		result = result * 10 + (rev % 10);
		rev /= 10;
	}
	
	cout<<result<<endl;
	
	return 0;
}
