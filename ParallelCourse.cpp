/*
leetcode=2050
Input: n = 4,(courses) relations = [[2,1],[3,1],[1,4]], k = 2
Output: 3
relations[i] = [prevCoursei, nextCoursei], prevCoursei has to be taken before course nextCoursei

ex: 
course  time to complete 
1       1 (month)
2       2
3       3
4       5
5       6
1->5
2->5
4->5
3->4
1(1 month),2(2month),3(3month),4(3+5),5 (max(1,2,8)+6)

ex:
rel=[[1,5],[2,5],[3,5],[3,4],[4,5]]
      0 1 2 3 4
time=[1,2,3,4,5]
1->5  (1 month)
2->5  (2 month)
3->5,4  (3->5 5 month,3->4 3 month )
4->5    (7(3+4) month)
5th complete in max(1,2,3,7)+5=12 month
---approach 
it is something like topological sort

we should maintain the current time arry[] which denotes how much max time to complete prev course 


*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=3;
    vector<vector<int>>relations={{1,3},{2,3}};
    vector<int>time={3,2,5};

    vector<int>AdjList[n];
    for(int i=0;i<relations.size();i++){
        AdjList[relations[i][0]-1].push_back(relations[i][1]-1);//-1 for 0 based indx
    }
    vector<int>Indeg(n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<AdjList[i].size();j++){
            Indeg[AdjList[i][j]]++;
        }
    }
    queue<int>q;
    for(int i=0;i<n;i++){
        if(!Indeg[i]) q.push(i);
    }

    vector<int>CourseTime(n,0);//max time to complete privious course
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto neighbour:AdjList[node]){
            Indeg[neighbour]--;
            if(!Indeg[neighbour]) q.push(neighbour);

            //maximum time to complete prev couse time + present course
            CourseTime[neighbour]=max(CourseTime[neighbour],CourseTime[node]+time[node]);

        }
    }

    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans, CourseTime[i]+time[i]);
    }
    cout<<ans;
}