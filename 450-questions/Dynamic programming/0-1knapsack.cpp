#include <iostream>
#include <cstring>
using namespace std;

int max(int a ,int b )
{ return (a > b) ? a : b; }

/*
int knapsack(int wt[],int val[] ,int n , int w){
    //recursive method
    //base condition
    if(n==0 || w==0){
        return 0;
    }

    //other conditions
    if(wt[n-1]<=w){
        return (
            max(val[n-1]+knapsack(wt,val,n-1,w-(wt[n-1]))
            ,knapsack(wt,val,n-1,w))
            ) ;
    }

    else{
        return knapsack(wt,val,n-1,w) ;
    }
}
*/
/*
int knapsack(int wt[],int val[],int n,int w){
    //recursive method with memorisation
    //creating an array for storing values
    int dp[n+1][w+1] ;
    //intialising matrix with -1
    memset(dp,-1,sizeof(dp));
    //base condition
    if(n==0 || w==0){
        return 0 ;
    }
    //checking in matrix wether value is present or not
    if(dp[n][w]!=-1){
        return dp[n][w] ;
    }

    //other conditions
    if(wt[n-1]<=w){
        dp[n][w] = max(val[n-1]+knapsack(wt,val,n-1,w-(wt[n-1]))
                    ,knapsack(wt,val,n-1,w)) ;
        return (dp[n][w]) ;
    }

    else{
        dp[n][w] = knapsack(wt,val,n-1,w) ; 
        return dp[n][w] ;
    }
}
*/

//top-down approach
int knapsack(int wt[],int val[],int n , int w){
    //matrix of size n,w
    int dp[n+1][w+1];

    //covering base condition with intilasation with zero
    for(int i = 0;i<n+1;i++){
        for(int j = 0;j<w+1;j++){
            if(i==0 || j==0)
            {
                dp[i][j] = 0 ;
            }
        }
    }

    //other conditions

    for(int i = 1 ; i<=n;i++){
        for(int j = 1;j<=w;j++){
            if(wt[i-1]<=j){
                dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]],
                                dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j] ;
            }

        }

    }

    return dp[n][w] ; 
}


int main(){
    int wt[] = {4,5,1};
    int val[] = {1,2,3};
    cout<<"Max profit : "<< knapsack(wt,val,3,4)<<endl;
    return 0;
}