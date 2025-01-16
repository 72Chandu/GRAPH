/*
Minimum Spanning Tree(MST) | Prims Algorithm

Spanning Tree: it is subset of edges of the graph that forms a tree where every node of the graph is a part of tree
tree:  n node, n-1 edge , no cycle, all nodes are connected

ex: all the state are connected with rails with minimum cost, similar for cable line, 

how to find MST
m-1: draw all possible ST and calcuate the cost of each and at last return minimum one
m-2: Prims algo
Initialize the MST with a randomly chosen vertex.
Find all edges that connect the tree to new vertices, select the minimum edge among all edge, and add it to the tree.
Repeat step 2 until all vertices are included in the MST.

ex:
0->{1,4},{7,8}
1->{0,4},{2,8},{7,11}
2->{1,8},{3,7},{8,2}
3->{2,7},{4,9},{5,14}
4->{3,9},{5,10}
5->{6,2},{4,10},{3,14}
6->{8,6},{7,1}
7->{1,11},{8,7},{0,8}
8->{7,7},{2,2},{6,6}


      0 1 2 3 4 5 6 7 8  
ISMST=[0,0,0,0,0,0,0,0,0]    PARENT=[]
NEED OF MIN HEAP (PQ)(WT,NODE,PARENT)=[] , COST=0m {NODE--PARENT}->denote edge 

PQ=[{0,0,-1}]  
pop pop min wt={0,0,-1} then push its neighbour which is not a part of MST
PQ=[{4,1,0},{8,7,0}]  ISMST=[1,0,0,0,0,0,0,0,0]  PARENT=[-1] COST=0

pop min wt={4,1,0} push its neighbour which is not a part of MST
PQ=[{8,7,0},{8,2,1},{11,7,1}]  ISMST=[1,1,0,0,0,0,0,0,0]  PARENT=[-1,0] COST=4

pop min wt={8,2,1}, push its neighbour which is not a part of MST
PQ=[{8,7,0},{11,7,1},{2,8,2},{7,3,2}]  ISMST=[1,1,1,0,0,0,0,0,0]  PARENT=[-1,0,1] COST=4+8

pop min wt={2,8,2}, push its neighbour which is not a part of MST
PQ=[{8,7,0},{11,7,1},{7,3,2},{6,6,8},{7,7,8}]  ISMST=[1,1,1,0,0,0,0,0,1]  PARENT=[-1,0,1,-1,-1,-1,-1,-1,2] COST=4+8+2

pop min wt={6,6,8}, push its neighbour which is not a part of MST
PQ=[{8,7,0},{11,7,1},{7,3,2},{7,7,8},{1,7,6},{2,5,6}]  ISMST=[1,1,1,0,0,0,1,0,1]  PARENT=[-1,0,1,-1,-1,-1,8,-1,2] COST=4+8+2+6

pop min wt={1,7,6}, push its neighbour which is not a part of MST-> no one
PQ=[{8,7,0},{11,7,1},{7,3,2},{7,7,8},{2,5,6}]  ISMST=[1,1,1,0,0,0,1,1,1]  PARENT=[-1,0,1,-1,-1,-1,8,6,2] COST=4+8+2+6+1

pop min wt={2,5,6}, push its neighbour which is not a part of MST
PQ=[{8,7,0},{11,7,1},{7,3,2},{7,7,8},{10,4,5},{14,3,5}]  ISMST=[1,1,1,0,0,1,1,1,1]  PARENT=[-1,0,1,-1,-1,6,8,6,2] COST=4+8+2+6+1+2

pop min wt={7,3,2}
PQ=[{8,7,0},{11,7,1},{7,7,8},{10,4,5},{14,3,5},{9,4,3}]  ISMST=[1,1,1,1,0,1,1,1,1]  PARENT=[-1,0,1,2,-1,6,8,6,2] COST=4+8+2+6+1+2+7

pop min wt={7,7,8}
PQ=[{8,7,0},{11,7,1},{10,4,5},{14,3,5},{9,4,3}]  ISMST=[1,1,1,1,0,1,1,1,1]  PARENT=[-1,0,1,2,-1,6,8,6,2] COST=4+8+2+6+1+2+7

pop min wt={8,7,0}
PQ=[{11,7,1},{10,4,5},{14,3,5},{9,4,3}]  ISMST=[1,1,1,1,0,1,1,1,1]  PARENT=[-1,0,1,2,-1,6,8,6,2] COST=4+8+2+6+1+2+7

pop min wt={9,4,3}, push its neighbour which is not a part of MST
PQ=[{11,7,1},{10,4,5},{14,3,5}]  ISMST=[1,1,1,1,1,1,1,1,1]  PARENT=[-1,0,1,2,3,6,8,6,2] COST=4+8+2+6+1+2+7+9

pop min wt={10,4,5}
PQ=[{11,7,1},{14,3,5}]  ISMST=[1,1,1,1,1,1,1,1,1]  PARENT=[-1,0,1,2,3,6,8,6,2] COST=4+8+2+6+1+2+7+9

pop min wt={11,7,1}, 
PQ=[{14,3,5}]  ISMST=[1,1,1,1,1,1,1,1,1]  PARENT=[-1,0,1,2,3,6,8,6,2] COST=4+8+2+6+1+2+7+9

pop min wt={14,3,5}, 
PQ=[]  ISMST=[1,1,1,1,1,1,1,1,1]  PARENT=[-1,0,1,2,3,6,8,6,2] COST=4+8+2+6+1+2+7+9=39
  
         0 1 2 3 4 5 6 7 8
PARENT=[-1,0,1,2,3,6,8,6,2] generate MST
edge b/w index(i) and parent[i]
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<pair<int, int>>> AdjList = {
        {{1, 4}, {7, 8}},           // Neighbors of node 0
        {{0, 4}, {2, 8}, {7, 11}},  // Neighbors of node 1
        {{1, 8}, {3, 7}, {8, 2}},   // Neighbors of node 2
        {{2, 7}, {4, 9}, {5, 14}},  // Neighbors of node 3
        {{3, 9}, {5, 10}},          // Neighbors of node 4
        {{6, 2}, {4, 10}, {3, 14}}, // Neighbors of node 5
        {{8, 6}, {7, 1}},           // Neighbors of node 6
        {{1, 11}, {8, 7}, {0, 8}},  // Neighbors of node 7
        {{7, 7}, {2, 2}, {6, 6}}    // Neighbors of node 8
    };
    int v = AdjList.size();
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<bool> IsMST(v, false);
    vector<int> parent(v, -1);
    int cost = 0;
    // Start with node 0
    pq.push({0, {0, -1}}); // {weight, {current_node, parent_node}}
    while (!pq.empty()) {
        int wt = pq.top().first;         // Weight of the edge
        int node = pq.top().second.first; // Current node
        int par = pq.top().second.second; // Parent node
        pq.pop();
        if (!IsMST[node]) {
            // Mark the node as included in MST
            IsMST[node] = true;
            cost += wt;
            parent[node] = par;
            // Traverse neighbors
            for (auto neighbor : AdjList[node]) {
                int nextNode = neighbor.first;  // Neighboring node
                int edgeWeight = neighbor.second; // Weight of the edge
                if (!IsMST[nextNode]) {
                    pq.push({edgeWeight, {nextNode, node}});
                }
            }
        }
    }
    cout << "Total cost of MST: " << cost << endl;
    cout << "Parent array:" << endl;
    for (int i = 0; i < v; ++i) {
        cout << "Node " << i << " -> Parent: " << parent[i] << endl;
    }
    return 0;
}
/*
sc=v+e
tc=e*loge(push) + e*loge(pop) ==eloge
*/