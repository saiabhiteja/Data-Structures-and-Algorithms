#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9
#define vec vector<int>
#define pp pair<int,int>
/*
    rat in maze problem
*/
//dlru
int dx[4] = {1,0,0,-1};
int dy[4] = {0,-1,1,0} ;

bool isvalid(vector<vector<int>>& m ,int x,int y,vector<vector<int>>& vis,int n){
    return (x>=0 && y>=0 && x<n && y<n && m[x][y]!=0 && !vis[x][y]);
}
void helper(int x,int y,vector<vector<int>>& m ,string temp,vector<string>& ans,int n,vector<vector<int>>& vis){
    if(x == n-1 && y == n-1){
        ans.push_back(temp) ;
        return ;
    }
    string dir = "DLRU" ;
    for(int i = 0;i<4;i++){
        int nx = x+dx[i] ;
        int ny = y+dy[i] ;
        if(isvalid(m,nx,ny,vis,n)){
            vis[x][y] = 1 ;
            helper(nx,ny,m,temp+dir[i],ans,n,vis) ;
            vis[x][y] = 0;
        }
    }


}
vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans ;
        vector<vector<int>> vis(n,vector<int>(n,0)) ;
        helper(0,0,m,"",ans,n,vis) ;
        return ans ;
        /*
        Time : O(3^N*N)
        space : O(N*N) + O(N*N)
        */
}
int main() {
    vector<vector<int>> m = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}} ;
    vector<string> ans = findPath(m,4);
    for(string s:ans){
        cout<<s<<endl;
    }

    return 0;
}