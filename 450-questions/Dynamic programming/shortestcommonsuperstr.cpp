#include <iostream>
#include "bits/stdc++.h"
using namespace std ;
//maximum function
int max(int a, int b){
    return (a>b) ? a:b ;
}

int superstr(string s1,string s2,int n,int m){
    int dp[n+1][m+1];
    for(int i =0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int i =0;i<=m;i++){
        dp[0][i] = 0;
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1] ) ;
            }
        }
    }
    int len = n+m -dp[n][m];
    return len ;
}
int main(){
    string s1 =  "abcdgh";
    string s2 =  "aedfhr";
    cout<<superstr(s1,s2,6,6)<<endl ;
    
    return 0 ;
}