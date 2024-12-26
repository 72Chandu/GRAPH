/*
it is graph in which the vertices can be divided into two disjoint set
such that no 2 vertices within the same set are adjacent . in other words
it is a graph in which every edge connect a vertex of one set of vertex to other set

2-coloring-algo (red=0,blue=1) : adjacent vertex should have diffrent colure
0 1 0 1 0 1
0-1-2-3-4-5
set1=red=[0,2,4], set2=blue=[1,3,5]
->if we are not able to give colure to any vertex then it is not a biparte graph
->even lenght cycle -biparte graph odd- no

bfs
->queue se jo elemet ko pop karege uske neighboure ko opposite colure allocate karege w.r.t that element
->queue me jo ele jayega usi ko colure milega
0->1
1->0,3,2
2->1
3->1,4,5,8
4->3
5->3,6
6->5,7
7->6,8
8->3,7

q=[] color=[-1,-1,-1,-1,-1,-1,-1,-1,-1]
q=[0] color=[0,-1,-1,-1,-1,-1,-1,-1,-1]

pop=0, neighbour of 0= 1
q=[1] color=[0,1,-1,-1,-1,-1,-1,-1,-1]

pop=1,neighbour of 1= 0,3,2
q=[3] color=[0,1,-1,0,-1,-1,-1,-1,-1]
q=[3,2] color=[0,1,0,0,-1,-1,-1,-1,-1] 0 ka colure sahi hai

pop=3,neighbour of 3= 1,4,5,8 . 1 has right coured
q=[2,4] color=[0,1,0,0,1,-1,-1,-1,-1]
q=[2,4,5] color=[0,1,0,0,1,1,-1,-1,-1]
q=[2,4,5,8] color=[0,1,0,0,1,1,-1,-1,1]

pop=2,neighbour of 2= 1 allredy have right colured
q=[4,5,8] color=[0,1,0,0,1,1,-1,-1,1]

pop=4,neighbour of 4= 3 allredy have right colured
q=[5,8] color=[0,1,0,0,1,1,-1,-1,1]

pop=5,neighbour of 5= 6,3  3 has corect
q=[8,6] color=[0,1,0,0,1,1,0,-1,1]

pop=8,neighbour of 8= 3,7  3 has corect
q=[6,7] color=[0,1,0,0,1,1,0,0,1]

pop=6,neighbour of 6= 5,7  5 has correct, but 7 has same colur as 6 which is wrong , hence it is not a bipartite graph
q=[6,7] color=[0,1,0,0,1,1,0,0,1]

1.it will look at its all neighboure
 ->if colur is not assigned then assign a colure to them (opposit of it)and push the neighbour into queue
 ->else (colure is assigned ) if neighbour colur is same as present node we declare it as not a biparite graph

dfs


*/
#include <bits/stdc++.h>
using namespace std;

bool dfsBipartiteGraph(int node, vector<int>AdjList[], vector<int>&color){
    for(auto neighbour:AdjList[node]){
        if(color[neighbour]==-1){
            color[neighbour]=(color[node]+1)%2;
            if(!dfsBipartiteGraph(neighbour,AdjList,color)) return 0;
        }else{
            if(color[node]==color[neighbour]) return 0;
        }
    }
    return 1;
}
int main(){
    int v = 9;
    vector<int> AdjList[v];

    // AdjList[0] = {1};
    // AdjList[1] = {0,3,2};
    // AdjList[2] = {1};
    // AdjList[3] = {1,4,5,8};
    // AdjList[4] = {3};
    // AdjList[5] = {3, 6};
    // AdjList[6] = {5, 7};
    // AdjList[7] = {6, 8};
    // AdjList[8] = {3, 7};

    AdjList[0] = {1, 3};
    AdjList[1] = {0, 2};
    AdjList[2] = {1, 5};
    AdjList[3] = {0, 4};
    AdjList[4] = {3, 5};
    AdjList[5] = {2, 4};
    vector<int> color(v, -1);
    queue<int> q;
    bool isBipartite = true;
    for (int i = 0; i < v; i++){ // if graph is disconnected so
        if (color[i] == -1){
            q.push(i);
            color[i] = 0;
            while (!q.empty()){
                int node = q.front();
                q.pop();
                for (auto neighbour : AdjList[node]){
                    if (color[neighbour] == -1){
                        color[neighbour] = color[node] + 1; // assigneing the color
                        q.push(neighbour);
                    }
                    else{
                        if (color[node] == color[neighbour]){ // neighboure has same color->not bipartite
                            isBipartite = false;
                            break;
                        }
                    }
                }
                if (!isBipartite) break;
            }
        }
        if (!isBipartite)break;
    }
    if (isBipartite)cout << "The graph is bipartite (BFS)." << endl; 
    else cout << "The graph is not bipartite (BFS)." << endl; 

    //m-2

    // Reset color array for DFS method
    fill(color.begin(), color.end(), -1); 

    // DFS Method
    isBipartite = true; 
    for (int i = 0; i < v; i++) {
        if (color[i] == -1) { 
            color[i] = 0; 
            if (!dfsBipartiteGraph(i, AdjList, color)) {
                isBipartite = false; 
                break; 
            }
        }
    }

    if (isBipartite) cout << "The graph is bipartite (DFS)." << endl; 
    else cout << "The graph is not bipartite (DFS)." << endl; 
    return 0;
}//tc=O(v+e) sc=O(v)