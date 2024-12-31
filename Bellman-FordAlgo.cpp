/*
Bellman-Ford Algorithm |distance from the source
use for shortest path in negative weight graph which is not in Dijkstra's algo

0->{1,3},{2,5}
1->
2->{1,-3}
src=0 pq=(dist,node)
-------According to Dijkstra's algo-----
pq=[(0,0)] dist=[inf,inf,inf] exp=[0,0,0]
pop, neigh 0=1,2
pq=[(3,1),(5,2)] dist=[0,inf,inf] exp=[1,0,0]
pop, neigh 1
pq=[(5,2)] dist=[0,3,inf] exp=[1,1,0]
pop, neigh 2
pq=[] dist=[0,3,5] exp=[1,1,1]
o/p=dist=[0,3,5] but this is wrong 

but the correct output is
0-> =0
0->2->1 =0+5-3=2
0->2 =5
dist=[0,2,5]

if we remove the explore concept then we get the correct answer but in case of negative cycle 
it will not generate correct answer. in negative cycle we traverse to infinite loop to find answer bu we not get
negative cycle = sum of edge is negative with cycle

for removing all the problem we use Bellman-Ford Algorithm 
-> only in directed graph
algo
-> (relax you all edges)*(v-1) times      u->v
     dist[u]+wt<dist[v]
          dist[v]=dist[u]+wt
->relax your edges one more time 
         cycle detect (dist vlaue change then cycle detect, if not then you get shortest path)

ex:
u  v wt
2, 4, 2
3, 4, -2
2, 3, -3
0, 2, 5
1, 3, 1
0, 1, 3
5-> vertex , we have to run 4 times
src=0,
dist=[0,inf,inf,inf,inf]
1st times 
d[2]+2<d[4]    2, 4, 2
d[3]+-2<d[4]   3, 4, -2
d[2]+-3<d[3]   2, 3, -3
d[0]+5<d[2]    0, 2, 5
dist=[0,inf,5,inf,inf]
d[1]+3<d[1]    1, 3, 1
d[0]+3<d[1]    0, 1, 3
dist=[0,3,5,inf,inf]

2nd times
d[2]+2<d[4]    2, 4, 2
dist=[0,3,5,inf,7]
d[3]+-2<d[4]   3, 4, -2
d[2]+-3<d[3]   2, 3, -3
dist=[0,3,5,2,7]
d[0]+5<d[2]    0, 2, 5
d[1]+3<d[1]    1, 3, 1
d[0]+3<d[1]    0, 1, 3

3rd times  dist=[0,3,5,2,7]
d[2]+2<d[4]    2, 4, 2
d[3]+-2<d[4]   3, 4, -2
dist=[0,3,5,2,0]
d[2]+-3<d[3]   2, 3, -3
d[0]+5<d[2]    0, 2, 5
d[1]+3<d[1]    1, 3, 1
d[0]+3<d[1]    0, 1, 3

4rth times  dist=[0,3,5,2,0]
d[2]+2<d[4]    2, 4, 2
d[3]+-2<d[4]   3, 4, -2
d[2]+-3<d[3]   2, 3, -3
d[0]+5<d[2]    0, 2, 5
d[1]+3<d[1]    1, 3, 1
d[0]+3<d[1]    0, 1, 3

relex 1 more 
d[2]+2<d[4]    2, 4, 2
d[3]+-2<d[4]   3, 4, -2
d[2]+-3<d[3]   2, 3, -3
d[0]+5<d[2]    0, 2, 5
d[1]+3<d[1]    1, 3, 1
d[0]+3<d[1]    0, 1, 3
non of dist is chnages
ans= dist=[0,3,5,2,0]

we can applay this in undirected graph we should do only give edge
u->v, v->u with same weight , and applay Bellman-Ford Algorithm 
but do not applay it 

undirected graph with negative weight do not get shortest path

*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<int>>edges={{2,4,2},{3,4,-2},{2,3,-3},{0,2,5},{1,3,1},{0,1,3}};//{u,v,w}
    int e=edges.size();
    int v=5;
    int src=0;
    vector<int>dist(v,1e8);
    dist[src]=0;
    for(int i=0;i<v-1;i++){ //relax edges v-1 times
        for(int j=0;j<e;j++){//relax edges
            int u=edges[j][0];
            int v=edges[j][1];
            int w=edges[j][2];
            if(dist[u]==1e8) continue; //optimise
            if(dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
            }
        }
    }
    //to detuct the cycle, 1 more times relax edges
    for(int j=0;j<e;j++){
        int u=edges[j][0];
        int v=edges[j][1];
        int w=edges[j][2];
        if(dist[u]==1e8) continue; //optimise
        if(dist[u]+w<dist[v]){
            //cycle detected
            cout<<"-1"<<endl;
            return 0;
        }
    }
    for(int i=0;i<dist.size();i++){
        cout<<dist[i]<<" ";
    }
    return 0;
}//tc=(v-1)*e+e=v*e , best case=tc=e
/*
best case=tc=e
for(int i=0;i<v-1;i++){ //relax edges v-1 times
        bool falg=0; //optimise 
        for(int j=0;j<e;j++){//relax edges
            int u=edges[j][0];
            int v=edges[j][1];
            int w=edges[j][2];
            if(dist[u]==1e8) continue; //optimise
            if(dist[u]+w<dist[v]){
                falg=1;
                dist[v]=dist[u]+w;
            }
        }
        if(!falg){
            for(int i=0;i<dist.size();i++){
                cout<<dist[i]<<" ";
            }
            return 0;
        }
    }
    for(int j=0;j<e;j++){
        int u=edges[j][0];
        int v=edges[j][1];
        int w=edges[j][2];
        if(dist[u]==1e8) continue; //optimise
        if(dist[u]+w<dist[v]){
            //cycle detected
            cout<<"-1"<<endl;
            return 0;
        }
    }

*/