#include <bits/stdc++.h>
using namespace std;

bool print_soln(vector<vector<char>> &maze, vector<vector<int>> &soln, int i, int j, int n, int m) {
    if(i == n && j == m) {
        soln[i][j] = 1;
        //print soln
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= m; j++)
                cout<<soln[i][j]<<" ";
            cout<<endl;
        }
        return true;
    }

    if(i > n || j > m)
        return false;

    if(maze[i][j] == 'X')
        return false;

    soln[i][j] = 1;
        
    bool right = print_soln(maze, soln, i, j + 1, n, m);
    if(right)
        return true;
    bool down = print_soln(maze, soln, i + 1, j, n, m);
    if(down)
        return true;

    soln[i][j] = 0;

    return false;

}


int main() {
    int n, m;
    cin>>n>>m;

    vector<vector<char>> maze(n, vector<char>(m, 'O'));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char ch;
            cin>>ch;
            maze[i][j] = ch;
        }
    }

    vector<vector<int>> soln(n, vector<int>(m, 0));
    bool ans = print_soln(maze, soln, 0, 0, n - 1, m - 1);
    if(!ans)
        cout<<-1<<endl;

}
