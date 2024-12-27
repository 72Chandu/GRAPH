/*
Replace O's with X 
only when 0 surrounded by x from 4 direction or
set of o is surrounded by x then also convert
boundary o's cant be replaced 
  0 1 2 3 
0 x x x x 
1 x o x x 
2 x o o x
3 x o x x
4 x x o o

o/p
  0 1 2 3 
0 x x x x 
1 x x x x 
2 x x x x
3 x x x x
4 x x o o

i/p
  0 1 2 3 
0 x o x x 
1 x o x x 
2 x o o x
3 x o x x
4 x x o o
non of o is replace in this example
-> set me ek bhi 'O' boundary pe hoga toh wo kabhi bhi replace nahi hoga 

approach
bfs
traverse to boundary find 'O' at boundary=> if 'O' found then all the 'O' associated with it cant be the part of set so, mark them all as 't' 
and then make all 'O' to 'x' and 't' to 'o'

*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> fill(vector<vector<char>>& mat) {
    int r = mat.size();
    int c = mat[0].size();
    // Apply BFS from border cells where 'O' is present
    queue<pair<int, int>> q;
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // up, down, left, right

    // Check the first row
    for (int j = 0; j < c; j++) {
        if (mat[0][j] == 'O') {
            q.push({0, j});
            mat[0][j] = 'T';
        }
    }

    // Check the first column
    for (int i = 1; i < r; i++) {
        if (mat[i][0] == 'O') {
            q.push({i, 0});
            mat[i][0] = 'T';
        }
    }

    // Check the last row
    for (int j = 0; j < c; j++) {
        if (mat[r - 1][j] == 'O') {
            q.push({r - 1, j});
            mat[r - 1][j] = 'T';
        }
    }

    // Check the last column
    for (int i = 1; i < r - 1; i++) {
        if (mat[i][c - 1] == 'O') {
            q.push({i, c - 1});
            mat[i][c - 1] = 'T';
        }
    }

    // Perform BFS to mark all connected 'O's to 'T'
    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for (auto dir : directions) {
            int ni = i + dir[0];
            int nj = j + dir[1];
            if (ni >= 0 && ni < r && nj >= 0 && nj < c && mat[ni][nj] == 'O') {
                mat[ni][nj] = 'T';
                q.push({ni, nj});
            }
        }
    }

    // Replace 'O' with 'X' and 'T' with 'O'
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (mat[i][j] == 'O') {
                mat[i][j] = 'X';
            } else if (mat[i][j] == 'T') {
                mat[i][j] = 'O';
            }
        }
    }
    return mat;
}
int main() {
    vector<vector<char>> mat = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'O', 'X', 'X'},
        {'X', 'X', 'O', 'O'}
    };
    cout << "Original Matrix:" << endl;
    for (auto& row : mat) {
        for (auto& cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
    vector<vector<char>> result = fill(mat);
    cout << "\nModified Matrix:" << endl;
    for (auto& row : result) {
        for (auto& cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
    return 0;
}
