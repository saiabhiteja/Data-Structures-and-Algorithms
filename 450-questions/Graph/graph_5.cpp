#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9
#define vec vector<int>
#define pp pair<int,int>
/*
    ----cycle in undirected graph
*/
bool is_cycle_bfs(vec adj[],int n){
    vec vis(n+1,0) ;
    for(int i = 1;i<=n;i++){
        if(!vis[i]){
            queue<pp> q ;
            q.push({i,-1}) ;
            vis[i] = 1 ;

            while(q.size()!=0){
                auto t = q.front() ;
                q.pop() ;
                int node = t.first ;
                int prev = t.second ;

                for(auto it : adj[node]){
                    if(!vis[it]){
                        vis[it] = 1 ;
                        q.push({it,node}) ;
                    }
                    else if (it != prev){
                        return true ;
                    }
                }
            }
        }
    }

    return false ;
    /*
    Time : O(V+E)
    Space : O(V) + O(V)
    */

}
//using depth first search
bool dfs_helper(int node,int prev,vec adj[],vec& vis){
    vis[node] = 1 ;
    for(auto it : adj[node]){
        if(!vis[it]){
            return dfs_helper(it,node,adj,vis) ;
        }
        else if(it != prev){
            return true ;
        }
    }
    return false ;
}
bool is_cycle_dfs(vec adj[],int n){
    vec vis(n+1,0) ;
    for(int i = 1;i<=n;i++){
        if(!vis[i]){
            if(dfs_helper(i,-1,adj,vis)){
                return true ;
            }
        }
    }
    return false ;
    /*
    Time : O(V+E)
    Space : O(V) + O(V)
    */
}
int main() {
/**/
vector<int> adjancy_list[15];
    adjancy_list[1] = {2};
    adjancy_list[2] = {1,4};
    adjancy_list[3] = {5};
    adjancy_list[4] = {2};
    adjancy_list[5] = {3,6,10};
    adjancy_list[6] = {5,7};
    adjancy_list[7] = {6,8};
    adjancy_list[8] = {7,9,11};
    adjancy_list[9] = {8,10};
    adjancy_list[10] = {5,9};
    adjancy_list[11] = {8};

    for(int i = 1;i<=11;i++){
        cout<<i<<"-->" ;
        for(auto it:adjancy_list[i]){
            cout<<it<<"-";
        }
        cout<< "NULL" << endl;
    }

    //cycle 
    if(is_cycle_dfs(adjancy_list,11)){
        cout<<"graph contains cycle"<<endl ;
    }
    else{
        cout<<"graph doesnot contains cycle"<<endl;
    }
return 0;
}