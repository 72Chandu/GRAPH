/*
only for directed acyclic graph

ex:1
0->1,2
1->3
2->3
3
for u->v , u allwase comes before v
ans=0,2,1,3 or 0,1,2,3 multiple answer
0          visited[1,0,0,0]
0->1       visited[1,1,0,0]
0->1->3    visited[1,1,0,1]
there no one after 3 now push into stack while returning
stack=[3]
stack=[3,1]
0->2     visited[1,1,1,1]
stack=[3,1,2]
stack=[3,1,2,0]
now remove element : 0,2,1,3
ex:2
0->1
1->2
2->3
3
4->5
5->0
4->5->0->1->2->3
ans=4,5,0,1,2,3
start with 0  dfs
0          visited[1,0,0,0,0,0]
0->1       visited[1,1,0,0,0,0]
0->1->2    visited[1,1,1,0,0,0]
0->1->2->3 visited[1,1,1,1,0,0]
there no one after 3 now push into stack while returning
stack=[3]
stack=[3,2]
stack=[3,2,1]
stack=[3,2,1,0]
4    visited[1,1,1,1,1,0]
4->5 visited[1,1,1,1,1,1]
there no one after 5 now push into stack while returning
stack=[3,2,1,0,5]
stack=[3,2,1,0,5,4]
       bot       top
now remove element : 4,5,0,1,2,3

*/
#include <bits/stdc++.h>
using namespace std;
void DFStopologicalSort(int node, vector<int> AdjList[], vector<bool> &visited, stack<int> &s) {
    visited[node] = 1;
    // Look at its neighbors one by one
    for (int neighbour : AdjList[node]) {
        if (!visited[neighbour]) {
            DFStopologicalSort(neighbour, AdjList, visited, s);
        }
    }
    s.push(node);
}
int main() {
    int v = 6; 
    vector<int> AdjList[v];    
    AdjList[0] = {1};
    AdjList[1] = {2};
    AdjList[2] = {3};
    AdjList[3] = {};
    AdjList[4] = {5};
    AdjList[5] = {};
    vector<bool> visited(v, 0);
    stack<int> s;
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            DFStopologicalSort(i, AdjList, visited, s);
        }
    }
    vector<int> ans;
    while (!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }
    for (auto i : ans) {
        cout << i << " ";
    }
    return 0;
}
