#include <iostream>
#include "bits/stdc++.h"
using namespace std;

vector<int> time_complete(int n,vector<int> adj[]){
    vector<int> ans(n+1,0) ;
    vector<int> indegree(n+1,0) ;
    for(int i = 1;i<=n;i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }
    queue<int> q ;
    for(int i = 1;i<=n;i++){
        if(indegree[i] == 0){
            q.push(i);
            ans[i] = 1;
        }
    }
   
    while(q.size()!=0){
       
            int node = q.front();
            q.pop();
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    ans[it] = 1+ans[node];
                    q.push(it);
                }
            }
   
    }
    return ans ;
    /*
    Time : O(V+E)
    Space : O(V)
    */
}

int main(){

    //space complexity : O(V+E)
    vector<int> adjancy_list[11];
    adjancy_list[1] = {3,4,5};
    adjancy_list[2] = {3,8,9};
    adjancy_list[3] = {6};
    adjancy_list[4] = {6,8};
    adjancy_list[5] = {8};
    adjancy_list[6] = {7} ;
    adjancy_list[7] = {8} ;
    adjancy_list[8] = {10} ;
    adjancy_list[9] = {};
    adjancy_list[10] = {};

    for(int i = 1;i<=10;i++){
        cout<<i<<"-->" ;
        for(auto it:adjancy_list[i]){
            cout<<it<<"-";
        }
        cout<< "NULL" << endl;
    }

    vector<int> topo = time_complete(10,adjancy_list);
    for(int i = 1;i<topo.size();i++){
        cout<<topo[i]<<" ";
    }
    return 0;
}