#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9
#define vec vector<int>
#define pp pair<int,int>
/*
    ----- Breadth First Search -----
    Time : O(V+E)
    Space : O(V)
*/
void bfs(vec adj[],int v){
    //breadth first search 
    vec vis(v+1,0) ; //visited array
    for(int i = 1;i<=v;i++){
        if(!vis[i]){

            queue<int> q ;
            q.push(i) ;
            vis[i] = 1 ;

            while(q.size()!=0){
                int node = q.front() ;
                cout<<node<<" ";
                q.pop() ;
                for(auto it : adj[node]){
                    if(!vis[it]){
                        q.push(it) ;
                        vis[it] = 1 ;
                    }
                }
            }

            cout<<endl ; //just for different components
        }
    }

}
int main() {
/**/
//space complexity : O(V+E)
    vector<int> adjancy_list[10];
    adjancy_list[1] = {2,3,4};
    adjancy_list[2] = {1,4};
    adjancy_list[3] = {1,5};
    adjancy_list[4] = {1,2,5};
    adjancy_list[5] = {3,4};
    adjancy_list[6] = {7,8} ;
    adjancy_list[7] = {6} ;
    adjancy_list[8] = {6} ;

    bfs(adjancy_list,8);
return 0;
}