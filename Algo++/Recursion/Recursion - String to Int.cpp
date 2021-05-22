#include <bits/stdc++.h>
using namespace std;

int convert_string_to_int(char *s, int n) {
    if(n == 0)
        return 0;

    int digit = s[n - 1] - '0';
    int smaller_number = convert_string_to_int(s, n - 1);

    return smaller_number * 10 + digit;

}


int main() {
    char s[11];
    cin>>s;
    int n = strlen(s);
    cout<<convert_string_to_int(s, n);
}
