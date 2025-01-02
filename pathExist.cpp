/*
Find wether path Exist

1- source, 2-destination , 3-move on it , 0->no movement on 0, move in 4 direction
3 0 3 0 0
3 0 2 0 3
3 3 3 3 3
0 3 0 0 3
3 3 1 0 3
o/p=yes


*/
#include<bits/stdc++.h>
using namespace std;

bool bfs(vector<vector<int>>& arr, int src_i, int src_j, int dest_i, int dest_j) {
    int r = arr.size();
    int c = arr[0].size();
    queue<pair<int, int>> q;
    q.push({src_i, src_j});
    arr[src_i][src_j] = 0;
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for (auto dir : directions) {
            int ni = i + dir[0];
            int nj = j + dir[1];
            if (ni >= 0 && ni < r && nj >= 0 && nj < c) {
                if (arr[ni][nj] == 2) {
                    return true; // Found the destination
                }
                if (arr[ni][nj] == 3) { // Continue traversal if it's a valid path
                    arr[ni][nj] = 0; // Mark as visited
                    q.push({ni, nj});
                }
            }
        }
    }
    return false; // Destination not reachable
}

bool dfs(vector<vector<int>>& arr, int src_i, int src_j, int dest_i, int dest_j) {
    int r = arr.size();
    int c = arr[0].size();
    if (src_i < 0 || src_i >= r || src_j < 0 || src_j >= c) return false;
    if(arr[src_i][src_j]==2) return true;
    if(arr[src_i][src_j]!=3 && arr[src_i][src_j]!=1) return false;
    
    arr[src_i][src_j]=0;
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (auto dir : directions) {
        int ni = src_i + dir[0];
        int nj = src_j + dir[1];
        if(dfs(arr,ni,nj,dest_i,dest_j)) return true;
    }
    return false; // Destination not reachable
}
int main(){
    vector<vector<int>>arr={{3,0,3,0,0},{3,0,2,0,3},{3,3,3,3,3},{0,3,0,0,3},{3,3,1,0,3}};
    int n=arr.size();
    int src_i,src_j ,dest_i,dest_j;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==1){
                src_i=i;
                src_j=j;
            }
            if(arr[i][j]==2){
                dest_i=i;
                dest_j=j;
            }
        }
    }
    // if(bfs(arr,src_i,src_j,dest_i,dest_j)) cout<<"yes"<<endl;
    // else cout<<"No"<<endl;
    if(dfs(arr,src_i,src_j,dest_i,dest_j)) cout<<"yes"<<endl;
    else cout<<"No"<<endl;
}