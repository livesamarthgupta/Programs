#include <bits/stdc++.h>
using namespace std;

void stock_span(int*prices, int n, int*span) {
    stack<int> s; //store index of prev largest element
    s.push(0);
    span[0] = 1;

    for(int i = 1; i < n; i++) {
        int currentPrice = prices[i];

        while(!s.empty() && prices[s.top()] <= currentPrice) {
            s.pop();
        }

        if(!s.empty()) {
            span[i] = i - s.top();
        } else {
            span[i] = i + 1;
        }

        s.push(i);
    }
}

int main() {
    int n;
    cin>>n;
    int prices[n];
    for(int i = 0; i < n; i++)
        cin>>prices[i];

    int span[n];
    stock_span(prices, n, span);
    for(int i = 0; i < n; i++)  
        cout<<span[i]<<" ";
    cout<<"END"<<endl;

}
