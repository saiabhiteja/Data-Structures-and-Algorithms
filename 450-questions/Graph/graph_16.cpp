#include "bits/stdc++.h"
using namespace std;
int dx[8] = {-1,0,1,-1,0,1,-1,1};
    int dy[8] = {-1,-1,-1,1,1,1,0,0} ;
    bool issafe(int row,int col,vector<vector<char>>& grid,vector<vector<bool>>& vis){
        return (row>=0 && col>=0 && row<grid.size() && col<grid[0].size() && 
        !vis[row][col] &&grid[row][col] == '1')   ;      
    }
    void dfs(vector<vector<char>>&grid ,int i, int j,
    vector<vector<bool>>& vis){
        
        vis[i][j] = true;
        for(int k = 0;k<8;k++){
            if(issafe(i+dx[k],j+dy[k],grid,vis)){
                dfs(grid,i+dx[k],j+dy[k],vis);
            }
        }
    }
 
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>vis (n,vector<bool>(m,false));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    ans++;
                    dfs(grid,i,j,vis);
                    
                }
            }
        }
        
        return ans ;
        /*
        Time : O(N*M)
        Space : O(N*M)
        */
}