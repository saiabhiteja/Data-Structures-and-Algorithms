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


int main(){
    
    int arr[] = {1,5,11,5} ;

    cout<<isperfectSum(4,arr,11)<<endl ;

    return 0 ;
}