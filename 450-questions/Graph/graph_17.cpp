#include "bits/stdc++.h"
using namespace std;
/*
     we have to form a graph according to sorted strings 
     then for order we should find topo sort 
*/

void dfs_helper(int node,vector<int>&vis,stack<int>&st,vector<int>adj[]){
        
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs_helper(it,vis,st,adj);
            }
        }
        st.push(node);
    }


string findOrder(string dict[], int n, int k) {
        vector<int> adj[k] ;
        
        for(int i = 1;i<n;i++){
            string s1 = dict[i-1];
            string s2 = dict[i];
            int j = 0;
            int l1 = s1.length();
            int l2 = s2.length();
            for(int j=0; j<min(l1,l2); j++){
                if(s1[j] != s2[j]){
                   int u = s1[j] - 'a';
                   int v = s2[j] - 'a';
                   adj[u].push_back(v);
                   break;
                }
            };
        }
        
        vector<int>vis(k,0);
        stack<int> st ;
        for(int i = 0;i<k;i++){
            if(!vis[i]){
                dfs_helper(i,vis,st,adj);
            }
        }
        string ans = "";
        while(st.size()!=0){
            int x = st.top();
            ans+= x+'a';
            st.pop();
        }
        //cout<<ans;
        return ans;
        /*
        Time : O(N^2) + O(V+E)
        Space : O(V+E) + O(V)+O(N)
        */
        
        
    }