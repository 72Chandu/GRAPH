/*
0-> water,  1->land
island form -> 1 connected with 1 in all direction(including diagonal ) denotes 1 island
  0 1 2 3 4 5
0 1 1 1 0 1 1
1 0 1 1 0 0 1
2 1 0 0 0 0 0
3 1 0 1 0 1 1
4 1 1 0 0 1 1
0/p=3
bfs
q=[(0,0)] also make maintain one visited array which heps us to not take those element again in queue

pop (0,0)-> push its neighbour=(0,1),(1,1), and v[0][0]=1 ,v[0][1]=1,v[1][1]=1
q=[(0,1),(1,1)]

pop (0,1)-> push its neighbour=(0,2),(1,2) ,and v[0][2]=1,v[1][2]=1
q=[(1,1),(0,2),(1,2)]

pop (1,1)-> push its neighbour=(2,0)and v[2][0]=1, (1,2)already visited
q=[(0,2),(1,2),(2,0)]

pop (0,2)-> neighbour is already visited
q=[(1,2),(2,0)]

pop (1,2)->  neighbour is already visited
q=[(2,0)]

pop (2,0)->  push its neighbour=(3,0)and v[3][0]=1, rest is already visited
q=[(3,0)]

pop (3,0)->  push its neighbour=(4,0),(4,1)and v[4][0]=1,v[4][1]=1, rest is already visited
q=[(4,0),(4,1)]

pop (4,0)->  neighbour is already visited
q=[(4,1)]

pop (4,1)->  push its neighbour=(3,2) v[3][2]=1,rest is already visited
q=[(3,2)]

pop (3,2)->  neighbour is already visited
q=[]
count =1
now move tho unvisited 1
do same process

m-2
1.find 1
   -> count of island
   ->push it in queue=(r,c)
   ->adjancent 1, make them 0
*/
#include <bits/stdc++.h>
using namespace std;
using namespace std;
int numIsland(vector<vector<char>> &grid) {
    int r = grid.size();
    int c = grid[0].size();
    queue<pair<int, int>> q;
    int directions[8][2] = {
        {-1, 0},  // Up
        {1, 0},   // Down
        {0, -1},  // Left
        {0, 1},   // Right
        {-1, -1}, // Top-left
        {-1, 1},  // Top-right
        {1, -1},  // Bottom-left
        {1, 1}    // Bottom-right
    };
    int count = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == '1') {
                count++;
                q.push({i, j});
                grid[i][j] = '0';
                while (!q.empty()) {
                    int new_i = q.front().first;
                    int new_j = q.front().second;
                    q.pop();
                    for (auto dir : directions) {
                        int ni = new_i + dir[0];
                        int nj = new_j + dir[1];
                        // Check boundaries and if the cell is part of an island (value 1)
                        if (ni >= 0 && ni < r && nj >= 0 && nj < c && grid[ni][nj] == '1') {
                            grid[ni][nj] = '0';//making 1 to 0 after visiting it
                            q.push({ni, nj});
                        }
                    }
                }
            }
        }
    }
    return count;
}
int main() {
    vector<vector<char>> grid = {
        {'1', '1', '1', '0', '1', '1'},
        {'0', '1', '1', '0', '0', '1'},
        {'1', '0', '0', '0', '0', '0'},
        {'1', '0', '1', '0', '1', '1'},
        {'1', '1', '0', '0', '1', '1'}
    };
    int result = numIsland(grid);
    cout << "Number of islands: " << result << endl;
    return 0;
}