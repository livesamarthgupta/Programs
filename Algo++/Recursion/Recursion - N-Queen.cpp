#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> arr, int i, int j, int n) {

    //check row
    for(int k = 0; k < i; k++) {
        if(arr[k][j] == 1)
            return false;
    }


    //check left diagonal
    int x = i;
    int y = j;
    while(x >= 0 && y >= 0) {
        if(arr[x][y] == 1)
            return false;
        x--;
        y--;
    }


    //check right diagonal
    x = i;
    y = j;
    while(x >= 0 && y < n) {
        if(arr[x][y] == 1)
            return false;
        x--;
        y++;
    }

    return true;

}

bool placeNQueen(vector<vector<int>> &arr, int n, int i, int &count) {

    //base case
    if(i == n) {
        count++;
        //this will print the n-queens
        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < n; j++) {
        //         if(arr[i][j] == 1)
        //             cout<<"Q";
        //         else
        //             cout<<" _ ";
        //     }
        //     cout<<endl;
        // }
        return false;
    }


    //recursive case
    for(int j = 0; j < n; j++) {
        if(isSafe(arr, i, j, n)) {
            arr[i][j] = 1;
            bool canPlace = placeNQueen(arr, n, i + 1, count);
            if(canPlace)
                return true;
            arr[i][j] = 0;
        }
    }
    return false;
   
}



int main() {
    int n;
    cin>>n;
    vector<vector<int>> arr(n, vector<int>(n, 0));
    int count = 0;
    placeNQueen(arr, n, 0, count);
    cout<<count<<endl;
}
