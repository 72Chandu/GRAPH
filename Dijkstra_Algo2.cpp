/*
Dijkstra's Algorithm  methode 2

0->{1,6},{2,2}
1->{0,6},{3,7},{2,3}
2->{0,2},{1,3},{4,4}
3->{1,7},{5,2},{4,5}
4->{2,4},{3,5},{5,9}
5->{3,2},{4,9}
find the sortest path to reach the any node from 0
src=0, neighbour of 0=1,2
explore=[1,0,0,0,0,0],d=[0,6,2,inf,inf,inf]

in this approach only the selection of min distance is from Priority queue and rest process is same
pair<dist,node> (min heap)-> for finding min elemnt fron distance give O(logn)
when you update the distnce then push that node and value in Priority queue

space=exp(v)+dist(v)+priority queue(E(complete graph))
tc=ElogE+ElogE
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<pair<int, int>>> AdjList(6);
    AdjList[0] = {{1, 6}, {2, 2}};
    AdjList[1] = {{0, 6}, {3, 7}, {2, 3}};
    AdjList[2] = {{0, 2}, {1, 3}, {4, 4}};
    AdjList[3] = {{1, 7}, {5, 2}, {4, 5}};
    AdjList[4] = {{2, 4}, {3, 5}, {5, 9}};
    AdjList[5] = {{3, 2}, {4, 9}};
    int v = 6;
    vector<bool> explore(v, false); 
    vector<int> dist(v, INT_MAX);
    int src = 0; 
    dist[src] = 0;

    // Priority queue for Dijkstra's algorithm
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;
    p.push({0, src});
    while (!p.empty()) {
        int node = p.top().second; //allwayse a min distance from p
        p.pop();
        if (explore[node]) continue; // Skip if already explored
        explore[node] = true;

        // Relax edges
        for (const auto& neighbor : AdjList[node]) {
            int neighbour = neighbor.first;
            int weight = neighbor.second;

            if (!explore[neighbour] && dist[node] + weight < dist[neighbour]) {
                dist[neighbour] = dist[node] + weight;
                p.push({dist[neighbour], neighbour});
            }
        }
    }

    // Print final distances from source
    for (int i = 0; i < v; i++) {
        cout << dist[i] <<" ";
    }
    return 0;
}
