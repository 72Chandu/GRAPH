/*
start with any vertex,  agal bagal wale ko first traverse karo then uske agal bagal wale ko traverse karo ...similarly
adjList
row ->colume , size of colume=AdjList[row].size();
0  ->1,2   AdjList[0][0]=1,AdjList[0][1]=2
1  ->0,5,7
2  ->0,3,4
3  ->2
4  ->2
5  ->1,6
6  ->5,8
7  ->1,8
8  ->6,7
BFS ->queue,  
visited array which make the particular vertex is visited or not

q=[]    v=[0,0,0,0,0,0,0,0,0]  BFS=[]
           0 1 2 3 4 5 6 7 8

q=[0]    v=[1,0,0,0,0,0,0,0,0]  BFS=[]
            0 1 2 3 4 5 6 7 8
pop 0 and push into bfs , neighbour of 0=1,2 
q=[1,2]    v=[1,1,1,0,0,0,0,0,0]  BFS=[0]
              0 1 2 3 4 5 6 7 8

pop 1 and push into bfs.  neighbour of 1=0,5,7  0 is allready visited
q=[2,5,7]    v=[1,1,1,0,0,1,0,1,0]  BFS=[0,1]
                0 1 2 3 4 5 6 7 8

pop 2 and push into bfs.  neighbour of 2=0,3,4  0 is allready visited
q=[5,7,3,4]    v=[1,1,1,1,1,1,0,1,0]  BFS=[0,1,2]
                  0 1 2 3 4 5 6 7 8

pop 5 and push into bfs.  neighbour of 5=1,6  1 is allready visited
q=[7,3,4,6]    v=[1,1,1,1,1,1,1,1,0]  BFS=[0,1,2,5]
                  0 1 2 3 4 5 6 7 8

pop 7 and push into bfs.  neighbour of 7=1,8  1 is allready visited
q=[3,4,6,8]    v=[1,1,1,1,1,1,1,1,1]  BFS=[0,1,2,5,7]
                  0 1 2 3 4 5 6 7 8

pop 3 and push into bfs.  neighbour of 3=2  2 is allready visited
q=[4,6,8]    v=[1,1,1,1,1,1,1,1,1]  BFS=[0,1,2,5,7,3]
                0 1 2 3 4 5 6 7 8

pop 4 and push into bfs.  neighbour of 4=2  2 is allready visited
q=[6,8]    v=[1,1,1,1,1,1,1,1,1]  BFS=[0,1,2,5,7,3,4]
              0 1 2 3 4 5 6 7 8

pop 6 and push into bfs.  neighbour of 6=5,8  5,8 is allready visited
q=[8]    v=[1,1,1,1,1,1,1,1,1]  BFS=[0,1,2,5,7,3,4,6]
            0 1 2 3 4 5 6 7 8

pop 8 and push into bfs.  neighbour of 8=6,7  6,7 is allready visited
q=[]    v=[1,1,1,1,1,1,1,1,1]  BFS=[0,1,2,5,7,3,4,6,8]
           0 1 2 3 4 5 6 7 8

*/
#include <bits/stdc++.h>
using namespace std;
vector<int> BFSTraversal(int v, vector<int> AdjList[]) {
    queue<int> q;
    vector<bool> visited(v, 0);
    q.push(0); // Starting BFS from node 0
    visited[0] = 1;
    vector<int> ans;
    while (!q.empty()) {
        int node = q.front(); // Current node
        q.pop();
        ans.push_back(node);

        // Check all neighbors of the current node
        for (int j = 0; j < AdjList[node].size(); j++) { 
            int neighbour = AdjList[node][j]; // Neighbor
            if (!visited[neighbour]) { 
                q.push(neighbour);
                visited[neighbour] = 1; // Mark as visited
            }
        }
    }
    return ans;
}
int main() {
    int v = 9; 
    vector<int> AdjList[v];

    // Adding edges to the adjacency list
    AdjList[0] = {1, 2};
    AdjList[1] = {0, 5, 7};
    AdjList[2] = {0, 3, 4};
    AdjList[3] = {2};
    AdjList[4] = {2};
    AdjList[5] = {1, 6};
    AdjList[6] = {5, 8};
    AdjList[7] = {1, 8};
    AdjList[8] = {6, 7};
    vector<int> bfsResult = BFSTraversal(v, AdjList);
    cout << "BFS Traversal: ";
    for (int node : bfsResult) {
        cout << node << " ";
    }
    cout << endl;
    return 0;
}

/*
sc=O(v+v) ->queue + visted array
tc=O(v+2E)

either the graph is directed, undirected the traversal will same 
*/