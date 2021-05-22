#include <iostream>
using namespace std;

int fast_power(int a, int n) {
    if(n == 0) {
        return 1;
    }

    int half_power = fast_power(a, n/2);
    half_power *= half_power;
    if(a&1) {
        return half_power * a;
    }
    return half_power;
}


int main() {
    int result = fast_power(2, 8);
    cout<<result<<endl;
}
