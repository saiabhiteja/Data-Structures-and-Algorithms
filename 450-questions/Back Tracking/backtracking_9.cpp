#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define mat vector<vector<int>>
#define ll long long
/*
    finding knights tour
    https://www.geeksforgeeks.org/the-knights-tour-problem-backtracking-1/
*/

int dx[8] = {1,1,-1,-1,2,2,-2,-2};//take care of cordinates 
int dy[8] = {2,-2,2,-2,1,-1,1,-1};//if not tle will occurs
bool isvalid(int x,int y,mat& brd){
    return (x>=0 && y>=0 && x<8 && y<8 && brd[x][y] == -1);
}
bool helper(int x,int y,int time,mat& brd){

    if(time == 8*8){
        return true;
    }

    for(int k = 0;k<8;k++){
        int nx = x+dx[k] ;
        int ny = y +dy[k] ;
        if(isvalid(nx,ny,brd)){
            brd[nx][ny] = time ;
            if(helper(nx,ny,time+1,brd)) {
                return true;
            }
            else{
                brd[nx][ny] = -1;
            }
        }
    }
    return false;
}
void knights_tour(){
    vector<vector<int>> brd(8,vector<int>(8,-1)) ;
    brd[0][0] = 0;
    helper(0,0,1,brd) ;

    for(int i = 0;i<8;i++){
        for(int j = 0;j<8;j++){
            cout<<brd[i][j]<<" ";
        }
        cout<<endl;
    }
    /*
    Time : O(8^N*N)
    Space : O(N*N)
    */

}
int main() {
    knights_tour();
    return 0;
}