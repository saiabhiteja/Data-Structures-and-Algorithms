#include <iostream>
#include "bits/stdc++.h"
using namespace std ;
#define p pair<int,int>
#define vec vector<pair<int,int>>
#define v vector<int> 
#define min_pq priority_queue <p, vector<p>, greater<p> > 
/*
----------SHORTEST PATH IN UNDIRECTED WEIGHTED GRAPH------
---------DIJKSTRA'S ALGORITHM --------
COMPLEXITES:
TIME: O(Elogv)
SPACE:O(V)

*/
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
      priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq ;
        pq.push({0,S});
        vector<int> dis(V,INT_MAX);
        dis[S] = 0;
        while(pq.size()!= 0){
            auto node = pq.top();
            pq.pop();
            for(auto it:adj[node.second]){
                if(dis[node.second]+it[1]<dis[it[0]]){
                    dis[it[0]] = dis[node.second]+it[1];
                    pq.push({dis[it[0]],it[0]});
                }
            }
            
        }
        return dis;
    }
int main(){
    vector<vector<int>> adj[10] ;
    adj[0] = {{1,1},{2,6}} ;
    adj[1] = {{0,1},{2,3}} ;
    adj[2] = {{0,6},{1,3}} ;
    v ans = dijkstra(3,adj,2) ;
    for(auto it : ans){
        cout<<it<<" ";
    }
    return 0 ;
}
