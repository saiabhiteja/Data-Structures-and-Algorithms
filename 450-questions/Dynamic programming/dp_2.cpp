#include "bits/stdc++.h"
using namespace std;

//recursion
int recursive_kapsack(vector<int> wt,vector<int> val,int n,int W){
    //base condition
    if(n==0 || W == 0){
        return 0;
    }
    if(wt[n-1]<=W){
        return (max(val[n-1]+recursive_kapsack(wt,val,n-1,W-wt[n-1]),
        recursive_kapsack(wt,val,n-1,W) ));
    }
    else{
        return recursive_kapsack(wt,val,n-1,W) ;
    }

    /*
    --------------complexities---------
    time : O(2^N)  
    space : O(N) : recursive stack 
    */
}

//top-down approach
int dp[1001][1001] ;

int memorization_knapsack(vector<int> wt,vector<int> val,int n,int W){
    if(n==0 || W == 0){
        return 0;
    }
    if(dp[n][W]!=-1){
        return dp[n][W];
    }
    if(wt[n-1]<=W){
        return dp[n][W] = (max(
            val[n-1]+recursive_kapsack(wt,val,n-1,W-wt[n-1]),
        recursive_kapsack(wt,val,n-1,W) ));
    }
    else{
        return dp[n][W] = recursive_kapsack(wt,val,n-1,W) ;
    }
    /*
    -----------complexities -----------
    time : O(N*W) 
    space : O(N*W) + O(N) matrix_table + recursive stack
    */

}

//using bottom -up
int knapsack(vector<int> wt,vector<int> val,int n,int W){
    int dp[n+1][W+1];
    for(int i = 0;i<=n;i++){
        for(int j = 0;j<=W;j++){
            if(i ==0 || j==0){
                dp[i][j] = 0 ;
            }
        }
    }

    for(int i = 1;i<=n;i++){
        for(int j=1;j<=W;j++){
            if(wt[i-1]<=j){
                dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j] ;
            }
        }
    }
    return dp[n][W];
    /*
    --------------complexities-------------
    time : O(N*W)
    space : O(N*W) just matrix
    
    */
}

//further optimisation of knapsack (memory optimisation)
int optimised_knapsack(vector<int> wt,vector<int> val,int n,int W){
    int dp[2][W+1];
    

    for(int i = 0;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(i == 0 || j == 0){
                dp[i%2][j] = 0; 
            }
            else if(wt[i-1]<=j){
                dp[i%2][j] = max(val[i-1] + dp[(i-1)%2][j-wt[i-1]],dp[(i-1)%2][j]);
            }
            else{
                dp[i%2][j] = dp[(i-1)%2][j] ;
            }
        }
    }
    return dp[n%2][W];
    /*
    --------------complexities-------------
    time : O(N*W)
    space : O(2*W) just 2d matrix
    
    */
}

//further optimisation just using 1d array
int f_optimised_knapasack(vector<int> wt,vector<int> val,int n ,int W){
    int dp[W+1];
    memset(dp,0,sizeof(dp));
    for(int i = 1;i<=n;i++){
        for(int j = W;j>=0;j--){
            if(wt[i-1]<=j){
                dp[j] = max(dp[j],dp[j-wt[i-1]]+val[i-1]);
            }
        }
    }
    return dp[W];
    /*
    ----------------complexitites--------
    time : O(N*wt)
    space : O(wt) just 1d array 

    */
}

int main(){

    vector<int> val = {100,70,50,10};
    vector<int> wt = {10,4,6,12} ;

    memset(dp,-1,sizeof(dp));

    cout<<"Recursive: "<<recursive_kapsack(wt,val,4,12)<<endl;
    cout<<"Memorised : "<<memorization_knapsack(wt,val,4,12)<<endl;
    cout<<"Dp : "<<knapsack(wt,val,4,12)<<endl;
    cout<<"Dp optimised-1 : "<<optimised_knapsack(wt,val,4,12)<<endl;
    cout<<"Dp optimised-2 : "<<f_optimised_knapasack(wt,val,4,12)<<endl;
    
    return 0;
}