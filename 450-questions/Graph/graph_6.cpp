#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9
#define vec vector<int>
#define pp pair<int,int>
/*
*/
int dx[4] = {1,0,0,-1};
int dy[4] = {0,-1,1,0};
bool issafe(int row,int col,int n,vector<vec>m,vector<vec>vis){
    return (row>=0 && col>=0 &&
            row<n && col<n &&
            m[row][col]!=0 && !vis[row][col]);
}
void dfs(int x,int y ,int n,vector<vec>& m,vector<vec>&vis,string temp,vector<string>& ans){
    if(x == (n-1) && y == (n-1)){
        ans.push_back(temp);
        return ;
    }
    string dir = "DLRU";
    for(int i = 0;i<4;i++){
        int nx = x+dx[i] ;
        int ny = y+dy[i] ;
        if(issafe(nx,ny,n,m,vis)){
            vis[x][y] = 1 ;
            dfs(nx,ny,n,m,vis,temp+dir[i],ans);
            vis[x][y] = 0;
        }
    }
}
vector<string> findPath(vector<vector<int>> &m, int n) {

    vector<string> ans ;
    vector<vec> vis(n,vec(n,0));
    dfs(0,0,n,m,vis,"",ans);
    return ans ;
    /*
    Time : O(4^N*N)
    Space : O(N*N)
    */
        
}
int main() {
/**/
vector<vec>mat = {
        {1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}} ;
vector<string> ans = findPath(mat,4) ;
for(auto it : ans){
    cout<<it<<endl;
}
return 0;
}