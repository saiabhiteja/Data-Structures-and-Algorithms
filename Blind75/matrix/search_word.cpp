class Solution {
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,1,-1};
    bool isvalid(int x,int y,int r,int c,vector<vector<bool>>& vis){
        return (x>=0 &&y>=0 && x<r &&y<c && !vis[x][y]) ;
    }
    bool dfs(int x,int y,string s,int ind ,vector<vector<bool>>& vis,vector<vector<char>>& brd){
        if(ind == s.length()){
            return true ;
        }
        vis[x][y] = true;
        for(int i = 0;i<4;i++){
            int nx = x+dx[i] ;
            int ny = y+dy[i] ;
            if(isvalid(nx,ny,brd.size(),brd[0].size(),vis) && s[ind]==brd[nx][ny]){
                if(dfs(nx,ny,s,ind+1,vis,brd)){
                    return true;
                }
            }
        }
        vis[x][y] = false;
        return false;
    }
public:
    bool exist(vector<vector<char>>& brd, string s) {
    vector<vector<bool>> vis(brd.size(),vector<bool>(brd[0].size(),false))  ;
        for(int i =0;i<brd.size();i++){
            for(int j = 0;j<brd[i].size();j++){
                if(s[0] == brd[i][j]){
                    if(dfs(i,j,s,1,vis,brd)){
                        return true;
                    }
                }
            }
        }
        return false;
        
    }
};