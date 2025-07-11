#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
#define nu NULL
/*
check subset sum
*/
bool f(vec arr, int ind,int tar){
    if(ind == 0){
        if(tar == 0 || tar == arr[0] ){
            return true ;
        }
        return false;
    }
    if(tar == 0){
        return true ;
    }
    bool pick = false ;
    if(arr[ind]<=tar){
        pick = f(arr,ind-1,tar-arr[ind]) ;
    }
    bool notpick = f(arr,ind-1,tar) ;
    return pick || notpick ;
    /*
    Time : O(2^N)
    space : O(N)
    */
}

vector<vector<int>> dp(1000,vector<int>(1000,-1)) ;
bool memo(vec arr,int ind ,int tar){
    if(ind == 0){
        if(tar == 0 || tar == arr[0] ){
            return true ;
        }
        return false;
    }
    if(dp[ind][tar]!=-1) return dp[ind][tar] ;
    if(tar == 0){
        return true ;
    }
    bool pick = false ;
    if(arr[ind]<=tar){
        pick = f(arr,ind-1,tar-arr[ind]) ;
    }
    bool notpick = f(arr,ind-1,tar) ;
    return dp[ind][tar] = pick || notpick ;
    /*
    Time : O(N^2)
    space : O(N^2)+O(N)//recursive stack
    */

}

bool btup(vec arr,int tar){
    int n = arr.size() ;
    vector<vector<bool>> dp(n+1,vector<bool>(tar+1,false)) ;
    for(int i = 0;i<=n;i++){
        dp[i][0] = 1 ;
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=tar;j++){
            if(arr[i-1]<=j){
                dp[i][j] = dp[i-1][j-arr[i-1]]||dp[i-1][j] ;
            }
            else{
                dp[i][j] = dp[i-1][j] ;
            }
        }
    }
    return dp[n][tar] ;
    /*
    Time : O(N^2)
    space : O(N^2)
    */
}
bool spot(vec arr,int tar){
    int n = arr.size() ;
    vector<vector<bool>> dp(2,vector<bool>(tar+1,false)) ;
    for(int i = 0;i<=1;i++){
        dp[i][0] = 1 ;
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=tar;j++){
            if(arr[i-1]<=j){
                dp[i%2][j] = dp[(i-1)%2][j-arr[i-1]]||dp[(i-1)%2][j] ;
            }
            else{
                dp[i%2][j] = dp[(i-1)%2][j] ;
            }
        }
    }
    return dp[n%2][tar] ;
    /*
    Time : O(N^2)
    space : O(N*2)
    */

}

bool can_we_partion(vec arr){
    //can we equaly partion given two subsets such that both sum are equally
    int sum = 0 ;
    accumulate(arr.begin(),arr.end(),sum) ;
    if(sum%2){
        return false ;
    }
    return spot(arr,sum/2) ;
    /*
    Time : O(N^2)
    space : O(2*N)
    */
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}