#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
#define nu NULL
/*
    longest common subsequence of three strings
*/
//same as two strings 
//just include another dimension
int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    vector<vector<vector<int>>>dp(n1+1,vector<vector<int>>(n2+1,vector<int>(n3+1,0)));  //Intializing the 3D vector with 0
   for(int i=1;i<=n1;i++){        //
       for(int j=1;j<=n2;j++){    
           for(int k=1;k<=n3;k++){//
               if(A[i-1]==B[j-1]&&B[j-1]==C[k-1])
               dp[i][j][k]=1+dp[i-1][j-1][k-1];
               else
               dp[i][j][k]=max({dp[i-1][j][k],dp[i][j-1][k],dp[i][j][k-1]});
           }
       }
   }
   return dp[n1][n2][n3];
   /*
   Time : O(N^3)
   Space : O(N^2)
   */
}
//can we space optimise it?
int spot(string A, string B, string C, int n1, int n2, int n3)
{
    vector<vector<vector<int>>>dp(2,vector<vector<int>>(n2+1,vector<int>(n3+1,0)));  //Intializing the 3D vector with 0
   for(int i=1;i<=n1;i++){        //
       for(int j=1;j<=n2;j++){    
           for(int k=1;k<=n3;k++){//
               if(A[i-1]==B[j-1]&&B[j-1]==C[k-1])
               dp[i%2][j][k]=1+dp[(i-1)%2][j-1][k-1];
               else
               dp[i%2][j][k]=max({dp[(i-1)%2][j][k],dp[i%2][j-1][k],dp[i%2][j][k-1]});
           }
       }
   }
   return dp[n1%2][n2][n3];
   /*
   Time : O(N^3)
   Space : O(N^2)
   */
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}