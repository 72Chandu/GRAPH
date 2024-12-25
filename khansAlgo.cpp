/* Topological order 
jiska koi parent nahi hoga o pahele execute hoga 
the vertex which has 0 indegree they will execute first
0->1,2  -> 0 increase the indgree of 1 and 2 by 1
1->3,4
2->
3->4
4->
5->6,4
6->3
indegree=[0,1,1,0,0,0,0]
indegree=[0,1,1,1,1,0,0]
indegree=[0,1,1,1,2,0,0]
indegree=[0,1,1,1,3,0,1]
indegree=[0,1,1,2,3,0,1]
ans=[]    q=[0,5]     indegree=[0,1,1,2,3,0,1]  only push the ele whose indegree is 0 in q

ans=[0]    q=[5]     indegree=[0,0,1,2,3,0,1] when 0 execute it dectrese the indegree of associated vertex by 1
ans=[0]    q=[5,1,2]     indegree=[0,0,0,2,3,0,1]

ans=[0,5]    q=[1,2]     indegree=[0,0,0,2,2,0,0]
ans=[0,5]    q=[1,2,6]     indegree=[0,0,0,2,2,0,0]

ans=[0,5,1]    q=[2,6]     indegree=[0,0,0,1,1,0,0]
ans=[0,5,1,2]    q=[6]     indegree=[0,0,0,1,1,0,0]
ans=[0,5,1,2,6]    q=[]     indegree=[0,0,0,1,1,0,0]
ans=[0,5,1,2,6]    q=[3]     indegree=[0,0,0,0,1,0,0]
ans=[0,5,1,2,6,3]    q=[4]     indegree=[0,0,0,0,0,0,0]
ans=[0,5,1,2,6,3,4]    q=[]     indegree=[0,0,0,0,0,0,0]
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int v = 7; 
    vector<int> AdjList[v];    
    AdjList[0] = {1, 2};
    AdjList[1] = {3, 4};
    AdjList[2] = {};
    AdjList[3] = {4};
    AdjList[4] = {};
    AdjList[5] = {6, 4};
    AdjList[6] = {3};
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
        cout << "The graph contains a cycle. Topological sort not possible.\n";
    } else {
        for (auto i : ans) {
            cout << i << " ";
        }
    }
    return 0;
}