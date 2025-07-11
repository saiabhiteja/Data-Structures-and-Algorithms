#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
#define nu NULL
/*
    longest common subsequence
*/

int f(int ind1,int ind2,string s,string t){
    if(ind1<0 || ind2<0){
        return  0;
    }
    if(s[ind1] == t[ind2]){
        return 1+f(ind1-1,ind2-1,s,t) ;
    }
    return max(f(ind1,ind2-1,s,t),f(ind1-1,ind2,s,t)) ;

    /*
    Time : O(2^max(N,M))
    space : O(max(N,M))
    */
}
int f_(int ind1,int ind2,string s,string t,vector<vector<int>> dp){
    if(ind1<0 || ind2<0){
        return  0;
    }
    if(dp[ind1][ind2]!=-1){
        return dp[ind1][ind2] ;
    }
    if(s[ind1] == t[ind2]){
        return dp[ind1][ind2] = 1+f_(ind1-1,ind2-1,s,t,dp) ;
    }
    return dp[ind1][ind2] = max(f_(ind1,ind2-1,s,t,dp),f_(ind1-1,ind2,s,t,dp)) ;

    /*
    Time : O(N*M)
    space : O(N*M)) + O(max(N,M))
    */

}
//bottom up
int btup(string s,string t){
    int l1 = s.size() ;
    int l2 = t.size() ;
    vector<vector<int>> dp(l1+1,vector<int>(l2+1)) ;
    for(int i = 0;i<=l1;i++){
        for(int j = 0;j<=l2;j++){
            if(i == 0||j == 0){
                dp[i][j] = 0 ;
            }
        }
    }

    for(int i = 1;i<=l1;i++){
        for(int j = 1;j<=l2;j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = 1+dp[i-1][j-1] ;
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]) ;
            }
        }
    }

    return dp[l1][l2] ;
    /*
    Time : O(l1*l2)
    space : O(l1*l2)
    */

}
//space optimisation
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
    vector<vector<int>> dp (2+1,vector<int>(5+1,-1)) ;
    cout<<f_(2,5,"ab","aedfhr",dp)<<endl;
    return 0;
}