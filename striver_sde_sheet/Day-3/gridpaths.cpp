#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
#define nu NULL
/*
    https://takeuforward.org/data-structure/grid-unique-paths-count-paths-from-left-top-to-the-right-bottom-of-a-matrix/
*/
int ans = 0 ;
void helper(int i,int j,int n){
    if(i == n-1 && j == n-1){
        ans++;
        return  ;
    }
    if((j+1)<n && i<n){
        helper(i,j+1,n) ;
    }
    if((i+1)<n){
        helper(i+1,j,n) ;
    }
}
int method1(int n){
    //using recursion
    helper(0,0,n) ;
    return ans ;
    /*
    Time : O(2^N)
    space : O(1)
    */
}

int method2(int n){
    mat dp(n,vector<int>(n,0)) ;
    for(int i = 0;i<n;i++){
        dp[0][i] = 1 ;
        dp[i][0] = 1 ;
    }
    for(int i = 1;i<n;i++){
        for(int j = 1;j<n;j++){
            dp[i][j] = dp[i-1][j] +dp[i][j-1] ;
        }
    }

    return dp[n-1][n-1] ;
    /*
    Time : O(N^2)
    space : O(N^2)
    */

}

int method3(int n,int m){
     int N = n + m - 2;
            int r = m - 1; 
            double res = 1;
            
            for (int i = 1; i <= r; i++)
                res = res * (N - r + i) / i;
            return (int)res;

    /*
    Time : O(n)
    space : O(1)
    */
}
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
return 0;
}