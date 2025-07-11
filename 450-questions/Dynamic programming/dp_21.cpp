#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
#define nu NULL
/*
    Longest subsequence-1 
*/
int recursion_lis_helper(vector<int> arr,int curr){
    //base case
    if(curr == 0){
        return 1;
    }
    int ans = 0;
    for(int i = curr-1;i>=0;i--){
        if(abs(arr[curr]-arr[i]) == 1){
            /*
            For a particular curr value we check all other less indexed values than curr
            and from them we will choose maximum value
            then we return it

            */
            ans = max(ans,1+recursion_lis_helper(arr,i)) ;
        }
    }
    return ans;

}
int r(vector<int> arr){
    int max_ans = 1;
    for(int i = 0;i<arr.size();i++){
        //finding maximum answer
        max_ans = max(max_ans,recursion_lis_helper(arr,i));
    }
    return max_ans ;

    /*
    ------------complexities -----------
    time : O(N^N)
    space : O(N) recursive stack space
    */
}


int recursion_lis_helper(vector<int> arr,int curr,vector<int> dp){
    //base case
    if(curr == 0){
        return 1;
    }
    if(dp[curr]!=-1) return dp[curr] ;
    int ans = 0;
    for(int i = curr-1;i>=0;i--){
        if(abs(arr[curr]-arr[i]) == 1){
            /*
            For a particular curr value we check all other less indexed values than curr
            and from them we will choose maximum value
            then we return it

            */
            ans = max(ans,1+recursion_lis_helper(arr,i,dp)) ;
        }
    }
    if(ans == 0) return dp[curr] = 1 ;
    return dp[curr] = ans;

}
int r(vector<int> arr){
    int max_ans = 1;
    vector<int> dp(arr.size(),-1) ;
    for(int i = 0;i<arr.size();i++){
        //finding maximum answer
        max_ans = max(max_ans,recursion_lis_helper(arr,i,dp));
    }
    return max_ans ;

    /*
    ------------complexities -----------
    time : O(N^N)
    space : O(N) recursive stack space
    */
}


//bottom up 
int btup(int arr[],int n){
    if(n == 0)return 0 ;
    if(n == 1) return arr[0] ;
    int dp[n] ;
    dp[0]= 1 ;
    int ans = INT_MIN ;
    for(int i = 1;i<n;i++){
        dp[i] = 1 ;
        for(int j = 0;j<i;j++){
            if(abs(arr[j]-arr[i]) == 1){
                dp[i] = max(dp[i],1+dp[j]) ;
            }
        }
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