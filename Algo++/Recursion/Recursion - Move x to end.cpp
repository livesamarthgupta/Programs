#include <bits/stdc++.h>
using namespace std;

void move_to_end(char input[], int i) {
    if(i == -1) {
        cout<<input<<endl;
        return;
    }

    if(input[i] == 'x') {
        int j = i;
        while(input[j] != '\0') {
            input[j] = input[j + 1];
            j++;
        }
        input[j - 1] = 'x';
    } 
    move_to_end(input, i - 1);

    return;
}


int main() {
    char input[100];
    char output[100];
    cin>>input;
    move_to_end(input, strlen(input) - 1);
}
