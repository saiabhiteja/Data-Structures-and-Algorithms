#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
#define nu NULL
/*
    Permutation Coefficient
*/
//recursion
int f(int n,int k){
    if(k>n) return  0 ;
    if(n == 1){
        return 1 ;
    }
    return f(n-1,k) + k*f(n-1,k-1) ;
    /*
    Time : O(2^N)
    space : O(N)
    */
}

//memorisation
int f(int n,int k,vector<vector<int>> dp){
    if(k>n) return  0 ;
    if(n == 1){
        return 1 ;
    }
    if(dp[n][k]!=-1){
        return dp[n][k] ;
    }
    return dp[n][k] = f(n-1,k) + k*f(n-1,k-1) ;
    /*
    Time : O(N*K)
    space : O(N*K) + O(N)
    */
}

//bottom up
int btup(int n,int k){
    vector<vector<int>> dp(n+1,vector<int>(k+1)) ;
    //n = 0 
    for(int i = 1;i<=k;i++){
        dp[0][i] = 0 ;
    }
    for(int i = 0;i<=n;i++){
        dp[i][0] = 1 ;
    }

    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=k;j++){
            dp[i][j] = dp[i-1][j] + j*dp[i-1][j-1] ;
        }
    }
    return dp[n][k] ;

    /*
    Time : O(N*k)
    space : O(N*K)
    */
}

//space optimisation
int sopt(int n,int k){
    vector<vector<int>> dp(2,vector<int>(k+1)) ;
    //n = 0 
    for(int i = 1;i<=k;i++){
        dp[0][i] = 0 ;
    }
    for(int i = 0;i<=1;i++){
        dp[i][0] = 1 ;
    }

    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=k;j++){
            dp[i%2][j] = dp[(i-1)%2][j] + j*dp[(i-1)%2][j-1] ;
        }
    }
    return dp[n%2][k] ;
    /*
    Time : O(N*k)
    space : O(2*k)
    */
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<sopt(5,5)<<endl;
return 0;
}