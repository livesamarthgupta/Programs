#include <bits/stdc++.h>
using namespace std;

class Stack {
    queue<int> q1;
    queue<int> q2;

public:

    void push(int data) {
        q2.push(data);
        while(!q1.empty()) {
            int ele = q1.front();
            q1.pop();
            q2.push(ele);
        }
        swap(q1, q2);
    }

    void pop() {
        q1.pop();
    }

    bool empty() {
        return size() == 0;
    }

    int size() {
        return q1.size() + q2.size();
    }

    int top() {
        return q1.front();
    }
};

int main() {
    Stack s;
    s.push(3);
    s.push(2);
    s.push(1);

    while(!s.empty()) {
        cout<<s.top()<<" ";
        s.pop();
    }
}
