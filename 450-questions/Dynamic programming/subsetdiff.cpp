#include <iostream>
using namespace std ;

//topdown

int isperfectSum(int n, int arr[], int sum){
        // array of booleans
        int dp[n+1][sum+1];

        //base condition = intialising the the matrix
        for(int i = 0 ;i<=n;i++){
            for(int j = 0;j<=sum;j++){
                
                if(j==0){
                    dp[i][j] = 1;
                }
                
                if(i==0 & j>0){
                    dp[i][j] = 0 ;
                }
                
            }
        }
        //other conditions 
        for(int i =1;i<=n;i++){
            for(int j =1;j<=sum;j++){
                if(arr[i-1]<=j){
                   
                    dp[i][j] = (dp[i-1][j-arr[i-1]] + dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j] ;
                }
            }
        }
        
        return dp[n][sum] ;
}
//we have to divide arr into two parts 
//then we have to calculate the summ of both arrays
//the difference between both arrays should be given diff value
//we have to return number of possible subsets 

int countsubsetdiff(int arr[] , int diff,int n){
    long sum = 0 ;
    for(int i = 0;i<n;i++){
            sum = sum+arr[i] ;
    }

    int s = (diff + sum)/2 ;

    int count = isperfectSum(n,arr,s) ;

    return count ;


}

int main()
{
    int arr[] = {1,5,11,5} ;
    cout<<countsubsetdiff(arr,0,4) ;
    return 0 ;

}