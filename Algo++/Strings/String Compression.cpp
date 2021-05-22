#include <iostream>
using namespace std;
int main() {
    string s;
    cin>>s;
    string temp;
    int count = 0;
    int idx = 0;
    int n = s.length();
    for(int i = 0; i < n; i++) {
        count = 1;
        while(i < n - 1 && s[i] == s[i + 1]) {
            count++;
            i++;
        }
        cout<<s[i]<<count;
    }
    cout<<temp;
}
