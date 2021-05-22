#include <bits/stdc++.h>
using namespace std;

void transfer(stack<int> &s1, stack<int> &s2, int n) {
    for(int i = 0; i < n; i++) {
        s2.push(s1.top());
        s1.pop();
    }
}

void reverseStack(stack<int> &s) {
    stack<int> aux;
    int n = s.size();

    for(int i = 0; i < n; i++) {
        //get top element;
        int x = s.top();
        s.pop();

        //transfer n-i-1 element to aux
        transfer(s, aux, n - i - 1);

        //place x in s
        s.push(x);

        //transfer n-i-1 element to s
        transfer(aux, s, n - i - 1);
    }
}

int main() {
    stack<int> s;
    for(int i = 0; i < 5; i++)
        s.push(i);

    reverseStack(s);

    for(int i = 0; i < 5; i++) {
        cout<<s.top()<<" ";
        s.pop();
    }
}
