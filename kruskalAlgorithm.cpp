/*
Minimum Spanning Tree |Kruskal Algorithm: alwayse find the minimum weighted edge and joint them (do not think about continious connection during stabilising edge in mst). do choose those edge who form circle
0->{1,4},{7,8}
1->{0,4},{2,8},{7,11}
2->{1,8},{3,7},{8,2}
3->{2,7},{4,9},{5,14}
4->{3,9},{5,10}
5->{6,2},{4,10},{3,14}
6->{8,6},{7,1}
7->{1,11},{8,7},{0,8},{6,1}
8->{7,7},{2,2},{6,6}
o/p=39
disjoint set  -> diffrent set connect them
     0 1 2 3 4 5 6 7 8 9 -index of set
set=[0,1,2,3,4,5,6,7,8,9] -> inially there are 9 set each vertex have seprat set
minimum edge=1 b/w=6,7 (vertex,vertex) vertex indicate by index
set=[0,1,2,3,4,5,6,6,8,9]
minimum edge=2 b/w=6,5
set=[0,1,2,3,4,6,6,6,8,9]
minimum edge=2 b/w=2,8
set=[0,1,8,3,4,6,6,6,8,9]
minimum edge=4 b/w=0,1
set=[0,0,8,3,4,6,6,6,8,9]
minimum edge=6 b/w=8,6 , 6 and 8 are of diff set mark all 8 to 6 to come in one set
set=[0,0,6,3,4,6,6,6,6,9]
minimum edge=7 b/w=2,3  2 and 3 are of diff set mark them in 6
set=[0,0,6,6,4,6,6,6,6,9]

parent-> ultimate parent , konsa set me hoga
rank->kis set ko kis set me merge karna hai (height)
1. find the ultimate parent of u and v
2.find the rank of ultimate (pu,pv)
merge the smallest set into large set (on the basic of rank
(0,1) 0->1 edge denotes
(1,2)
(3,4)
(5,6)
(7,9)
(3,6)
(4,6)
(1,4)
(8,5)
        0 1 2 3 4 5 6 7 8
parnet=[0,1,2,3,4,5,6,7,8]    up=ultimate parent 
rank=[0,0,0,0,0,0,0,0,0]
             0 1 2 3 4 5 6 7 8
0->1:parnet=[0,0,2,3,4,5,6,7,8] rank=[1,0,0,0,0,0,0,0,0]

1->2:up(0 ,2)->diff set , rank of up(1,0), rank of 1>2==0->2
parnet=[0,0,0,3,4,5,6,7,8] rank=[1,0,0,0,0,0,0,0,0]

3->4:up(3, 4)->diff set , rank of up(0,0), 3->4
parnet=[0,0,0,3,3,5,6,7,8] rank=[1,0,0,1,0,0,0,0,0]

5->6:up(5, 6)->diff set , rank of up(0,0), 5->6
parnet=[0,0,0,3,3,5,5,7,8] rank=[1,0,0,1,0,1,0,0,0]

7->8:up(7, 8)->diff set , rank of up(0,0), 7->8
parnet=[0,0,0,3,3,5,5,7,7] rank=[1,0,0,1,0,1,0,1,0]

3->6:up(3, 5)->diff set , rank of up(1,1), 3->5 : 3->5->6 3->4
parnet=[0,0,0,3,3,3,5,7,7] rank=[1,0,0,2,0,1,0,1,0]

4->6:up(3, 5(x),3)->same set: skip that edge :  5(x)->6 ka parnet 5,  5 ka parnet 3, 3 ka parnet is 3 itself  =it is ultimate parent : 3->5->6 3->4

1->4:up(0, 3)->diff set , rank of up(1,2), 3->0 : 3->5->6 3->4 3->0->2 0->1
parnet=[3,0,0,3,3,3,5,7,7] rank=[1,0,0,2,0,1,0,1,0]

8->5:up(7, 3)->diff set , rank of up(1,2), 3->7->8
parnet=[3,0,0,3,3,3,5,3,7] rank=[1,0,0,2,0,1,0,1,0]


1.pirraty queue -> insert all the edge into pq : pair<w,pair<u,v>>
*/
#include <bits/stdc++.h>
using namespace std;
int findUltimateParent(int u, vector<int> &p) {
    if (u == p[u]) return u;
    return p[u] = findUltimateParent(p[u], p);
}
void UnionByRank(int u, int v, vector<int> &parent, vector<int> &rank) {
    int pu = findUltimateParent(u, parent);
    int pv = findUltimateParent(v, parent);
    if (rank[pu] > rank[pv]) {
        parent[pv] = pu;
    } else if (rank[pu] < rank[pv]) {
        parent[pu] = pv;
    } else {
        parent[pv] = pu;
        rank[pu]++;
    }
}
int main() {
    vector<vector<pair<int, int>>> AdjList = {
        {{1, 4}, {7, 8}},           // Neighbors of node 0
        {{0, 4}, {2, 8}, {7, 11}},  // Neighbors of node 1
        {{1, 8}, {3, 7}, {8, 2}},   // Neighbors of node 2
        {{2, 7}, {4, 9}, {5, 14}},  // Neighbors of node 3
        {{3, 9}, {5, 10}},          // Neighbors of node 4
        {{6, 2}, {4, 10}, {3, 14}}, // Neighbors of node 5
        {{8, 6}, {7, 1}},           // Neighbors of node 6
        {{1, 11}, {8, 7}, {0, 8}, {6, 1}},  // Neighbors of node 7
        {{7, 7}, {2, 2}, {6, 6}}    // Neighbors of node 8
    };
    int v = AdjList.size();
    vector<int> parent(v);
    vector<int> rank(v, 0);
    for (int i = 0; i < v; i++) {
        parent[i] = i;
    }

    // Priority queue to store edges with their weights
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    for (int i = 0; i < v; i++) {
        for (auto edge : AdjList[i]) {
            int adjNode = edge.first;
            int weight = edge.second;
            pq.push({weight, {i, adjNode}});
        }
    }

    // Implementing Kruskal's algorithm
    int mstWeight = 0;
    while (!pq.empty()) {
        int weight = pq.top().first;
        int u = pq.top().second.first;
        int v = pq.top().second.second;
        pq.pop();

        // If u and v are in different sets, union them
        if (findUltimateParent(u, parent) != findUltimateParent(v, parent)) {
            mstWeight += weight;
            UnionByRank(u, v, parent, rank);
        }
    }
    cout << "Weight of the Minimum Spanning Tree: " << mstWeight << endl;
    return 0;
}
//tc=eloge