#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
#define nu NULL
/*
    nth catlan number
*/
int mod = 1e9+7 ;
//recursion
int f(int n){
    if(n == 0){
        return 1 ;
    }
    int ans = 0;
    for(int i = 0;i<n;i++){
        ans += (f(i)*f(n-i-1)) ;
    }
    return ans%mod ;
    /*
    Time : O(N*2^N)
    space : O(N)
    */
}

//memorisation
int f(int n,vector<int> dp){
    if(n == 0){
        return 1 ;
    }
    if(dp[n]!= -1){
        return dp[n] ;
    }
    int ans = 0;
    for(int i = 0;i<n;i++){
        ans += (f(i)*f(n-i-1)) ;
    }
    return dp[n] = ans%mod ;
    /*
    Time : O(N*N)
    space : O(N) + O(N)
    */
}

//bottom up
int btup(int n){
    vector<int> dp(n+1) ;
    dp[0] = 1 ;
    dp[1] = 1 ;
    for(int i = 2;i<=n;i++){
        for(int j = 0;j<i;j++){
            dp[i]+=(dp[j]*dp[i-j-1]) ;
        }
    }
    return dp[n] ;
    /*
    Time : O(N*N)
    space : O(N*N)
    */
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     for (int i = 0; i < 10; i++)
        cout << f(i) << " ";
    return 0;
}