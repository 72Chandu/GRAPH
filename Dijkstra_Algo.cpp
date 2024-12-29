/*
Dijkstra's Algorithm

0->{1,6},{2,2}
1->{0,6},{3,7},{2,3}
2->{0,2},{1,3},{4,4}
3->{1,7},{5,2},{4,5}
4->{2,4},{3,5},{5,9}
5->{3,2},{4,9}
find the sortest path to reach the any node from 0 

src=0, neighbour of 0=1,2
explore=[1,0,0,0,0,0],d=[0,6,2,inf,inf,inf] 

min of d=2 v=2,not 0 beacuse it is explored,  neighbour of 2=1,4
explore=[1,0,1,0,0,0],d=[0,5,2,inf,6,inf] d[1]=min(d[1]=6,d[2]+w(2,1)=2+3)=5

min of d=5,v=1,not 0,2 beacuse it is explored,  neighbour of 1=3,2(ex)
explore=[1,1,1,0,0,0],d=[0,5,2,12,6,inf] d[3]=d[1]+w(1,3)=5+7=12

min of d=6,v=4,not 0,2,5 beacuse it is explored,  neighbour of 4=3,2(ex),5
explore=[1,1,1,0,1,0],d=[0,5,2,11,6,15]    d[5]=d[4]+w(4,5)=6+9=15, d[3]=min(d[3],d[4]+w(4,3))=11

min of d=11,v=3,not 0,2,5,6 beacuse it is explored,  neighbour of 3=1(ex),4,5
explore=[1,1,1,1,1,0],d=[0,5,2,11,6,13]     d[4]=min(d[4],d[3]+w(3,4))=6, d[5]=min(d[5],d[3]+w(3,5))=13,

min of d=13,v=5,not 0,2,5,6,11 beacuse it is explored,  neighbour of 3=1(ex),4,5
explore=[1,1,1,1,1,1],d=[0,5,2,11,6,13]

select the vertex which is not explored yet and its dist is minimum amoung all the unexplored vertex
releax the edeges
  look at your all the unexpolored neighboure
  if(dit[node]+weight<dist[neighbour]) dit[neighbourr]=dist[node]+weight
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<int>>AdjList[6]={{{1,6},{2,2}},{{0,6},{3,7},{2,3}},{{0,2},{1,3},{4,4}},{{1,7},{5,2},{4,5}},{{2,4},{3,5},{5,9}},{{3,2},{4,9}}};
    int v=6;
    vector<bool>explore(v,0);
    vector<int>dist(v,INT_MAX);
    int src=0;
    dist[src]=0;

    int count=v;
    while(count--){
    int node=-1, value=INT_MAX;
    for(int i=0;i<v;i++){
        if(!explore[i] && value>dist[i]){
            node=i;
            value=dist[i];
        }
    }
    explore[node]=1;
    //relax the edge
    for(int j=0;j<AdjList[node].size();j++){
        int neighbour=AdjList[node][j][0];
        int weight=AdjList[node][j][1];
        if(!explore[neighbour] && (dist[node]+weight < dist[neighbour])){
            dist[neighbour]=dist[node]+weight;
        }
    }
    }
    for(int i=0;i<v;i++){
        cout<<dist[i]<<" ";
    }
    return 0;
}
/*
tc=O(v*(v-1))=O(v^2)
sc=O(v)
*/