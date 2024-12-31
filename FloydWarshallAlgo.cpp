/*
Floyd Warshall Algorithm 
multi source shortest path algorithms
-> only for directed graph (weight can be negative and positive)
s  d w
a->b,2
a->c,8
b->d,1
b->c,4
d->c,2
warshal:a->b, b->c then a->c

[a->b 2, b->c = 4 a->c,6]
a->b,2
a->c,6
b->d,1
b->c,4
d->c,2
[a->b 2,b->d 1= a->d 3 ]
a->b,2
a->c,6
b->d,1
b->c,4
d->c,2
a->d ,3 new
[a->d 3 d->c 2 = a->c 5]
a->b,2
a->c,5
b->d,1
b->c,4
d->c,2
a->d ,3 
[b->d 1 d->c 2 = b->c 3]
a->b,2
a->c,5
b->d,1
b->c,3
d->c,2
a->d ,3 

similarly we do and we got the answer

select each node as intermidiate node b/w source and destination
  0   1   2   3
0 0  inf  2   4
1 3   0   inf 10
2 inf inf 0    1
3 6   4   inf  0
path(i,j)=min(path(i,j), path(i,k)+path(k,j))

via 0 -> 0th row and col remain same and diagonal alwase 0 beacuse no self loop
  0   1   2   3
0 0  inf  2   4     
1 3   0   5   7   1-0 0-2 =5  1-0 0-3 =7
2 inf inf 0   1   2-0 0-1 =inf,  2-0 0-3 =inf 
3 6   4   8   0  3-0 0-1 =inf, 3-0 0-2=8

via 1 -> 1st row and col remain same and diagonal=0 
  0   1   2   3
0 0  inf  2   4     0-1 1-2=inf,  0-1 1-3=inf 
1 3   0   5   7      
2 inf inf 0   1     2-1 1-0=inf,  2-1 1-3 =inf
3 6   4   8   0     3-1 1-0=7 , 3-1 1-2=9

via 2 -> 2nd row and col remain same and diagonal=0 
  0   1   2   3
0 0  inf  2   3    0-2 2-3=3
1 3   0   5   6   1-2 2-3=6    
2 inf inf 0   1     
3 6   4   8   0
via 3 -> 3rd row and col remain same and diagonal=0 
  0   1   2   3
0 0   7   2   3    0-3 3-1=3
1 3   0   5   6     
2 7   5   0   1     2-3 3-0=7,  2-3 3-1=5
3 6   4   8   0

if we change the order of intermeidate node selection the no change in answer 

will we applay Dijkstra's Algorithm by choosing all node one time soure and destination and find  shortest path
in Dijkstra's in sparse tc=O(v^2logv) in dens=O(v^3) in dense use Floyd Warshall tc=O(v^3)
why not bellmon ford = ve *v =v^2*v^2(worst case)
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<int>>mat={{0,INT_MAX,2,4},{3,0,INT_MAX,10},{INT_MAX,INT_MAX,0,1},{6,4,INT_MAX,0}};
    int n=mat.size();
    for(int k=0;k<n;k++){ //intermidiate node 
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][k]==INT_MAX ||mat[k][j]==INT_MAX) continue;
                mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==INT_MAX) mat[i][j]=-1;
            else cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}