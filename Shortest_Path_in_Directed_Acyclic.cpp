/*
Shortest Path in Directed weighted Acyclic Graph

0-> {1,4},{2,3}
1->{3,6}
2->{4,2}
3->{6,5}
4->{5,1}
5->{3,2}
6->{7,4}
7
src=0
o/p=0,4,3,8,5,6,13,17  distance of each node(that is index) w.r.t 0 
source node given=0

----------------------------
dfs
path=0->1->3->6->7
path=0->2->4->5->3->6->7
move all  path and allwase put minimum distance to node => this approach make multiple visit to one node 
tc increase

------------------------------
optimisation
path=0->1->3 stop
path=0->2->4->5->3 stop 
at 3 choose min distance from diffrent path  then proced further path
path=0->2->4->5->3->6->7 stop 
allwayse find min distance from source node

------------------------
0 2 4 1 5 3 6 7 -> order to find the distance of node from source
for knowing the dist[2] you should know shortest dist[0] first then dist[2]=dist[shortest dist of 0]+2.second
this order is nothing but the topological sort
--------------------------

find the topological sort using dfs
0->1->3->6->7 then start returning and push the element in statck
stack=[7,6,3,1]  from 0 there is also another path 0->2->4->5 rest is visited so return
stack=[7,6,3,1,5,4,2,0] -> order=[0,2,4,5,1,3,6,7]
                            0    1   2  3   4   5   6    7
stack=[7,6,3,1,5,4,2,0] ,d=[inf,inf,inf,inf,inf,inf,inf,inf] 
distance is associated with the poped elemet that is put in dist array
pop=0   
stack=[7,6,3,1,5,4,2] ,d=[0,inf,inf,inf,inf,inf,inf,inf] 

pop=2
stack=[7,6,3,1,5,4] ,d=[0,inf,3,inf,inf,inf,inf,inf] 

problem that this process is to long because each time we travese the adj list to find the dist so, we move to another approach
-----------------------------

stack=[7,6,3,1,5,4,2,0] -> order=[0,2,4,5,1,3,6,7]
                            0    1   2  3   4   5   6    7
stack=[7,6,3,1,5,4,2,0] ,d=[inf,inf,inf,inf,inf,inf,inf,inf] 
distance(weight) is associated with the poped elemet that is put in dist array

pop=0   edge move from 0 to=4,2
stack=[7,6,3,1,5,4,2] ,d=[0,4,3,inf,inf,inf,inf,inf] 0+4,0+3  dist[neighbour]=min(dist[neighboure],weight(node,neighbour)+dist[node])

pop=2   edge move from 2 to=4
stack=[7,6,3,1,5,4] ,d=[0,4,3,inf,5,inf,inf,inf]  dit[2]+w(2,4)=3+2

pop=4   edge move from 4 to=5
stack=[7,6,3,1,5] ,d=[0,4,3,inf,5,6,inf,inf]  dit[4]+w(4,5)=5+1

pop=5   edge move from 5 to=3
stack=[7,6,3,1] ,d=[0,4,3,8,5,6,inf,inf]  dit[5]+w(5,3)=6+2

pop=1   edge move from 1 to=3
stack=[7,6,3] ,d=[0,4,3,8,5,6,inf,inf]  min(dit[1]+w(1,3)=4+6,dist[3]=8)=8

pop=3  edge move from 3 to=6
stack=[7,6] ,d=[0,4,3,8,5,6,13,inf]  dit[3]+w(3,6)=8+5

pop=6  edge move from 6 to=7
stack=[7] ,d=[0,4,3,8,5,6,13,17]  dit[6]+w(6,7)=13+4

pop=7  no edge move
stack=[] ,d=[0,4,3,8,5,6,13,17]  

*/
#include<bits/stdc++.h>
using namespace std;
void DFS(int node,vector<pair<int,int>>AdjList[],stack<int>&s,vector<bool>&visited){
    visited[node]=1;
    for(auto neighbour:AdjList[node]){
        if(!visited[neighbour.first]){
            DFS(neighbour.first,AdjList,s,visited);
        }
    }
    s.push(node);
}
int main(){
    vector<vector<int>>edges={{0,1,4},{0,2,3},{1,3,6},{2,4,2},{3,6,5},{4,5,1},{5,3,2},{6,7,4}};
    int n=9;
    int m=edges.size();
    vector<pair<int,int>>AdjList[n];//node,weight
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int weight=edges[i][2];
        AdjList[u].push_back({v,weight});
    }
    stack<int>s;
    vector<bool>visited(n,0);
    vector<int>dist(n,INT_MAX);
    DFS(0,AdjList,s,visited);
    dist[0]=0;
    while(!s.empty()){
        int node=s.top();
        s.pop();
        for(auto neighbour:AdjList[node]){
            int weight=neighbour.second;
            dist[neighbour.first]=min(dist[neighbour.first],weight+dist[node]);
        }
    }
    for(int i=0;i<n;i++){
        if(dist[i]==INT_MAX) dist[i]=-1; //indicate this node is not able to visit 
    }
    for(int i=0;i<n;i++){
        cout<<dist[i]<<" ";  
    }
    return 0;
}
/*
tc=
(V+E)->adjlist
(V+E)->topo-sort
(V+E)->stack
tc=O(V+E)
sc=O(V+E)
*/