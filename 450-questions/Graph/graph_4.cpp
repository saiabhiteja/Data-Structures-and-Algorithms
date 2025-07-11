#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9
#define vec vector<int>
#define pp pair<int,int>
/*
    ----cycle in Directed graph-----

*/
bool iscycle_bfs(vec adj[],int n){
    /*
            using Khans algo
    topo sort is used for DAG if we get cnt equal to all nodes
    then it there is no cycle in it

    */ 
    vec indegree(n+1,0) ;
    for(int i = 1;i<=n;i++){
        for(auto it : adj[i]){
            indegree[i]++;
        }
    }
    int cnt = 0;
    queue<int> q ;
    for(int i = 1;i<=n;i++){
        if(indegree[i] == 0){
            q.push(i) ;
        }
    }

    while(q.size()!=0){
        int node = q.front();
        q.pop();
        cnt++;
        for(auto it: adj[node]){
            indegree[it]--;
            if(indegree[it] == 0){
                q.push(it) ;
            }
        }
    }

    return !(cnt == n);
    /*
    Time : O(V) + O(V+E) 
    Space : O(v) (queue + indegree)
    */

}
bool dfs_helper(int node,vec& vis,vec adj[],vec& dfs_vis){
        vis[node] = 1 ;
        dfs_vis[node] = 1 ;
        for(auto it : adj[node]){
            if(!vis[it]){
                return dfs_helper(it,vis,adj,dfs_vis) ;
            }
            else if(dfs_vis[it]){
                return true ;
            }
        }
        dfs_vis[node] = 0;
        return false;
}
bool iscycle_dfs(vec adj[],int n){
    vec vis(n+1,0),dfs_vis(n+1,0) ;
    for(int i = 1;i<=n;i++){
        if(!vis[i]){
            if(dfs_helper(i,vis,adj,dfs_vis)){
                return true ;
            }
        }
    }
    return false;
    /*
    Time : O(V+E) 
    Space : O(V) (visted,dfs_visited)
    */
}
int main() {
/**/
vector<int> adjancy_list[10];
    adjancy_list[1] = {2};
    adjancy_list[2] = {3};
    adjancy_list[3] = {4,6};
    adjancy_list[4] = {5};
    adjancy_list[5] = {};
    adjancy_list[6] = {5} ;
    adjancy_list[7] = {2,8};
    adjancy_list[8] = {9} ;
    adjancy_list[9] = {7} ;

    //check
    if(iscycle_dfs(adjancy_list,9)){
        cout<<"graph is cyclic"<<endl ;
    }
    else{
        cout<<"graph is not cyclic"<<endl ;
    }

return 0;
}