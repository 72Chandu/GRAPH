/*
AdjList
0 ->1,3,2
1 ->0,7,4
2 ->0,5
3 ->0
4 ->1,5
5 ->4,6,2
6 ->5
7 ->1
do with recurrsion
end tak move karna hai jab tak koi option nahi ba
visited array
ans
[0]  visited=[1,0,0,0,0,0,0,0]
[0,1]  visited=[1,1,0,0,0,0,0,0]  ,0 ->1(vis),3,2
[0,1,7]  visited=[1,1,0,0,0,0,0,1] ,1 ->7(vis),4
[0,1,7,4]  visited=[1,1,0,0,0,0,0,1] ,7 ->1(done),
[0,1,7,4]  visited=[1,1,0,0,1,0,0,1] ,1 ->7(done),4(vis)
[0,1,7,4,5]  visited=[1,1,0,0,1,1,0,1], 4 ->1(done),5(vis)
[0,1,7,4,5,6]  visited=[1,1,0,0,1,1,1,1], 5 ->4(done),6(vis),2
[0,1,7,4,5,6]  visited=[1,1,0,0,1,1,1,1], 6 ->5(done)
[0,1,7,4,5,6,2]  visited=[1,1,1,0,1,1,1,1], 5 ->4(done),6(done),2(vis)
[0,1,7,4,5,6]  visited=[1,1,1,0,1,1,1,1], 2 ->0(done),5(done)
[0,1,7,4,5,6,3]  visited=[1,1,1,1,1,1,1,1], 0 ->1(done),3(vis),2(done)

it will c=visit its all unvisited neighbour one by one 
agar usene sare neighbour explore kar liye it will back from ut has been call 
*/
#include<bits/stdc++.h>
using namespace std;
void DFSTraversal(int node, vector<int> AdjList[], vector<bool>& visited, vector<int>& ans) {
    visited[node] = 1; // Mark the current node as visited
    ans.push_back(node); // Add the current node to the result
    for (int j = 0; j < AdjList[node].size(); j++) {
        int neighbour = AdjList[node][j]; // Get the adjacent node
        if (!visited[neighbour]) { // If the node is not visited
            DFSTraversal(neighbour, AdjList, visited, ans); // Recursively visit it
        }
    }
}
int main() {
    int n = 8; // Total number of nodes (0 to 7)
    vector<int> AdjList[n];
    AdjList[0] = {1, 3, 2};
    AdjList[1] = {0, 7, 4};
    AdjList[2] = {0, 5};
    AdjList[3] = {0};
    AdjList[4] = {1, 5};
    AdjList[5] = {4, 6, 2};
    AdjList[6] = {5};
    AdjList[7] = {1};
    vector<bool> visited(n, false);
    vector<int> ans;
    DFSTraversal(0, AdjList, visited, ans);
    cout << "DFS Traversal: ";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
/*
tc=sc=O(V+E)
*/
 