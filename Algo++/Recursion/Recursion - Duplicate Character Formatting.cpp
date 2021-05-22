#include <iostream>
using namespace std;

void format_duplicate(char *a, int i) {
    if(a[i] == '\0')
        return;
    
    if(a[i] == a[i + 1]) {
        //shift and add *
        int j = i + 1;
        while(a[j] != '\0')
            j++;
        while(j >= i + 1) {
            a[j + 1] = a[j];
            j--;
        }
            
        a[i + 1] = '*';
        format_duplicate(a, i + 2);

    } else {
        format_duplicate(a, i + 1);
    }
}

int main() {
    char str[10000];
    cin>>str;
    format_duplicate(str, 0);

    cout<<str<<endl;
}
