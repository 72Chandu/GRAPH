/*
Dijkstra's Algorithm methode 2 on directed graph

*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<pair<int, int>>> AdjList(6);
    AdjList[0] = {{1, 6}, {2, 2}};
    AdjList[1] = {{3, 7}, {2, 3}};
    AdjList[2] = {{4, 4}};
    AdjList[3] = {{5, 2}, {4, 5}};
    AdjList[4] = {{5, 9}};
    AdjList[5] = {}; // Node 5 has no outgoing edges

    int v=6;
    vector<bool>explore(v,0);
    vector<int>dist(v,INT_MAX);
    int src=0;
    dist[src]=0;
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
            if(dist[node]+weight<dist[neighbour]){
                dist[neighbour]=dist[node]+weight;
                pq.push({dist[neighbour],neighbour});
            }
        }
    }
    // Print final distances from source
    for (int i = 0; i < v; i++) {
        if (dist[i] == INT_MAX) {
            cout << "Distance from node " << src << " to node " << i << ": INF" << endl;
        } else {
            cout << "Distance from node " << src << " to node " << i << ": " << dist[i] << endl;
        }
    }
    return 0;

}