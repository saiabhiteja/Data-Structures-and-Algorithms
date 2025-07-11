#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*
    prims algo
*/

vector<int> prims_algo(vector<pair<int,int>> adj[],int n){
    vector<int>parent(n,-1);
    vector<bool> mst(n,false);
    vector<int> dis(n,INT_MAX) ;
    //from zero
    dis[0] = 0;
    for(int i = 0;i<n-1;i++){
        //finding minimum in dis 
        int mi = INT_MAX ;
        int u = -1;
        for(auto it: dis){
            if(!mst[it] && dis[it]<mi){
                mi = dis[it] ;
                u = it ;
            }
        }
        mst[u] = true ;
        for(auto it:adj[u]){
            int v = it.first ;
            int weight = it.second ;
            if(mst[v] == false && weight<dis[v]){
                dis[v] = weight ;
                parent[v] = u ;
            }
        }

    }
    return parent;
    /*
    Time : O(N* N+E)
    Space : O(N)
    */

}

vector<int> prims_algo_2(vector<pair<int,int>> adj[],int n){

    vector<int>parent(n,-1);
    vector<bool> mst(n,false);
    vector<int> dis(n,INT_MAX) ;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq ;
    pq.push({0,0}); //dis,node
    for(int i = 0;i<n-1;i++){
        auto t = pq.top() ;
        pq.pop();
        int u = t.second ;
        mst[u] = true;
        for(auto it: adj[u]){
            int v = it.first ;
            int weght = it.second ;
            if(mst[v] == false &&weght<dis[v] ){
                dis[v] = weght ;
                parent[v] = u;
                pq.push({dis[v],v});
            }
        }
    }
    return parent ;
    /*
    Time : O(Nlogn)
    space : O(N)
    */    
}


int main() {
    
    vector<pp> adj[5] ;
    adj[0] = {{1,1},{2,2},{3,2}} ;
    adj[1] = {{0,1},{2,2},{3,3}} ;
    adj[2] = {{0,2},{1,2}} ;
    adj[3] = {{0,2},{1,3}} ;

    vector<int> ans = prims_algo_2(adj,4);

    for(int i: ans){
        cout<<i<<" ";
    }

    return 0;
}