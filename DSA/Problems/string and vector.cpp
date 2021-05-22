#include<iostream>
#include<string>
#include<vector>
#include<sstream>

using namespace std;

int main(){
	string input;
	vector<string> indivStr;
	string temp;
	
	cout<<"Enter the expression";
	cin>>input;
	stringstream stream(input);
	
	while(getline(stream, temp, ' ')){
		indivStr.push_back(temp);
	}
	
	int n1 = stoi(indivStr[0]);
	int n2 = stoi(indivStr[2]);
	string op = indivStr[1];
	
	if(op == "+"){
		cout<<n1<<" + "<<n2<<" = "<<n1+n2;		
	}
	else
		if(op == "-"){
		cout<<n1<<" - "<<n2<<" = "<<n1-n2;		
	}
	else
		if(op == "*"){
		cout<<n1<<" * "<<n2<<" = "<<n1*n2;		
	}
	else
		if(op == "/"){
		cout<<n1<<" / "<<n2<<" = "<<n1/n2;		
	}
	else{
		cout<<"Enter among +,-,*,/";
	}
	
	return 0;
}