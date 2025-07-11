#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
#define nu NULL
/*
    Maximize The Cut Segments 
*/
int r(int l ,int x,int y,int z){
    if(l == 0){
        return  0;
    }
    int a,b,c ;
    a = b = c = 0;
    if(x<=l){
        a = r(l-x,x,y,z) ;
    }
    if(y<=l){
        b = r(l-y,x,y,z) ;
    }
    if(z<=l){
        c = r(l-z,x,y,z) ;
    }
    return max(a,max(b,c))+1 ;
    /*
    Time : O(3^N)
    space : O(N)
    */
}
int dp[101] ;
int memo(int l ,int x,int y,int z){
    if(l == 0){
        return  0;
    }
    if(dp[l]!= -1) return dp[l] ;
    int a,b,c ;
    a = b = c = 0;
    if(x<=l){
        a = memo(l-x,x,y,z) ;
    }
    if(y<=l){
        b = memo(l-y,x,y,z) ;
    }
    if(z<=l){
        c = memo(l-z,x,y,z) ;
    }
    return dp[l] = max(a,max(b,c))+1 ;
    /*
    Time : O(N)
    space : O(N)
    */
}

//bottom up
int btup(int l,int x,int y,int z){
    int dp[l+1] = {0};
    memset(dp,-1,sizeof(dp)) ;
    dp[0] = 0 ;
    for(int i = 0;i<=l;i++){
        if(x<=i && dp[i-x]!=-1){
           dp[i]= max(dp[i],1+dp[i-x]) ;
        }
        if(y<=i && dp[i-y]!=-1){
            dp[i] = max(dp[i],1+dp[i-y]) ;
        }
        if(z<=i && dp[i-z]!=-1){
            dp[i] = max(dp[i],1+dp[i-z]) ;
        }
        
    }
    if(dp[l]!=-1){
        return 0 ;
    }
    return dp[l] ;
    /*
    Time : O(N)
    space : O(N)
    */

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp,-1,sizeof(dp)) ;
    return 0;
}