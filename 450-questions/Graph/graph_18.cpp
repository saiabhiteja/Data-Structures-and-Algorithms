#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*
    kruskal's algo
*/
class disjointset{
    private :
    vector<int> parents,rank ;
    public:
    disjointset(vector<int> ve,vector<int> rk){
        parents = ve ;
        rank = rk ;
    }

    int findparent(int u){
        if(u == parents[u]) 
        return u; 
        return parents[u] = findparent(parents[u]); 
        
    }

    void unionn(int u,int v){
        u = findparent(u) ;
        v = findparent(v) ;
        if(rank[u]<rank[v]){
            parents[u] = v ;
        }
        else if(rank[v]<rank[u]){
            parents[v] = u;
        }
        else{
            //rank[u] == rank[v]
            parents[v] = u;
            rank[u]++;
        }
        
        /*
        Time : O(alpha(n)) where alpha is the inverse Ackermann function,
        */
        

    }

};

bool cmp(vector<int> v1,vector<int> v2){
    return v1[0]<v2[0] ;
}
vector<pp> kruskals_algo(vector<vector<int>> edges,int n){
    //sorting edges according to weights
    sort(edges.begin(),edges.end()) ;
    //declaring useful vectors
    vector<int> parent(n,0),rank(n,0) ;

    for(int i = 0;i<n;i++){
        parent[i] = i ;
    }
    //disjoint set 
    disjointset d(parent,rank) ;

    vector<pp> ans ;
    for(auto it: edges){
        int w = it[0] ;
        int u = it[1];
        int v = it[2] ;
        if(d.findparent(u)!=d.findparent(v)){
            ans.push_back({u,v}) ;
            d.unionn(u,v) ;
        }
    }
    return ans ;
    /*
    Time : O(N*logN) + O(N)
    Space : O(N)
    */

}
int main() {
    vector<vector<int>> edges ;
    edges.push_back({1,0,1}) ;
    edges.push_back({3,1,3}) ;
    edges.push_back({4,3,2}) ;
    edges.push_back({2,0,2}) ;
    edges.push_back({2,0,3}) ;
    edges.push_back({2,1,2}) ;
    vector<pp> ans = kruskals_algo(edges,4) ;
    for(auto it: ans){
        cout<<it.first<<"-->"<<it.second<<endl;                                                                                                                                                                            
    }

    return 0;
}