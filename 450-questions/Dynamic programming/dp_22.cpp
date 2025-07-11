#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
#define nu NULL
/*
 maximum sum of subsequence such that no three adjacent elements are included

*/
int r(int arr[],int ind){
    if(ind == 0){
        return arr[0] ;
    }
    if(ind == 1){
        return arr[0]+arr[1] ;
    }
    if(ind == 2){
        return (max(arr[0]+arr[2],max(arr[0]+arr[1],arr[1]+arr[2]))) ;
    }
    //ind 
    //include 
    int include_1 = arr[ind]+arr[ind-1]+r(arr,ind-3);
    int include_2 = arr[ind]+r(arr,ind-2) ;
    //exclude case
    int exclude = r(arr,ind-1) ;
    return max(exclude,include_1,include_2) ;
    /*
    Time : O(3^N)
    space : O(N)
    */
}

//memo
int memo(int arr[],int ind,int dp[]){
    if(ind == 0){
        return arr[0] ;
    }
    if(ind == 1){
        return arr[0]+arr[1] ;
    }
    if(ind == 2){
        return (max(arr[0]+arr[2],max(arr[0]+arr[1],arr[1]+arr[2]))) ;
    }
    //ind 
    //include 
    int include_1 = arr[ind]+arr[ind-1]+memo(arr,ind-3,dp);
    int include_2 = arr[ind]+memo(arr,ind-2,dp) ;
    //exclude case
    int exclude = memo(arr,ind-1,dp) ;
    return dp[ind] = max(exclude,include_1,include_2) ;
    /*
    Time : O(N)
    space : O(N)
    */
}

//bottom up 
int btup(int arr[],int n){
    int dp[n] ;
    if(n == 0) return 0 ;
    dp[0] = arr[0] ;
    if(n == 1) return arr[0] ;
    dp[1] = arr[0]+arr[1] ;
    if(n == 2) return dp[1] ;
    dp[2] = max(arr[0]+arr[2],max(arr[0]+arr[1],arr[1]+arr[2])) ;
    for(int i = 3;i<n;i++){
        dp[i] = max(dp[i-1],max(arr[i]+arr[i-1]+dp[i-3],arr[i]+dp[i-2])) ;
    }
    return dp[n-1] ;
    /*
    Time : O(N)
    space : O(N)
    */
}

//space optimisation
int spot(int arr[],int n){
    //int dp[n] ;
    if(n == 0) return 0 ;
    //p[0] = arr[0] ;
    if(n == 1) return arr[0] ;
    //dp[1] = arr[0]+arr[1] ;
    if(n == 2) return arr[0]+arr[1] ;
    //dp[2] = max(arr[0]+arr[2],max(arr[0]+arr[1],arr[1]+arr[2])) ;
    int prev_3 = arr[0] ;
    int prev_2 = arr[0]+arr[1] ;
    int prev_1 = max(arr[0]+arr[2],max(arr[0]+arr[1],arr[1]+arr[2])) ;
    for(int i = 3;i<n;i++){
        int curr = max(prev_1,max(arr[i]+arr[i-1]+prev_3,arr[i]+prev_2)) ;
        prev_3 = prev_2 ;
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