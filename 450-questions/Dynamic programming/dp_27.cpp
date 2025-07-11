#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
#define nu NULL
/*
    maximum path sum
*/
int R(mat arr,int i,int j,int r,int c){
    //base cases
    if(i<0 || j<0 || i>=r || j>=c){
        return  0;
    }
    if(i == 0){
        return arr[0][j] ;
    }
    int up = arr[i][j]+R(arr,i-1,j,r,c) ;
    int up_right = arr[i][j]+R(arr,i-1,j+1,r,c) ;
    int up_left = arr[i][j]+R(arr,i-1,j-1,r,c) ;
    return max(up,max(up_right,up_left)) ;
}
int f(mat arr){
    int r = arr.size() ;
    int c = arr[0].size() ;
    int ans = 0;
    for(int i = c-1;i>=0 ;--i){
        ans = max(ans,R(arr,r-1,i,r,c)) ;
    }
    return ans ;
    /*
    Time : O(3^N)
    space : O(N)
    */
}

int M(mat arr,int i,int j,int r,int c,int dp[100][100]){
    //base cases
    if(i<0 || j<0 || i>=r || j>=c){
        return  0;
    }
    if(i == 0){
        return arr[0][j] ;
    }
    if(dp[i][j]!=-1) return dp[i][j] ;
    int up = arr[i][j]+M(arr,i-1,j,r,c,dp) ;
    int up_right = arr[i][j]+M(arr,i-1,j+1,r,c,dp) ;
    int up_left = arr[i][j]+M(arr,i-1,j-1,r,c,dp) ;
    return dp[i][j] = max(up,max(up_right,up_left)) ;
}
int memo(mat arr){
    
    int r = arr.size() ;
    int c = arr[0].size() ;
    int dp[r][c] ;
    memset(dp,-1,sizeof(dp)) ;
    int ans = 0;
    for(int i = c-1;i>=0 ;--i){
        ans = max(ans,M(arr,r-1,i,r,c,dp)) ;
    }
    return ans ;
    /*
    Time : O(N^2)
    space : O(N)
    */
}

//bottom up
int btup(mat arr){
    int r = arr.size() ;
    int c = arr[0].size() ;
    int dp[r][c] ;
    for(int i = 0;i<c;i++){
        dp[0][i] = arr[0][i] ;
    }
    int ans = 0;
    for(int i = 1;i<r;i++){
        for(int j =0;j<c;j++){
            int down,down_r,down_l ;
            if((j-1)>=0){
                down_l = arr[i][j]+dp[i-1][j-1] ;
            }
            if((j+1)<c){
                down_r = arr[i][j]+dp[i-1][j+1] ;
            }
            down = arr[i][j]+dp[i-1][j] ;
            dp[i][j] = max(down,max(down_r,down_l)) ;
            if(i == r-1) ans = max(ans,dp[i][j]) ;
        }
    }
    /*
    Time : O(N*M)
    space : O(N*M)
    */
   return ans ;
}

int spot(mat arr){
    int r = arr.size() ;
    int c = arr[0].size() ;
    int dp[2][c] ;
    for(int i = 0;i<c;i++){
        dp[0][i] = arr[0][i] ;
    }
    int ans = 0;
    for(int i = 1;i<r;i++){
        for(int j =0;j<c;j++){
            int down,down_r,down_l ;
            if((j-1)>=0){
                down_l = arr[i][j]+dp[(i-1)%2][j-1] ;
            }
            if((j+1)<c){
                down_r = arr[i][j]+dp[(i-1)%2][j+1] ;
            }
            down = arr[i][j]+dp[(i-1)%2][j] ;
            dp[i%2][j] = max(down,max(down_r,down_l)) ;
            if(i == r-1) ans = max(ans,dp[i%2][j]) ;
        }
    }
    return ans ;
    /*
    Time : O(N*M)
    space : O(2*M)
    */
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mat arr = {{348, 391},
          {618, 193}} ;
    cout<<f(arr)<<endl;
    return 0;
}