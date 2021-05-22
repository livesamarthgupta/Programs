#include <bits/stdc++.h>
using namespace std;

int generate_subsequence(char input[], char output[], int i, int j) {
    if(input[i] == '\0') {
        output[j] = '\0';
        cout<<output<<" ";
        return 1;
    }

    int ans = 0;
    ans += generate_subsequence(input, output, i + 1, j);

    output[j] = input[i];
    ans += generate_subsequence(input, output, i + 1, j + 1);
    return ans;
}


int main() {
    char input[1000];
    cin>>input;
    char output[strlen(input) + 1];

    int count = generate_subsequence(input, output, 0, 0);
    cout<<endl;
    cout<<count<<endl;
}
