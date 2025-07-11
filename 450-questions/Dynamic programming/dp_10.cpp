#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
#define nu NULL
/*
    goldmine problem
*/
bool isvalid(int i,int j,int r,int c){
    return (i>=0 && j>=0 && i<r && j<c ) ;
}
int helper(mat arr, int i,int j){
    if(i == 0){
        return arr[0][j] ;
    }
    int r = arr.size() ;
    int c = arr[0].size() ;
    int right_up,right,right_down ;
    right_up = right = right_down = INT_MIN ;
    if(isvalid(i-1,j-1,r,c)){
        right_up = arr[i][j]+helper(arr,i-1,j-1) ;
    }
    if(isvalid(i,j-1,r,c)){
        right = arr[i][j]+helper(arr,i,j-1) ;
    }
    if(isvalid(i+1,j-1,r,c)){
        right_down = arr[i][j]+helper(arr,i+1,j-1) ;
    }
    return max(right,max(right_up,right_down)) ;
}
int f(mat arr){
    int r = arr.size() ;
    int c = arr[0].size() ;
    int ans = INT_MIN ;
    for(int i = 0;i<c;i++){
        ans = max(ans,helper(arr,r-1,i) ) ;
    }
    return ans ;
    /*
    Time : O(3^(r*c))
    space : O(c)
    */
}

//memo 
vector<vector<int>> dp(1000,vector<int>(1000,-1)) ;
int helper_(mat arr, int i,int j){
    if(i == 0){
        return arr[0][j] ;
    }
    if(dp[i][j]!=-1) return dp[i][j] ;
    int r = arr.size() ;
    int c = arr[0].size() ;
    int right_up,right,right_down ;
    right_up = right = right_down = INT_MIN ;
    if(isvalid(i-1,j-1,r,c)){
        right_up = arr[i][j]+helper_(arr,i-1,j-1) ;
    }
    if(isvalid(i,j-1,r,c)){
        right = arr[i][j]+helper_(arr,i,j-1) ;
    }
    if(isvalid(i+1,j-1,r,c)){
        right_down = arr[i][j]+helper_(arr,i+1,j-1) ;
    }
    return dp[i][j] = max(right,max(right_up,right_down)) ;
}
int memo(mat arr){
    int r = arr.size() ;
    int c = arr[0].size() ;
    int ans = INT_MIN ;
    for(int i = 0;i<c;i++){
        ans = max(ans,helper_(arr,r-1,i) ) ;
    }
    return ans ;
    /*
    Time : O(r*c)
    space : O(r*c)+O(c)
    */
}

//bottom up 
int btup(mat arr){
    int r = arr.size() ;
    int c = arr[0].size() ;
    vector<vector<int>> dp(r,vector<int>(c)) ;
    for(int i = 0;i<r;i++){
        dp[i][0] = arr[i][0] ;
    }
    int ans = INT_MIN ;
    for(int i = 1;i<r;i++){
        for(int j = 1;j<c;j++){
            int right_up,right,right_down ;
        right_up = right = right_down = INT_MIN ;
        if(isvalid(i-1,j-1,r,c)){
        right_up = arr[i][j]+dp[i-1][j-1] ;
        }
         if(isvalid(i,j-1,r,c)){
        right = arr[i][j]+dp[i][j-1] ;
        }
        if(isvalid(i+1,j-1,r,c)){
        right_down = arr[i][j]+dp[i+1][j-1] ;
        }
        dp[i][j] = max(right,max(right_up,right_down)) ;

        if(i == r-1) ans = max(ans,dp[r-1][j]) ;
            
        }
    }
    return ans ;
    /*
    Time : O(r*c)
    space : O(r*c)
    */
}

//space optimisation
int spot(mat arr){
    int r = arr.size() ;
    int c = arr[0].size() ;
    vector<vector<int>> dp(r,vector<int>(2)) ;
    for(int i = 0;i<r;i++){
        dp[i][0] = arr[i][0] ;
    }
    int ans = INT_MIN ;
    for(int i = 1;i<r;i++){
        for(int j = 1;j<c;j++){
        int right_up,right,right_down ;
        right_up = right = right_down = INT_MIN ;
        if(isvalid(i-1,j-1,r,c)){
        right_up = arr[i][j%2]+dp[i-1][(j-1)%2] ;
        }
         if(isvalid(i,j-1,r,c)){
        right = arr[i][j%2]+dp[i][(j-1)%2] ;
        }
        if(isvalid(i+1,j-1,r,c)){
        right_down = arr[i][j%2]+dp[i+1][(j-1)%2] ;
        }
        dp[i][j] = max(right,max(right_up,right_down)) ;

        if(i == r-1) ans = max(ans,dp[r-1][j%2]) ;
            
        }
    }
    return ans ;
    /*
    Time : O(r*c)
    space : O(2*r)
    */
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}