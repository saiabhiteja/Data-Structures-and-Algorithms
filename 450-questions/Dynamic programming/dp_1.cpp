#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
#define nu NULL
/*
coin change problem
*/

//recursion
long long int f(ll int ind ,vector<long long > coins,int target){
    if(ind == 0){
        if(target == 0 || target%coins[0] == 0){
            return 1 ;
        }
        return 0 ;
    }

    if(target == 0){
        return 1 ;
    }

    long long int pick = 0,notpick = 0 ;
    if(coins[ind]<=target){
        pick = f(ind,coins,target-coins[ind]) ;
    }
    notpick = f(ind-1,coins,target) ;

    return pick+notpick ;

    /*
    Time : O(2^N)
    space : O(N)
    */

}

//memorisation
long long int f(int ind ,int coins[],int target,vector<vector<long long int>>&dp){
    if(ind == 0){
        if(target == 0 || target%coins[0] == 0){
            return 1 ;
        }
        return 0 ;
    }

    if(target == 0){
        return 1 ;
    }
    
    if(dp[ind][target]!=-1){
        return dp[ind][target] ;
    }

    long long int pick = 0,notpick = 0 ;
    if(coins[ind]<=target){
        pick = f(ind,coins,target-coins[ind],dp) ;
    }
    notpick = f(ind-1,coins,target,dp) ;

    return dp[ind][target] = pick+notpick ;

    /*
    Time : O(N*target)
    space : O(N*target) + O(N) //recursive stack
    */

}

//bottom up
long long int btup(int coins[],int target,int n){
    //dp matrix
    vector<vector<long long int>> dp(n+1,vector<long long int>(target+1)) ;
    //base cases 
    for(int i = 0;i<=n;i++){
        dp[i][0] = 1 ;
    }
    for(int i = 1;i<=target;i++){
        dp[0][i] = 0 ;
    }

    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=target;j++){
            if(coins[i-1]<=j){
                dp[i][j] = dp[i][j-coins[i-1]]+dp[i-1][j] ;
            }
            else{
                dp[i][j] = dp[i-1][j] ;
            }
        }
    }

    return dp[n][target] ;
    /*
    Time : O(N*target)
    space : O(N*target)
    */
}

//space optimised
long long int btup(int coins[],int target,int n){
    //dp matrix
    vector<vector<long long int>> dp(2,vector<long long int>(target+1)) ;
    //base cases 
    for(int i = 0;i<=1;i++){
        dp[i][0] = 1 ;
    }
    for(int i = 1;i<=target;i++){
        dp[0][i] = 0 ;
    }

    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=target;j++){
            if(coins[i-1]<=j){
                dp[i%2][j] = dp[i%2][j-coins[i-1]]+dp[(i-1)%2][j] ;
            }
            else{
                dp[i%2][j] = dp[(i-1)%2][j] ;
            }
        }
    }

    return dp[n%2][target] ;
    /*
    Time : O(N*target)
    space : O(2*target)
    */
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}