#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
#define nu NULL
/*
    max sum increasing subsequence
*/
int helper(int arr[],int curr){
    if(curr == 0){
        return arr[curr] ;
    }
    int ans = 0 ;
    for(int i = curr-1;i>=0;i--){
        if(arr[curr]>arr[i]){
            ans = max(ans,arr[curr]+helper(arr,i));
        }
    }
    return ans ;
}
int r(int n,int arr[]){
    int ans = INT_MIN ;
    for(int i = 0;i<n;i++){
        ans = max(ans,helper(arr,i)) ;
    }
    return ans ;
    /*
    Time : O(N^N)
    space : O(N)
    */
}


int helper_(int arr[],int curr,int dp[]){
    if(curr == 0){
        return arr[curr] ;
    }
    if(dp[curr]!=-1){
        return dp[curr] ;
    }
    int ans = 0 ;
    for(int i = curr-1;i>=0;i--){
        if(arr[curr]>arr[i]){
            ans = max(ans,arr[curr]+helper_(arr,i,dp));
        }
    }
    if(ans == 0) return dp[curr] = arr[curr] ;
    return dp[curr] = ans ;
}
int r(int n,int arr[]){
    int dp[n] ;
    memset(dp,-1,sizeof(dp)) ;

    int ans = INT_MIN ;
    for(int i = 0;i<n;i++){
        ans = max(ans,helper_(arr,i,dp)) ;
    }
    return ans ;
    /*
    Time : O(N^2)
    space : O(N)
    */
}

//bottom up
int btup(int arr[],int n){
    int dp[n] ;
    if(n==0){
        return 0;
    }
    if(n == 1){
        return arr[0] ;
    }
    int ans = 0 ;
    dp[0] = arr[0] ;
    for(int i = 1;i<n;i++){
        
        int sum = INT_MIN ;
        for(int j =0;j<i;j++){
            if(arr[i]>arr[j]){
                sum = max(sum,dp[j]) ;
            }
        }
        if(sum == INT_MIN ){
            sum = 0;
        }
        dp[i] = sum+arr[i] ;
        ans = max(ans,dp[i]) ;
    }
    return ans ;
    /*
    Time : O(N)
    space : O(N)
    */
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}