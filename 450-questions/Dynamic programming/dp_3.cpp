#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
#define nu NULL
/*
    find ncr 
*/
//recursion
int f(int n,int r){
    if(r>n){
        return  0;
    }

    if(r == n){
        return 1 ;
    }
    if(n == 0 || r == 0){
        return 1 ;
    }
    return f(n-1,r-1)+f(n-1,r) ;
    /*
    Time : O(2^N)
    Space : O(N) //recursive stack
    */
}
//memorisation
int mod = 1000000007 ;
int f(int n,int r,vector<vector<int>>& dp){
    if(r>n){
        return  0;
    }
    
    if(r == n){
        return 1 ;
    }
    if(n == 0 || r == 0){
        return 1 ;
    }
    if(dp[n][r]!=-1){
        return dp[n][r] ;
    }
    return dp[n][r] = (f(n-1,r-1,dp)%mod+f(n-1,r,dp)%mod)%mod ;

    /*
    Time : O(N*R)
    space : O(N*R) + O(N)
    */
}
//bottom up 
int btup(int n,int r){

    if(r>n) return  0;
    vector<vector<int>> dp(n+1,vector<int>(r+1)) ;
    //n = 0 
    for(int i = 1;i<=r;i++){
        dp[0][i] = 0;
    }
    //r = 0
    for(int i = 0;i<=n;i++){
        dp[i][0] = 1 ;
    }

    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=r;j++){
            dp[i][j] = (dp[i-1][j] + dp[i-1][j-1])%1000000007 ;
        }
    }

    return dp[n][r] ;
    /*
    Time : O(N*r)
    space : O(N*r)
    */
}
//space optimised

int spot(int n,int r){

    if(r>n) return  0;
    vector<vector<int>> dp(2,vector<int>(r+1)) ;
    //n = 0 
    for(int i = 1;i<=r;i++){
        dp[0][i] = 0;
    }
    //r = 0
    for(int i = 0;i<=1;i++){
        dp[i][0] = 1 ;
    }

    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=r;j++){
            dp[i%2][j] = (dp[(i-1)%2][j] + dp[(i-1)%2][j-1])%1000000007 ;
        }
    }

    return dp[n%2][r] ;
    /*
    Time : O(N*R)
    space : O(2*r)
    */
}

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
return 0;
}