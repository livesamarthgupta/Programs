#include <bits/stdc++.h>
using namespace std;

bool canPlace(vector<vector<int>> sudoku, int i, int j, int num, int n) {
    //check row and col
    for(int k = 0; k < n; k++) {
        if(sudoku[i][k] == num || sudoku[k][j] == num)
            return false;
    }

    //check grid
    int rn = sqrt(n);
    int sx = (i/rn) * rn;
    int sy = (j/rn) * rn;
    for(int x = sx; x < sx + rn; x++) {
        for(int y = sy; y < sy + rn; y++) {
            if(sudoku[x][y] == num)
                return false;
        }
    }

    return true;
}

bool solveSudoku(vector<vector<int>> &sudoku, int i, int j, int n) {
    if(i == n) {
        //print sudoku
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++)
                cout<<sudoku[i][j]<<" ";
            cout<<endl;
        }
        return true;
    }

    //reached end of one row
    if(j == n)
        return solveSudoku(sudoku, i + 1, 0, n);

    //if already filled
    if(sudoku[i][j] != 0)
        return solveSudoku(sudoku, i, j + 1, n);

    for(int num = 1; num <= n; num++) {
        if(canPlace(sudoku, i, j, num, n)) {
            sudoku[i][j] = num;
            bool canSolve = solveSudoku(sudoku, i, j + 1, n);
            if(canSolve)
                return true;
        }
    }
    sudoku[i][j] = 0;
    return false;

}



int main() {
    int n;
    cin>>n;
    vector<vector<int>> sudoku;
    for(int i = 0; i < n; i++) {
        vector<int> v;
        for(int j = 0; j < n; j++) {
            int num;
            cin>>num;
            v.push_back(num);
        }
        sudoku.push_back(v);
        v.clear();
    }

    solveSudoku(sudoku, 0, 0, n);
}
