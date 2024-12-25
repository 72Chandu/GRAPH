/*
Representation of graph
2. Adjacency list

A.undirected-unweight graph
vertex={0,1,2,3,4}-> 5
edge:{{0,1},{1,2},{0,2},{2,4},{3,4},{1,3}} edge{u,v}->u->v,v->u

0  ->{1,2}    AdjList[0].push_back(1),AdjList[0].push_back(2)
1  ->{0,3,2} [1 se 0,3,2 edge ja rahi hai]
2  ->[0,1,4]
3  ->{1,4}
4  ->{2,3}
array ->vector |  vector<int>AdjList[5]
AdjList[0].push_back(1)
AdjList[1].push_back(0)
for acessing
AdjList[0][1]=2
AdjList[1][2]=2
the above list represt the above graph

B.undirected-weight graph
vertex={0,1,2,3,4}-> 5
edge:{{0,1,3},{1,2,2},{0,2,4},{2,4,6},{3,4,7},{1,3,2}} edge{u,v,w}->u->v,v->u
 
0   ->{[1,3],[2,4]}      [vertex,weight]
1   ->{[0,3],[2,2],[3,2]}
2   ->{[1,2],[0,4],[4,6]}
3   ->{[4,7],[1,2]}
4   ->{[2,6],[3,7]}
Time=O(V+2E)=O(VE) E->V, O(V^2)->worst case when complete graph
space=O(V+E)

the above list represt the above graph

C.directed-unweight graph
vertex={0,1,2,3,4}-> 5
edge:{{0,1},{1,2},{0,2},{2,4},{3,4},{1,3}} edge{u,v}->u->v

0  ->1->2    AdjList[0].push_back(1),AdjList[0].push_back(2)
1  ->3->2 [1 se 0,3,2 edge ja rahi hai]
2  ->4
3  ->4
4  
B.directed-weight graph
vertex={0,1,2,3,4}-> 5
edge:{{0,1,3},{1,2,2},{0,2,4},{2,4,6},{3,4,7},{1,3,2}} edge{u,v,w}->u->v
  
0  ->{[1,3],[2,4]}
1  ->{[2,2],[3,2]}
2  ->{[4,6]}
3  ->{[4,7]}
4 
the above list represt the above graph
*/
#include<bits/stdc++.h>
using namespace std;
void undirectedUnweighted(int vertex, int edges){
   vector<int>AdjList[vertex];
   int u,v;
   for(int i=0;i<edges;i++){
    cin>>u>>v;
    AdjList[u].push_back(v);//u->v edge
    AdjList[v].push_back(u);//v->u edge
   }
   for(int i=0;i<vertex;i++){
    cout<<i<<"->";
    for(int j=0;j<AdjList[i].size();j++){
        cout<<AdjList[i][j]<<",";
    }
    cout<<endl;
   }
}
/*
5 6
0 1
1 2
0 2
2 4
3 4
1 3
0->1,2,
1->0,2,3,
2->1,0,4,
3->4,1,
4->2,3,
*/
void undirectedWeighted(int vertex, int edges){
   vector<pair<int,int>>AdjList[vertex];
   int u,v,weight;
   for(int i=0;i<edges;i++){
    cin>>u>>v>>weight;
    AdjList[u].push_back(make_pair(v,weight));//u->v ,w edge
    AdjList[v].push_back(make_pair(u,weight));//v->u , w edge
   }
   for(int i=0;i<vertex;i++){
    cout<<i<<"->";
    for(int j=0;j<AdjList[i].size();j++){
        cout<<"{"<<AdjList[i][j].first<<","<<AdjList[i][j].second<<"}";
    }
    cout<<endl;
   }
}
/*
5 6
0 1 3
1 2 2
0 2 4
2 4 6
3 4 7
1 3 2
0->{1,3}{2,4}
1->{0,3}{2,2}{3,2}
2->{1,2}{0,4}{4,6}
3->{4,7}{1,2}
4->{2,6}{3,7}
*/
void directedUnweighted(int vertex, int edges){
   vector<int>AdjList[vertex];
   int u,v;
   for(int i=0;i<edges;i++){
    cin>>u>>v;
    AdjList[u].push_back(v);//u->v edge
   }
   for(int i=0;i<vertex;i++){
    cout<<i<<"->";
    for(int j=0;j<AdjList[i].size();j++){
        cout<<AdjList[i][j]<<",";
    }
    cout<<endl;
   }
}
/*
5 6
0 1
1 2
0 2
2 4
3 4
1 3
0->1,2,
1->2,3,
2->4,
3->4,
4->
*/
void directedWeighted(int vertex, int edges){
   vector<pair<int,int>>AdjList[vertex];
   int u,v,weight;
   for(int i=0;i<edges;i++){
    cin>>u>>v>>weight;
    AdjList[u].push_back(make_pair(v,weight));//u->v ,w edge
   }
   for(int i=0;i<vertex;i++){
    cout<<i<<"->";
    for(int j=0;j<AdjList[i].size();j++){
        cout<<"{"<<AdjList[i][j].first<<","<<AdjList[i][j].second<<"}";
    }
    cout<<endl;
   }
}
/* 
5 6
0 1 3
1 2 2
0 2 4
2 4 6
3 4 7
1 3 2
0->{1,3}{2,4}
1->{2,2}{3,2}
2->{4,6}
3->{4,7}
4->
*/
int main(){
    int vertex, edges;
    cin>>vertex>>edges;
    //undirectedUnweighted(vertex,edges);
    //directedUnweighted(vertex,edges);
    //undirectedWeighted(vertex,edges);
    directedWeighted(vertex,edges);
}

/*
parameter  Adj matrix  Adj List

add edge     O(1)        O(1)
remove edge  O(1)        O(V)
edge exist   O(1)        O(V)
spce comp    O(v^2)      O(v+E)->worst case O(v^2)
use         dense graph  sparse graph(no of edge less)

we prefer Adj list more 
*/