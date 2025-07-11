#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
#define nu NULL
/*
    longest Increasing Subsequence
*/
int helper(int arr[],int curr){
    if(curr == 0){
        return 0 ;
    }
    int ans = INT_MIN ;
    for(int i = curr-1;i>=0 ;i--){
        if(arr[i]<arr[curr]){
            ans = max(ans,1+helper(arr,i)) ;
        }
    }
    return ans ;
}
int f(int arr[],int n){
    int ans = INT_MIN ;
    for(int i = 0;i<n;i++){
        ans = max(ans,helper(arr,i)) ;
    }
    return ans ;
    /*
    Time : O(N^N)
    Space : O(N)
    */
}

int helper_(int arr[],int curr,int dp[]){
    if(curr == 0){
        return 0 ;
    }
    if(dp[curr]!=-1){
        return dp[curr] ;
    }
    int ans = INT_MIN ;
    for(int i = curr-1;i>=0 ;i--){
        if(arr[i]<arr[curr]){
            ans = max(ans,1+helper_(arr,i,dp)) ;
        }
    }
    return dp[curr] = ans ;
}

int memo(int arr[],int n){
    int dp[n] ;
    memset(dp,-1,sizeof(dp)) ;
    int ans = INT_MIN ;
    for(int i = 0;i<n;i++){
        ans = max(ans,helper_(arr,i,dp)) ;
    }
    return ans ;
    /*
    Time : O(N^2)
    Space : O(N)
    */
}

int btup(int arr[],int n){
    if(n<=1){
        return n ;
    }
    int dp[n] ;
    int ans = 0 ;
    for(int i = 0;i<n;i++){
        dp[i] = 1 ;
        for(int j = 0;j<i;j++){
            if(arr[j]<arr[i]){
                dp[i] = max(dp[i],1+dp[j]) ;
            }
        }
        ans = max(ans,dp[i]) ;
    }
    return ans ;
    /*
    Time : O(N^2)
    space : O(N)
    */
}

//using greedy + binary search approach
int optimised_method(int arr[],int n){
    vector<int> ans ;
    for(int i = 0;i<n;i++){
        if(ans.empty() || ans[ans.size()-1]<arr[i]){
            ans.push_back(arr[i]) ;
        }
        else{
            auto it = lower_bound(arr,arr+n,arr[i]) ;
            *it = arr[i] ;
        }
    }
    return ans.size() ;
    /*
    Time : O(NlogN)
    Space : O(N)
    */
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}