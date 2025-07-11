#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*
    distance to nearesrt 1 in a binary matrix
    multi source bfs
*/
    int dx[4] = {-1,1,0,0} ;
    int dy[4] = {0,0,1,-1} ;
    bool isvalid(int x,int y,int n,int m){
        return (x>=0 && y>=0 && x<n && y<m) ;
    }
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid){
	    
	    int r = grid.size() ;
	    int c = grid[0].size() ;
	    vector<vector<int>>dis(r,vector<int>(c,0)),vis(r,vector<int>(c,0)) ;
	    queue<pair<int,int>> q ;
	    for(int i = 0;i<r;i++){
	        for(int j = 0;j<c;j++){
	            if(grid[i][j] == 1){
	                q.push({i,j});
	                vis[i][j] = 1;
	            }
	        }
	    }
	    while(q.size()!=0){
	        auto t = q.front() ;
            q.pop() ;
            int x = t.first ;
            int y = t.second ;
            
            for(int i = 0;i<4;i++){
                int nx = x+dx[i] ;
                int ny = y+dy[i] ;
                if(isvalid(nx,ny,r,c) && !vis[nx][ny]){
                    q.push({nx,ny});
                    vis[nx][ny] = 1;
                    dis[nx][ny] = 1+dis[x][y] ;
                }
            }
	    }
	    return dis;
        /*
        Time : O(N*M)
        Space : O(N*M)
        */
	   
}

int main() {
    vector<vec> grid = {{0,1,1,0},{1,1,0,0},{0,0,1,1}} ;
    auto t = nearest(grid);
    for(auto it: t){
        for(auto i: it){
            cout<<i<<" ";
        }
        cout<<endl;
    }

    return 0;
}