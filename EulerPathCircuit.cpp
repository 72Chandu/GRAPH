/*
Euler path
It is path in graph that visit every edge exactly once 
every graph cant have eular path
0 or 2 vertex node have odd degree and remaining have even degree (all non-zero degree node should connected)

Euler circuit 
It is path in graph that visit every edge exactly once having same initial and final point
if degree of each vertex is even and all edges should be the part of single component then euler circuit is present

the node which have degree and not visited then there is no euler circuit
if EC present then EP also present vice versa is may or may not possible
*/
#include<bits/stdc++.h>
using namespace std;
void DFS(int node, vector<int>AdjList[],vector<bool>&visited){
    visited[node]=1;
    for(auto neighbour:AdjList[node]){
        if(!visited[neighbour]) DFS(neighbour,AdjList,visited);
    }
}
int main(){
    int v=2;
    vector<int>AdjList[]={{1,2},{0,2},{1,0}};
    vector<int>Deg(v,0);
    int odd_deg=0;
    for(int i=0;i<v;i++){
        Deg[i]=AdjList[i].size();
        if(Deg[i]%2!=0) odd_deg++;
    }
    if(odd_deg!=2 && odd_deg!=0){
        cout<<-1<<endl;
        return 0;
    }
    vector<bool>visited(v,0);
    for(int i=0;i<v;i++){
        if(Deg[i]){
            DFS(i,AdjList,visited);
            break;
        }
    }
    for(int i=0;i<v;i++){
        if(Deg[i] && !visited[i]){
            cout<<0<<endl;
            return 0;
        }
    }
    if(odd_deg==0) cout<<"Euler circuit";
    else cout<<"Euler path";

    return 0;
}//tc=O(v+e) sc=O(v)