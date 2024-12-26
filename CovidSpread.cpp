/*
1 2 1 1 0 1        0->empty  
1 1 0 1 1 2        1->patient
0 1 0 2 1 1        2->covid patient, covid spread to its all neighbour(l,r,u,d) in 1 unit 
1 1 0 1 0 1
1 0 1 2 0 1
how much time to spread covid to all,if not return-1
ans=5
bfs
2 makes 1 to 2 when covid spread
covid person(i,j) comes in queue pop that person and check all it neighbour 
if queue empty then check matrix if 1 left in it then -1; 
  0  1  2  3  4
0 2  1  0  2  1
1 1  0  1  2  1
2 1  0  0  2  1
q->indicate which person has covid
q=[(0,0),(0,3),(1,3),(2,3)]

pop=(0,0)-> effect (0,1),(1,0)  timer=1
  0  1  2  3  4
0 2  2  0  2  1
1 2  0  1  2  1
2 1  0  0  2  1
q=[(0,3),(1,3),(2,3)]  q1=[(0,1),(1,0)]

pop=(0,3)-> effect (0,4)  timer=1
  0  1  2  3  4
0 2  2  0  2  2
1 2  0  1  2  1
2 1  0  0  2  1
q=[(1,3),(2,3)]   q1=[(0,1),(1,0),(0,4)]

pop=(1,3)-> effect (1,2),(1,4)  timer=1
  0  1  2  3  4
0 2  2  0  2  2
1 2  0  2  2  2
2 1  0  0  2  1
q=[(2,3)]   q1=[(0,1),(1,0),(0,4),(1,2),(1,4)]

pop=(2,3)-> effect (2,4)  timer=1
  0  1  2  3  4
0 2  2  0  2  2
1 2  0  2  2  2
2 1  0  0  2  2
q=[]   q1=[(0,1),(1,0),(0,4),(1,2),(1,4),(2,4)]
now push all q1 to q and now timer=2
q=[(0,1),(1,0),(0,4),(1,2),(1,4),(2,4)]  q1=[]  

pop=(0,1)-> no effect   timer=2 
q=[(1,0),(0,4),(1,2),(1,4),(2,4)]  q1=[]  

pop=(1,0)-> effect 2,1  timer=2 
  0  1  2  3  4
0 2  2  0  2  2
1 2  0  2  2  2
2 2  0  0  2  2
q=[(0,4),(1,2),(1,4),(2,4)]  q1=[(2,1)] 

pop=(0,4)-> no effect  timer=2 
q=[(1,2),(1,4),(2,4)]  q1=[(2,1)] 

pop=(1,2)-> no effect  timer=2 
q=[(1,4),(2,4)]  q1=[(2,1)] 

pop=(1,4)-> no effect  timer=2 
q=[(2,4)]  q1=[(2,1)] 

pop=(2,4)-> no effect  timer=2 
q=[]  q1=[(2,1)] 
now push all q1 to q and now timer=3
q=[(2,1)]  q1=[] 

pop=(2,1)-> no effect  timer=3 
q=[]  q1=[]

if bothe the q is empty then check whole array is 1 is it in if yes the return -1
other wiase timer=3-1=2 (-1 because last one not spread the corona)
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<int>>hospital={{2,1,0,2,1},{1,0,1,2,1},{1,0,0,2,1}};
    int r=hospital.size();
    int c=hospital[0].size();
    queue<pair<int,int>>q;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(hospital[i][j]==2){
                q.push({i, j});
            }
        }
    }
    int timer=0;
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // up, down, left, right
    while(!q.empty()){
        timer ++;
        int curr_patient=q.size();
        while (curr_patient--){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for (auto dir : directions) {
                int ni = i + dir[0];
                int nj = j + dir[1];

                // Check boundaries and if the cell is not yet infected (value 1)
                if (ni >= 0 && ni < r && nj >= 0 && nj < c && hospital[ni][nj] == 1) {
                    hospital[ni][nj] = 2; // Infect the patient
                    q.push({ni, nj});
                }
            }
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(hospital[i][j]==1){
                cout<<"Not Possible To Spread All Patient";
                return 0;
            }
        }
    }
    cout<<"Time taken To Spread Covid:"<<timer-1;
    return 0;
}