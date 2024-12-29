/*
Shortest path between two node in undirected graph 
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
src=0  destination=8  o/p=0 2 3 8
for determinig the path we store the parent of each node 

          0  1  2  3  4  5  6  7  8 -> node 
parents=[-1,-1,-1,-1,-1,-1,-1,-1,-1] -> shorest distance form 0 to node
visited=[0,0,0,0,0,0,0,0,0]
q=[0],v=[1,0,0,0,0,0,0,0,0],d=[0,-1,-1,-1,-1,-1,-1,-1,-1] ,p=[-1,-1,-1,-1,-1,-1,-1,-1,-1]

pop=0 push its neighboure 1,2
q=[1,2],v=[1,1,1,0,0,0,0,0,0],d=[0,1,1,-1,-1,-1,-1,-1,-1] ,p=[-1,0,0,-1,-1,-1,-1,-1,-1]

pop=1 push its neighboure 0(v),5
q=[2,5],v=[1,1,1,0,0,1,0,0,0],d=[0,1,1,-1,-1,2,-1,-1,-1] ,p=[-1,0,0,-1,-1,1,-1,-1,-1] 2=d[pop node]+1=1+1=2

pop=2 push its neighboure 0(v),4,3
q=[5,4,3],v=[1,1,1,1,1,1,0,0,0],d=[0,1,1,2,2,2,-1,-1,-1] , 2=d[pop node]+1=1+1=2, p=[-1,0,0,2,2,1,-1,-1,-1]

pop=5 push its neighboure 1(v),6
q=[4,3,6],v=[1,1,1,1,1,1,1,0,0],d=[0,1,1,2,2,2,3,-1,-1]  3=d[pop node]+1=2+1=3,p=[-1,0,0,2,2,1,5,-1,-1]

pop=4 push its neighboure 2(v),3(v),8
q=[3,6,8],v=[1,1,1,1,1,1,1,0,1,0],d=[0,1,1,2,2,2,3,-1,3]  3=d[pop node]+1=2+1=3, ,p=[-1,0,0,2,2,1,5,-1,4]

pop=3 push its neighboure 4(v),2(v),7
q=[6,8,7],v=[1,1,1,1,1,1,1,1,1,0],d=[0,1,1,2,2,2,3,3,3]  3=d[pop node]+1=2+1=3 ,p=[-1,0,0,2,2,1,5,3,4]

pop=6 push its neighboure 5(v),8(v)
q=[8,7],v=[1,1,1,1,1,1,1,1,1],d=[0,1,1,2,2,2,3,3,3] ,,p=[-1,0,0,2,2,1,5,3,4]

pop=8 push its neighboure 7(v),6(v)
q=[7],v=[1,1,1,1,1,1,1,1,1],d=[0,1,1,2,2,2,3,3,3] ,p=[-1,0,0,2,2,1,5,3,4]

pop=7 push its neighboure 3(v),8(v)
q=[],v=[1,1,1,1,1,1,1,1,1],d=[0,1,1,2,2,2,3,3,3]  ,p=[-1,0,0,2,2,1,5,3,4]

    0 1 2 3 4 5 6 7 8 9
p=[-1,0,0,2,2,1,5,3,4,-1]
parent of 8=4 -> parent of 4=2 ->parent of 2=0 ->parent of 0=-1
8->4->2->0->-1 reverse=-1->0->2->4->8 =0->2->4->8 
now you can find all the path b/w any 2 nodes by looking parents array
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 5}, {2, 4}, {2, 3},{3, 4},{3, 7},{4, 8},{5, 6},{6, 8},{7, 8}};
    int n=9; //no of vertex
    int m=edges.size(); //no of edges
    int src=0;
    int dest=8;
    vector<int>AdjList[n];
    for(int i=0;i<m;i++){
        AdjList[edges[i].first].push_back(edges[i].second);//0->1
        AdjList[edges[i].second].push_back(edges[i].first);//1->0
    }
    vector<int>dist(n,-1);
    vector<bool>visited(n,0);
    vector<int>parent(n,-1);
    queue<int>q;
    q.push(src);
    dist[src]=0;
    visited[src]=1;
    parent[src]=-1;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto neighboure:AdjList[node]){            
            if(!visited[neighboure]){
                q.push(neighboure);
                dist[neighboure]=dist[node]+1;
                visited[neighboure]=1;
                parent[neighboure]=node;
            }
        }
    }

    vector<int>path;
    while(dest!=-1){
        path.push_back(dest);
        dest=parent[dest];
    }
    reverse(path.begin(),path.end());
    for(int i=0;i<path.size();i++){
        cout<<path[i]<<" ";
    }
    return 0;
}