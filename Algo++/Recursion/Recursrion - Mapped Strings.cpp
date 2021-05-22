#include <bits/stdc++.h>
using namespace std;

void generate_characters(char input[], char output[], int i, int j) {
    if(input[i] == '\0') {
        output[j] = '\0';
        cout<<output<<endl;
        return;
    }


    //taking one digit at a time
    int digit = input[i] - '0';
    char ch = digit + 'A' - 1;
    output[j] = ch;
    generate_characters(input, output, i + 1, j + 1);

    //taking two digit at a time
    if(input[i + 1] != '\0') {
        int secondDigit = input[i + 1] - '0';
        int no = digit * 10 + secondDigit;
        if(no <= 26) {
            ch = no + 'A' - 1;
            output[j] = ch;
            generate_characters(input, output, i + 2, j + 1);
        }
    }
    return;

}


int main() {
    char input[100];
    char output[100];
    cin>>input;
    generate_characters(input, output, 0, 0);
}
