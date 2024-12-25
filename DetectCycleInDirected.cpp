/*directed graph 
deadlock

if there is node if its neighbour is allready visited and its not a parent -> cycle but not true for directed graph
-> current path me koi element 2 baar aa jata hai to cycle hai

dfs-> 
jab jab new path me move kartey jayege tab new node ko 1 karna hai path me ,
jab end tak chale jayege , back move karey wakt us particular node ke path wala array ko 0 kartey jana hai 
we must travese all possible path 
path=[0,0,0,0,0,0,0] tells wether the node is part of path or not 
it is also call dfs stack

bfs->
Topological sort -> only for direacted asyclic graph 
if cycle present then we cant sort
applay khans algo on dircted cyclic graph
-> cycleic part never be in answer beacuse cycle me atleast 1 degree to hoga therefor it cant move to queue and cant be the part of answer
-> count of ans!=vertex -> cycle present 

*/
#include<bits/stdc++.h>
using namespace std;
void DetectCycleUsingBFS(vector<int> AdjList[], int v) {
   vector<int> ans;
    vector<int> InDeg(v, 0);
    for (int i = 0; i < v; i++) {// Calculating in-degrees
        for (int j = 0; j < AdjList[i].size(); j++) {
            InDeg[AdjList[i][j]]++;
        }
    }
    queue<int> q;
    // Add all nodes with in-degree 0 to the queue
    for (int i = 0; i < v; i++) {
        if (InDeg[i] == 0) q.push(i);
    }
    // Perform Kahn's Algorithm
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (int j = 0; j < AdjList[node].size(); j++) {// Reduce in-degree of neighbors by 1
            InDeg[AdjList[node][j]]--;
            if (InDeg[AdjList[node][j]] == 0) q.push(AdjList[node][j]);
        }
    }
    // Check for cycles (if all nodes are not processed)
    if (ans.size() != v) {
        cout << "The graph contains a cycle.";
    }else{
        cout << "The graph not contains a cycle.";
    } 
}
bool DetectCycleUsingDFS(int node, vector<int> AdjList[], vector<bool>& path, vector<bool>& visited) {
    visited[node] = 1; // Mark the node as visited, for not travese same the path again
    path[node] = 1;    // Mark the node in the current path
    for (int neighbour : AdjList[node]) {
        if (path[neighbour]) return 1; // if curr node is alredy present in path then Cycle found
        if (visited[neighbour])  continue;//if neighboure is already visited skip it 
        if (DetectCycleUsingDFS(neighbour, AdjList, path, visited)) return 1;
    }
    path[node] = 0; // Backtrack: remove the node from the current path
    return 0;       // No cycle found
}//tc=O(V+E) sc=O(V)

int main() {
    int n = 5; 
    vector<int> AdjList[n];
    AdjList[0] = {1};
    AdjList[1] = {2};
    AdjList[2] = {3};
    AdjList[3] = {1, 4}; // Back edge creates a cycle
    AdjList[4] = {};
    vector<bool> visited(n, 0);
    vector<bool> path(n, 0);
    bool hasCycle = false;
    for (int i = 0; i < n; i++) { //graph can be disconnected so we do check all node 
        // if (!visited[i] && DetectCycleUsingDFS(i, AdjList, path, visited)) {
        //     hasCycle = true;
        //     break;
        // }
    }
    // if (hasCycle) {
    //     cout << "Cycle detected in the graph." << endl;
    // } else {
    //     cout << "No cycle detected in the graph." << endl;
    // }

    DetectCycleUsingBFS(AdjList,n);
    return 0;
}