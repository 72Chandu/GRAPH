/* Shortest Path in undirected graph
0->1,2
1->0,5
2->0,4,3
3->4,2,7
4->2,3,8
5->1,6
6->5,8
7->3,8
8->7,6
9->
draw a graph then visiualization is easy
if any node that is not connected with graph then return -1 fo it 
source node given=0
           0  1  2  3  4  5  6  7  8 9-> node 
distance=[-1,-1,-1,-1,-1,-1,-1,-1,-1,-1] -> shorest distance form 0 to node
visited=[0,0,0,0,0,0,0,0,0,0]
q=[0],v=[1,0,0,0,0,0,0,0,0,0],d=[0,-1,-1,-1,-1,-1,-1,-1,-1,-1] 

pop=0 push its neighboure 1,2
q=[1,2],v=[1,1,1,0,0,0,0,0,0,0],d=[0,1,1,-1,-1,-1,-1,-1,-1,-1] 

pop=1 push its neighboure 0(v),5
q=[2,5],v=[1,1,1,0,0,1,0,0,0,0],d=[0,1,1,-1,-1,2,-1,-1,-1,-1]  2=d[pop node]+1=1+1=2

pop=2 push its neighboure 0(v),4,3
q=[5,4,3],v=[1,1,1,1,1,1,0,0,0,0],d=[0,1,1,2,2,2,-1,-1,-1,-1]  2=d[pop node]+1=1+1=2

pop=5 push its neighboure 1(v),6
q=[4,3,6],v=[1,1,1,1,1,1,1,0,0,0],d=[0,1,1,2,2,2,3,-1,-1,-1]  3=d[pop node]+1=2+1=3

pop=4 push its neighboure 2(v),3(v),8
q=[3,6,8],v=[1,1,1,1,1,1,1,0,1,0],d=[0,1,1,2,2,2,3,-1,3,-1]  3=d[pop node]+1=2+1=3

pop=3 push its neighboure 4(v),2(v),7
q=[6,8,7],v=[1,1,1,1,1,1,1,1,1,0],d=[0,1,1,2,2,2,3,3,3,-1]  3=d[pop node]+1=2+1=3

pop=6 push its neighboure 5(v),8(v)
q=[8,7],v=[1,1,1,1,1,1,1,1,1,0],d=[0,1,1,2,2,2,3,3,3,-1]

pop=8 push its neighboure 7(v),6(v)
q=[7],v=[1,1,1,1,1,1,1,1,1,0],d=[0,1,1,2,2,2,3,3,3,-1] 

pop=7 push its neighboure 3(v),8(v)
q=[],v=[1,1,1,1,1,1,1,1,1,0],d=[0,1,1,2,2,2,3,3,3,-1]  

push 9
q=[9],v=[1,1,1,1,1,1,1,1,1,1],d=[0,1,1,2,2,2,3,3,3,-1]  

pop=9 no neighboure
q=[],v=[1,1,1,1,1,1,1,1,1,0],d=[0,1,1,2,2,2,3,3,3,-1]  

return d

//dfs -> not prefer beacuse tc inc
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<int>>edges={{0,1},{0,3},{3,4},{4,5},{5,6},{1,2},{2,6},{6,7},{7,8},{6,8}};
    int n=9; //no of vertex
    int m=10;//no of edge
    int src=0;
    vector<int>AdjList[n];
    for(int i=0;i<m;i++){
        AdjList[edges[i][0]].push_back(edges[i][1]);//0->1
        AdjList[edges[i][1]].push_back(edges[i][0]);//1->0
    }

    // vector<int>AdjList[]={{1, 2},{0, 5},{0, 4, 3},{4, 2, 7},{2, 3, 8},{1, 6},{5, 8},{3, 8},{7, 6},{}};
    // int n= sizeof(AdjList) / sizeof(AdjList[0]);
    // int src=0;
    vector<int>dist(n,-1);
    vector<bool>visited(n,0);
    queue<int>q;
    q.push(src);
    dist[src]=0;
    visited[src]=1;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto neighboure:AdjList[node]){            
            if(!visited[neighboure]){
                q.push(neighboure);
                dist[neighboure]=dist[node]+1;
                visited[neighboure]=1;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<dist[i]<<" ";
    }
    return 0;
}//tc=O(V+E), sc=O(V+E+V+V+V)=O(V+E)