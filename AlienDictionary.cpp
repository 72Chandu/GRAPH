/*
k=4 (4 charcter is used)
dict=
baa
abcd
abca
cab
cad
order of charcter?

sol
human dict
abca ->last 'a' comes befor 'd' of abcd so 'abca' come first
abcd
baa
cab
cad
order=abcd
----
baa
abcd
abca
cab
cad

observation
b->a (baa,abcd)
d->a (abcd,abca)
a->c (abca,cab)
b->d (cab,cad)
now draw a graph we found there is no cycle so, it is something like topological sort
o/p=b d a c
for easy 
a-0
b-1
c-2
d-3
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    string dict[]={"baa","abcd","abca","cab","cad"};
    int n=5;
    int k=4;
    /*
    cde
    cdef
    */
    vector<int>AdjList[k];
    vector<int>InDeg(n,0);
    for(int i=0;i<n-1;i++){
        string s1=dict[i], s2=dict[i+1];
        int p=0,q=0;
        while(p<s1.size() && q<s2.size()&&s1[p]==s2[q]){
            p++ , q++;
        }
        if(p==s1.size()) continue;
        AdjList[s1[p]-'a'].push_back(s2[q]-'a');//p->q
        InDeg[s2[q]-'a']++;
    }
    //khans algo
    queue<int>q;
    vector<char>ans;
    for(int i=0;i<k;i++){
        if(!InDeg[i]) q.push(i);
    }
    while(!q.empty()){
        int node=q.front();
        q.pop();
        char c='a'+ node;
        ans.push_back(c);
        for(auto neighbour:AdjList[node]){
            InDeg[neighbour]--;
            if(!InDeg[neighbour]) q.push(neighbour);
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}