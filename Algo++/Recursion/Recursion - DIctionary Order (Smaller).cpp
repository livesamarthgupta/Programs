#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin>>s;
    string temp = s;
    sort(s.begin(), s.end());
    do{
        if(s < temp)
            cout<<s<<endl;
    }while(next_permutation(s.begin(), s.end()));
}
