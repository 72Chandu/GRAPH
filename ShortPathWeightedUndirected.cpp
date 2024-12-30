/*22.Shortest path in weighted undirected graph(google map backend)
0->{1,6},{2,2}
1->{0,6},{2,3},{3,7}
2->{0,2},{1,3},{4,4}
3->{1,7},{5,2},{4,5}
4->{2,4},{3,5},{5,9}
5->{3,2},{4,9}
use Dijkstra's Algorithm and read 17.Shortest path between two node in undirected graph

similar concept is use behinde the google map to find the shortest distance 

*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<pair<int, int>>> AdjList(6);
    AdjList[0] = {{1,6},{2,2}};
    AdjList[1] = {{0,6},{2,3},{3,7}};
    AdjList[2] = {{0,2},{1,3},{4,4}};
    AdjList[3] = {{1,7},{5,2},{4,5}};
    AdjList[4] = {{2,4},{3,5},{5,9}};
    AdjList[5] = {{3,2},{4,9}};
    int v=6;
    vector<int>dist(v,INT_MAX);
    vector<int>parent(v,0);
    vector<int>explore(v,0);
    int src=0;
    int dest=5;
    dist[src]=0;
    parent[src]=-1;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,src});
    while(!pq.empty()){
        int node=pq.top().second;
        pq.pop();
        if(explore[node]) continue;
        explore[node];

        for(auto neighbor:AdjList[node]){
            int neighbour=neighbor.first;
            int weight=neighbor.second;
            if(!explore[neighbour] && dist[node]+weight<dist[neighbour]){
                dist[neighbour]=dist[node]+weight;
                pq.push({dist[neighbour],neighbour});
                parent[neighbour]=node;
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
}