#include <iostream>
using namespace std ;

//topdown

bool isSubsetSum(int n, int arr[], int sum){
        // array of booleans
        bool dp[n+1][sum+1];

        //base condition = intialising the the matrix
        for(int i = 0 ;i<=n;i++){
            for(int j = 0;j<=sum;j++){
                
                if(j==0){
                    dp[i][j] = true;
                }
                
                if(i==0 & j>0){
                    dp[i][j] = false ;
                }
                
            }
        }
        //other conditions 
        for(int i =1;i<=n;i++){
            for(int j =1;j<=sum;j++){
                if(arr[i-1]<=j){
                    //using or operator in place of max operator
                    dp[i][j] = (dp[i-1][j-arr[i-1]] || dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j] ;
                }
            }
        }
        
        return dp[n][sum] ;
    }
int main(){
    int sum = 9;
    int arr[] = {3,34,4,12,5,2} ;

    cout<<isSubsetSum(6,arr,sum)<<endl ;

    return 0 ;
}