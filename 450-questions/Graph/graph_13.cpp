#include <iostream>
#include "bits/stdc++.h"
using namespace std;
/*
TOPOLOGICAL SORTING:
DIRECTED ACYCLIC GRAPH
khans algorithm
LINEAR ORDERING OF VERTICES SUCH THAT FOR EDGE U->V : VERTEX U COMES BEFORE V
-----BFS----
COMPLEXITIES:
TIME : O(V+E) + O(V) + O(V+E)
SPACE : O(V+E)+O(V)+O(V+E) (ADJANCYLIST,INDEGREE,QUEUE)

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

/*
TOPOLOGICAL SORTING:
DIRECTED ACYCLIC GRAPH

LINEAR ORDERING OF VERTICES SUCH THAT FOR EDGE U->V : VERTEX U COMES BEFORE V
-----DFS----
COMPLEXITIES:
TIME : O(v+E) + O(V)
SPACE : O(N) RECURSION STACK + O(V) (TOPO STACK)+O(V)(VISITED) + O(V+E) ADJANCY LIST

*/
void dfs_helper(int node,vector<int> adj[],vector<int>& visited,stack<int>& st){
    visited[node] = 1;
    for(auto it: adj[node]){
        if(!visited[it]){
            dfs_helper(it,adj,visited,st);
        }
    }
    st.push(node) ;

    return ;

}
vector<int> toposort_dfs(vector<int>adj[],int n){
    vector<int> ans ;

    vector<int> visited(n+1,0);
    stack<int> st ;
    for(int i = 1;i<=n;i++){
        if(!visited[i]){
            dfs_helper(i,adj,visited,st) ;
        }
    }

    while(st.size() != 0){
        ans.push_back(st.top());
        st.pop() ;
    }
    

    return ans;
}
int main(){

    //space complexity : O(V+E)
    vector<int> adjancy_list[10];
    adjancy_list[1] = {};
    adjancy_list[2] = {};
    adjancy_list[3] = {4};
    adjancy_list[4] = {2};
    adjancy_list[5] = {1,2};
    adjancy_list[6] = {1,3} ;

    for(int i = 1;i<=6;i++){
        cout<<i<<"-->" ;
        for(auto it:adjancy_list[i]){
            cout<<it<<"-";
        }
        cout<< "NULL" << endl;
    }

    vector<int> topo = toposort(adjancy_list,6);
    cout<<"\nTOPOLOGICAL SORT FOR GIVEN DIRCTED ACYCLIC GRAPH IS: \n";
    for(auto it : topo){
        cout<<it<<" ";
    }
    return 0;
}
