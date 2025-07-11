#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
#define nu NULL
int mod = 1e9+7 ;
/*
FRIENDS PAIRING PROBLEM
*/
int f(int n){
    if(n<=2){
        return n ;
    }
    return (f(n-2)%mod)*((n-1)%mod)+(f(n-1))%mod ;
    /*
    Time :O(2^n)
    space : o(N)
    */
}
//changing varbile is n 
vector<int> dp(1000,-1) ;
int memo(int n){
    if(n<=2){
        return n ;
    }
    if(dp[n]!=-1) return dp[n] ;
    return dp[n] = (f(n-2)%mod)*((n-1)%mod)+(f(n-1))%mod ;
    /*
    Time :O(2^n)
    space : o(N)
    */
}

int btup(int n){
    vector<int> dp(n+1) ;
    if(n<=2){
        return n ;
    }
    dp[0] = 0;
    dp[1] = 1 ;
    dp[2] = 2 ;
    for(int i = 3;i<=n;i++){
        dp[i] = dp[i-1]%mod +(i-1)*dp[i-2]%mod ;
    }
    return dp[n] ;
    /*
    Time : O(N)
    space : O(N)
    */
}

int spot(int n){
     //vector<int> dp(n+1) ;
    if(n<=2){
        return n ;
    }
    //dp[0] = 0;
    int prev_2 = 1 ;
    int prev_1 = 2 ;
    for(int i = 3;i<=n;i++){
       int curr = prev_1%mod + (i-1)*prev_1%mod ;
       prev_2 = prev_1 ;
       prev_1 = curr ;
    }
    return prev_1 ;
    /*
    Time : O(N)
    space : O(1)
    */

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}