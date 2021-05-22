#include <iostream>
using namespace std;

void remove_duplicates(char *a, char ch, int i) {
    if(a[i] == '\0')
        return;

    if(ch == a[i]) {
        //remove duplicate
        int j = i;
        while(a[j] != '\0') {
            a[j] = a[j + 1];
            j++;
        }
        remove_duplicates(a, ch, i);
    } else {
        remove_duplicates(a, a[i], i + 1);
    }
}


int main() {
    char str[1000];
    cin>>str;
    remove_duplicates(str, str[0], 1);
    cout<<str<<endl;
}
