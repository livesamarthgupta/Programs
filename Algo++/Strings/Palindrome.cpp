#include<bits/stdc++.h>
using namespace std;


bool isPalindrome(char ch[]) {
	
	int i = 0;
	int j = strlen(ch) - 1;
	while(i <= j) {
		if(ch[i] == ch[j])
		{
			i++;
			j--;
		}
		else 
		return false;
	}
	return true;
}

int main() {
	char ch[1000];
	cin>>ch;
	
	if(isPalindrome(ch))
		cout<<"Palindrome"<<endl;
	else 
		cout<<"Not a Palindrome"<<endl;
	
	return 0;
}
