#include <bits/stdc++.h>
using namespace std;

class Queue {
    stack<int> s1;
    stack<int> s2;

public:
    void push(int data) {
        while(!s1.empty()) {
            int ele = s1.top();
            s1.pop();
            s2.push(ele);
        }
        s1.push(data);
        while(!s2.empty()) {
            int ele = s2.top();
            s2.pop();
            s1.push(ele);
        }
    }

    void pop() {
        s1.pop();
    }

    int front() {
        return s1.top();
    }

    bool empty() {
        return size() == 0;
    }

    int size() {
        return s1.size() + s2.size();
    }


};

int main() {
    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);

    while(!q.empty()) {
        cout<<q.front()<<" ";
        q.pop();
    }
}
