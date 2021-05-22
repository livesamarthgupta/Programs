#include<bits/stdc++.h>

using namespace std;

char s[100];
int top = -1;

void push(char n)
{
	top++;
	s[top] = n;
}

void pop()
{
	s[top] = 0;
	top--;
}

bool isEmpty()
{
	if(top >= 0)
	return false;
	else
	return true;
}

char topElement()
{
	return s[top];
}

int main(){
	bool check = true;
	char exp[100];
	int n; 
	cout<<"Enter number of symbols:";
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>exp[i];
	}
	for(int i = 0; i < n; i++)
	{
		if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
		push(exp[i]);
		else
		if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{
			if(isEmpty() || (exp[i] == ')' && topElement() != '(') || (exp[i] == '}' && topElement() != '{') || (exp[i] == ']' && topElement() != '['))
			{
				check = false;
				break;
			}
			else
			pop();
		}
	}
	if(check == true && isEmpty())
	cout<<"Expression syntactically correct!";
	else if(check == false)
	cout<<"Expression not syntactically correct";

	return 0;
}

