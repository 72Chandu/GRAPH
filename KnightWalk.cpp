/*
Knight Walk (ghoda)
move 2.5 step (2 step straight, 1 step turn)
inital position of knight(source)
final position of knight(target)
minimum step to reach target
bfs (dfs is time consuming )

*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=6;//size of chess board
    vector<int>knightPos={4,5};
    vector<int>targetPos={1,1};
    if(knightPos[0]==targetPos[0] && knightPos[1]==targetPos[1]){//base case
        cout<<0<<endl;
        return 0;
    }
    queue<pair<int,int>>q;
    vector<vector<bool>>chess(n,vector<bool>(n,0));
    q.push({knightPos[0],knightPos[1]});
    chess[knightPos[0]][knightPos[1]]=1;
    int step=0;
    int knight_dire[8][8]={{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{-1,2},{1,-2},{-1,-2}};
    while(!q.empty()){
        int count=q.size();
        while(count--){ //something like level order traversal
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for (auto dir : knight_dire) {
                int ni = i + dir[0];
                int nj = j + dir[1];
                if (ni>=0 && ni<n && nj>=0 && nj<n && !chess[ni][nj]){
                    if(ni==targetPos[0] && nj==targetPos[1]){
                        cout<<step+1<<endl;
                        return 0;
                    }
                    chess[ni][nj]=1;
                    q.push({ni, nj});
                }
            }
        }
        step++;
    }
    if(step<0) cout<<-1;
    return 0;
}