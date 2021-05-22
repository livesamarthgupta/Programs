#include <bits/stdc++.h>
using namespace std;


void insertAtBottom(stack<int> &s, int x) {
    if(s.empty()) {
        s.push(x);
        return;
    }

    int ele = s.top();
    s.pop();
    insertAtBottom(s, x);
    s.push(ele);
}

void reverserRecursive(stack<int> &s) {

    //base case
    if(s.empty()) {
        return;
    }

    //get top element
    int x = s.top();
    s.pop();

    //get empty stack
    reverserRecursive(s);
    //insert top element at bottom
    insertAtBottom(s, x);
}

int main() {
    stack<int> s;
    for(int i = 0; i < 5; i++)
        s.push(i);

    reverserRecursive(s);

    while(!s.empty()) {
        cout<<s.top()<<" ";
        s.pop();
    }
    
}
