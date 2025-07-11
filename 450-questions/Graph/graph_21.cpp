#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*

    Belman ford algorithm
    Finding shortest paths from src to all vertexes when  we have negative weighted edges

*/
vector<int> bellman_ford(vector<vector<int>> edges,int n){
    vector<int> dis(n,INT_MAX) ;
    //we have to n-1 reflexes 
    dis[0] = 0 ; //src
    for(int i = 1;i<n;i++){
        for(int i = 0;i<edges.size();i++){
            int u = edges[i][0] ;
            int v = edges[i][1] ;
            int w = edges[i][2] ;
            if(dis[u] == INT_MAX){
                continue ;
            }
            if(dis[u]+w < dis[v]){
                dis[v] = dis[u] +w ;
            }
        }
    }
    //for finding negative cycle
   /* for(auto it: edges){
        int u = it[0] ;
        int v = it[1] ;
        int w = it[2] ;
        if(dis[u]+w<dis[v]){
            return true;
        }
    }*/
    return dis;
    /*
    Time ; O(N^2)
    Space : O(1)
    */
}

int main() {
        vector<vector<int>> edges = {{0,1,-1},{1,2,-2},
    {0,2,-3}} ;
    vector<int> dis = bellman_ford(edges,3);
    for(int i: dis){
        cout<<i<<" ";
    }

    return 0;
}