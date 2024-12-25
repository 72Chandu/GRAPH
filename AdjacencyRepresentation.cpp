/*
Representation of graph

1. Adjacency matrix

A.undirected-unweight graph
vertex={0,1,2,3,4}-> 5
edge:{{0,1},{1,2},{0,2},{2,4},{3,4},{1,3}} edge{u,v}->u->v,v->u

0-> no edge,  1-> edge present
  0  1  2  3  4  
0 0  1  1  0  0   
1 1  0  1  1  0
2 1  1  0  0  1
3 0  1  0  0  1
4 0  0  1  1  0
the above 2d array represt the above graph

B.undirected-weight graph
vertex={0,1,2,3,4}-> 5
edge:{{0,1,3},{1,2,2},{0,2,4},{2,4,6},{3,4,7},{1,3,2}} edge{u,v,w}->u->v,v->u

  0  1  2  3  4  
0 0  3  4  0  0   
1 3  0  5  2  0
2 4  5  0  0  6
3 0  2  0  0  7
4 0  0  6  7  0
the above 2d array represt the above graph

C.directed-unweight graph
vertex={0,1,2,3,4}-> 5
edge:{{0,1},{1,2},{0,2},{2,4},{3,1},{4,3}} edge{u,v}->u->v edge hai

  0  1  2  3  4  
0 0  1  1  0  0   
1 0  0  1  0  0
2 0  0  0  0  1
3 0  1  0  0  0
4 0  0  0  1  0
the above 2d array represt the above graph

B.directed-weight graph
vertex={0,1,2,3,4}-> 5
edge:{{0,1,3},{1,2,2},{0,2,4},{2,4,6},{3,4,7},{1,3,2}} edge{u,v,w}->u->v

  0  1  2  3  4  
0 0  3  4  0  0   
1 0  0  5  2  0
2 0  0  0  0  6
3 0  0  0  0  7
4 0  0  0  0  0
the above 2d array represt the above graph
*/

#include<iostream>
#include<vector>
using namespace std;
void undirectedUnweighted(int vertex, int edges){
   vector<vector<bool>>adjMat(vertex,vector<bool>(vertex,0));
   int u,v;
   for(int i=0;i<edges;i++){
    cin>>u>>v; // e1= u-v
    adjMat[u][v]=1; //u->v
    adjMat[v][u]=1; //v->u
   }
   for(int i=0;i<vertex;i++){
    for(int j=0;j<vertex;j++){
        cout<<adjMat[i][j]<<" ";
    }
    cout<<endl;
   }
}/*
5 6
0 1
1 2
0 2
2 4
3 4
1 3
0 1 1 0 0 
1 0 1 1 0 
1 1 0 0 1 
0 1 0 0 1 
0 0 1 1 0 
*/
void undirectedWeighted(int vertex, int edges){
   vector<vector<int>>adjMat(vertex,vector<int>(vertex,0));
   int u,v,weight;
   for(int i=0;i<edges;i++){
    cin>>u>>v>>weight; // e1= u-v w
    adjMat[u][v]=weight; //u->v
    adjMat[v][u]=weight; //v->u
   }
   for(int i=0;i<vertex;i++){
    for(int j=0;j<vertex;j++){
        cout<<adjMat[i][j]<<" ";
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
0 3 4 0 0 
3 0 2 2 0 
4 2 0 0 6
0 2 0 0 7
0 0 6 7 0
*/
void directedUnweighted(int vertex, int edges){
   vector<vector<bool>>adjMat(vertex,vector<bool>(vertex,0));
   int u,v;
   for(int i=0;i<edges;i++){
    cin>>u>>v; // e1= u-v 
    adjMat[u][v]=1; //u->v edge hai
   }
   for(int i=0;i<vertex;i++){
    for(int j=0;j<vertex;j++){
        cout<<adjMat[i][j]<<" ";
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
3 1
4 3
0 1 1 0 0 
0 0 1 0 0 
0 0 0 0 1 
0 1 0 0 0 
0 0 0 1 0
*/
void directedWeighted(int vertex, int edges){
   vector<vector<int>>adjMat(vertex,vector<int>(vertex,0));
   int u,v,weight;
   for(int i=0;i<edges;i++){
    cin>>u>>v>>weight; // e1= u-v ,w
    adjMat[u][v]=weight; //u->v edge hai
   }
   for(int i=0;i<vertex;i++){
    for(int j=0;j<vertex;j++){
        cout<<adjMat[i][j]<<" ";
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
0 3 4 0 0 
0 0 2 2 0
0 0 0 0 6
0 0 0 0 7
0 0 0 0 0
*/
int main(){
   int vertex, edges;
   cin>>vertex>>edges;
   //undirectedUnweighted(vertex,edges);
   //undirectedWeighted(vertex,edges);
   //directedUnweighted(vertex,edges);
   directedWeighted(vertex,edges);
   return 0;
}
/*
time complexity=O(v^2);
space complexity=O(v^2);
*/