#include <iostream>
using namespace std;

void tower_of_hanoi(int n, char src, char aux, char dest) {
    if(n == 0)
        return;

    tower_of_hanoi(n - 1, src, dest, aux);
    cout<<"Moving ring "<<n<<" from "<<src<<" to "<<dest<<endl; 
    tower_of_hanoi(n - 1, aux, src, dest);
}

int main() {
    int n;
    cin>>n;
    tower_of_hanoi(n, 'A', 'C', 'B');
}
