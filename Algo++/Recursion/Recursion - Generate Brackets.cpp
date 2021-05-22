#include <iostream>
using namespace std;

void generate_brackets(char *output, int i, int n, int open, int close) {
    if(i == 2 * n) {
        output[i] = '\0';
        cout<<output<<endl;
        return;
    }

    

    if(close < open) {
        output[i] = ')';
        generate_brackets(output, i + 1, n, open, close + 1);
    }

    if(open < n) {
        output[i] = '(';
        generate_brackets(output, i + 1, n, open + 1, close);
    }



}


int main() {
    int n;
    cin>>n;
    char output[n * 2 + 1];

    generate_brackets(output, 0, n, 0, 0);

}
