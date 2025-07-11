#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*
    rotten oranges
    https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1
*/
int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int oranges = 0;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[i].size();j++){
                if(grid[i][j] == 1){
                    oranges++;
                }
                if(grid[i][j] ==2){
                    q.push({i,j});
                }
            }
        }
        
        int dx[4] = {0,0,1,-1};
        int dy[4] = {-1,1,0,0};
        
        
        int mins = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        
        while(q.size()!=0){
            int si = q.size();
            
            for(int i = 0;i<si;i++){
                auto t = q.front();
                q.pop();
                int x = t.first;
                int y = t.second;
                for(int j = 0;j<4;j++){
                    int nx = x+dx[j];
                    int ny = y+dy[j];
                    
                    if(nx>=0 && nx<rows && ny>=0 && ny<cols){
                        if(grid[nx][ny] == 1){
                            oranges--;
                            grid[nx][ny] = 2;
                            q.push({nx,ny});
                        }
                    }
                }
            }
            
            if(!q.empty()){
                mins++;
            }
            
        }
        if(oranges == 0){
            return mins;
        }
        return -1;
        /*
        Time : O(N*M)
        Space : O(N*M)
        */
    }
int main() {
    vector<vector<int>> grid = {{0,1,2},{0,1,2},{2,1,1}} ;
    cout<<orangesRotting(grid)<<endl;
    return 0;
}