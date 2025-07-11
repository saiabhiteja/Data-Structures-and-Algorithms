#include <iostream>
#include "bits/stdc++.h"
using namespace std;
/*
     Topo sort gives us order of tasks can be done if and only if the graph is Directed acyclic graph
     if not it we cannot complete all tasks given
     so now our problem boils down into finding cycle in a graph
*/
bool dfs_helper(int node,vector<int> adj[],vector<int>&vis,vector<int>&dfs_vis){
        vis[node] = 1;
        dfs_vis[node] = 1 ;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs_helper(it,adj,vis,dfs_vis)){
                    return true;
                }
            }
            else if(dfs_vis[it]){
                return true;
            }
        }
        dfs_vis[node] = 0 ;
        return false;
    }

bool isPossible(int N, vector<pair<int, int> >& pre) {
	    // Code here
	    vector<int> adj[N];
	    for(int i = 0;i<pre.size();i++){
	        adj[pre[i].first].push_back(pre[i].second);
	    }
	    
	    vector<int> vis(N,0);
	    vector<int> dfs_vis(N,0) ;
	    for(int i = 0;i<N;i++){
	        if(!vis[i]){
	            if(dfs_helper(i,adj,vis,dfs_vis)){
	                return false;
	            }
	        }
	    }
	    
	   return true;
       /*
       Time : O(V+E)
       Space : O(V)
       */
	}

/*
DETECING CYCLE IN DIRCETD GRAPH 
-----BFS----
COMPLEXTIES:
TIME : O(V+E)
SPACE:O(N)
*/

vector<int> toposort(vector<int>adj[],int n){
    vector<int> ans ;
    vector<int> indegree(n+1,0) ;
    for(int i = 1;i<=n;i++){
        for(auto it: adj[i]){
            indegree[it]++ ;
        }
    }

    //queue
    queue<int> q ;

    //checking for zero indegree tasks
    for(int i = 1;i<=n;i++){
        if(indegree[i] == 0){
            q.push(i) ;
        }
    }

    while(q.size()!=0){
        int node = q.front();
        q.pop();
        ans.push_back(node) ;
        for(auto it : adj[node]){
            indegree[it]--;
            if(indegree[it] == 0){
                q.push(it) ;
            }
        }
    }


    return ans;
}

bool cyclic(int n,vector<int> adj[]){
    vector<int> ans = toposort(adj,n);
    for(auto it: ans){
        cout<<it<<" ";
    }
    return !(n == ans.size());
}

int main(){

    
    return 0;
}
