/*
Circle of String
ex:ab bc cd da   
ab-bc-cd-da-ab -> circle yes
ex:abc cde edg
abc-cde-edg -> no 
last charcter is match with first charcter of next charcter

create a node to all string link then to all another string node with proper way

ex:[ac  ca cd dc]
1.ac-ca further no connection possible (no cycle)
2.ac-cd-dc-ca-ac ->yes cycle

ex:abad dabc cdea akrt trdd deka 

abad->dabc->cdea->akrt->trdd->dcka
 |            |                 |
 dcka        abad               akrt,abad

it is like a hamiltanion cycle present: tc=n!
->no need of middle charcter 
ad dc ca at td da 
 a d   c  a  t  d -> name of above 

name   chale jana
making edge b/w first char and last char of each string
a->d
d->c
c->a
a->t
t->d
d->a
a->d->c->a->t->d->a
check eluerian circuit present or not 

1.create edges b/w first and lst char of string
2.eluerian circuit-> indegre==outdegree
  dfs : all the edges are part of single connected component

a-0  b-1 c-2 d-3  ..
*/
#include<bits/stdc++.h>
using namespace std;
void DFS(int node, vector<int>AdjList[],vector<bool>&visited){
    visited[node]=1;
    for(auto neighbour:AdjList[node]){
        if(!visited[neighbour]){
            DFS(neighbour,AdjList,visited);
        }
    }
}
int main(){
    int n=6;
    vector<string>s={"abad", "dabc", "cdea", "akrt", "trdd", "deka"};
    //create a edge
    vector<int>AdjList[26];
    vector<int>Indeg(26,0);
    vector<int>Outdeg(26,0);
    for(int i=0;i<n;i++){
        string temp=s[i];
        int u=temp[0]-'a';
        int v=temp[temp.size()-1]-'a';
        AdjList[u].push_back(v);
        Outdeg[u]++;
        Indeg[v]++;
    }
    for(int i=0;i<26;i++){
        if(Indeg[i]!=Outdeg[i]){
            cout<<"No Circle";
            return 0;
        }
    }
    vector<bool>visited(26,0);
    int node=s[0][0]-'a';
    DFS(node,AdjList,visited);
    for(int i=0;i<26;i++){
        if(Indeg[i]&&!visited[i]){
            cout<<"No Circle";
            return 0;
        }
    }
    cout<<"Circle present"<<endl;
    return 0;
}