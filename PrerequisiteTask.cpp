/*
Prerequisite Tasks or course schedule(gfg)
N=4(no of task) P=3, Pre={{1,0},{2,1},{3,2}} ={u,v} 'u' task complete before 'v' task. will we complete all task
sol
0->1
1->2
2->3
o/p=0 1 2 3= N=4
something like topological sort. if we draw a diagram of above then it never create circle, if circle present then all task is not completed 
we can applay cycle detection algo
bfs
dfs (khans algo)
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
int n=4;
int p=3;
vector<pair<int,int>>pre={{1,0},{2,1},{3,2}};
vector<int>AdjList[n];
vector<int>InDeg(n,0);
for(int i=0;i<p;i++){
    AdjList[pre[i].second].push_back(pre[i].first);
    InDeg[pre[i].first]++;
}
//khans algo
queue<int>q;
vector<int>ans;
for(int i=0;i<n;i++){
    if(!InDeg[i]) q.push(i);
}
while(!q.empty()){
    int node=q.front();
    q.pop();
    ans.push_back(node);
    for(auto neighbour:AdjList[node]){
        InDeg[neighbour]--;
        if(!InDeg[neighbour]) q.push(neighbour);
    }
}
for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
}

if(ans.size()==n) cout<<"Yes";
else cout<<"No";
return 0;
}