/*
Shortest source to destination path

matrix
  0 1 2 3 
0 1 1 1 0
1 1 0 1 0
2 1 0 1 1
3 1 0 0 1
4 1 1 1 1
s=(0,0),d=(x,y) movement l,r,u,d only travel on 1 
m1=shortest path in undirected and unweighted graph=>bfs
do not use Dijkstra's becasue it is sparse
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<int>>arr={{1,1,1,0},{1,0,1,0},{1,0,1,1},{1,0,0,1},{1,1,1,1}};
    int dest_x=4;
    int dest_y=2;
    int n=arr.size();
    int m=arr[0].size();
    if(dest_x==0 && dest_y==0){
        cout<<0<<endl;
        return 0;
    }
    if(!arr[0][0]){
        cout<<-1<<endl;
        return 0;
    }
    queue<pair<int,pair<int,int>>>q;//row,col,step
    q.push({0,{0,0}});
    vector<vector<bool>>visited(n,vector<bool>(m,0));
    visited[0][0]=1; //arr[0][0]=0-> for optimisation
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // up, down, left, right
    while(!q.empty()){
        int r=q.front().first;
        int c=q.front().second.first;
        int step=q.front().second.second;
        q.pop();
        for (auto dir : directions) {
            int ni = r + dir[0];
            int nj = c + dir[1];
            if (ni >= 0 && ni < n && nj >= 0 && nj < m && arr[ni][nj] && !visited[ni][nj]){
                if(ni==dest_x && nj==dest_y){
                    cout<<step+1<<endl;
                    return 0;
                }
                visited[ni][nj]=1; // arr[ni][nj]=0 this is optimised way
                q.push({ni,{nj,step+1}});
            }
        }
    }
    cout<<-1<<endl;
    return 0;
}
/*
we can optimise it by not useing visited array
we have to just mark 0 in array itself when we move from there 

tc=O(n*m)
sc=O(visited+queue(min(n,m))) or  O(queue(min(n,m)))
*/