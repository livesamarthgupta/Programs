#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Stack {
private:
    vector<T> v;

public:
    void push(T data) {
        v.push_back(data);
    }

    void pop() {
        if(!empty())
            v.pop_back();
    }

    bool empty() {
        return v.size() == 0;
    }

    T top() {
        return v[v.size() - 1];
    }

};

int main() {
    Stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    for(int i = 0; i < 3; i++) {
        cout<<s.top()<<endl;
        s.pop();
    }
}
