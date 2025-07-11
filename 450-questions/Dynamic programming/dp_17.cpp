#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
#define nu NULL
/*
    space optimised solution for lcs
*/
int sopt(string s,string t){
    int l1 = s.size() ;
    int l2 = t.size() ;
    vector<vector<int>> dp(2,vector<int>(l2+1)) ;
    for(int i = 0;i<=1;i++){
        for(int j = 0;j<=l2;j++){
            if(i == 0||j == 0){
                dp[i][j] = 0 ;
            }
        }
    }

    for(int i = 1;i<=l1;i++){
        for(int j = 1;j<=l2;j++){
            if(s[i-1] == t[j-1]){
                dp[i%2][j] = 1+dp[(i-1)%2][j-1] ;
            }
            else{
                dp[i%2][j] = max(dp[(i-1)%2][j],dp[i%2][j-1]) ;
            }
        }
    }

    return dp[l1%2][l2] ;

    /*
    Time : O(l1*l2)
    space : O(2*l2)
    */

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}