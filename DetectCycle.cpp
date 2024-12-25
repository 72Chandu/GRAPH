/*detect a cycle in an undirected graph
0->1
1->0,2,4
2->1,3
3->2,4
4->1,3
[0]  
[0,1] 0->1
[0,1,2]   1->0,2,4 , not 0 because it is parent of 1
[0,1,2,3] 2->1,3 ,not 1 because it is parent of 2
[0,1,2,3,4] 3->2,4 ,not 2 because it is parent of 3
[0,1,2,3,4,1] 4->1,3 ,not 3 because it is parent of 4
1 is visited 2 times so, there is loop
->ignore the parent node
->neighbour node allready visited ->cycle found
->viste the neighboure
*/
#include<bits/stdc++.h>
using namespace std;
bool DetectCycleUsingBFS(vector<int> AdjList[], vector<int>& visited) {
    visited[0]=1;
    queue<pair<int,int>>q; //{ele, EleParent}
    q.push(make_pair(0,-1));
    while(!q.empty()){
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();
        for(int j=0;j<AdjList[node].size();j++){
            int neighbour = AdjList[node][j]; // Get the adjacent node
            if (parent == neighbour) continue; // Skip the edge to the parent node
            if (visited[neighbour] == 1) return 1; // Cycle detected
            visited[neighbour]=1;
            q.push(make_pair(neighbour,node));
        }
    }
    return 0;
}
/*tc=O(V+2E), sc=O(V+V)*/
bool DetectCycleUsingDFS(int node, int parent, vector<int> AdjList[], vector<int>& visited) {
    visited[node] = 1; // Mark the current node as visited
    for (int j = 0; j < AdjList[node].size(); j++) {
        int neighbour = AdjList[node][j]; // Get the adjacent node
        if (parent == neighbour) continue; // Skip the edge to the parent node
        if (visited[neighbour] == 1) return 1; // Cycle detected
        if (DetectCycleUsingDFS(neighbour, node, AdjList, visited)) return 1; // Recur for the adjacent node
    }
    return 0; // No cycle detected
}/*tc=O(V+2E)  sc=O(v+v) */
int main() {
    int n = 5; // Total number of nodes (0 to 4)
    vector<int> AdjList[n];
    AdjList[0] = {1};
    AdjList[1] = {0, 2, 4};
    AdjList[2] = {1, 3};
    AdjList[3] = {2, 4};
    AdjList[4] = {1, 3};
    vector<int> visited(n, 0);
    bool hasCycle = false;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) { // If the node is not visited
            // if (DetectCycleUsingDFS(i, -1, AdjList, visited)) { // Start DFS from the node
            //     hasCycle = true;
            //     break;
            // }
            if (DetectCycleUsingBFS(AdjList, visited)) {
                hasCycle = true;
                break;
            }
        }
    }
    if (hasCycle) {
        cout << "Cycle detected in the graph." << endl;
    } else {
        cout << "No cycle detected in the graph." << endl;
    }
    return 0;
}
