#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
#define nu NULL
/*
    https://takeuforward.org/data-structure/implement-powxn-x-raised-to-the-power-n/
*/
ll method1(ll x,ll n){
    ll ans = 1;
    for(int i = 0;i<n;i++){
        ans =ans*x ;
    }
    return ans ;
    /*
    Time : O(n)
    space : O(1)
    */
}

ll method2(ll x,ll n){
    bool isneg = false ;
    if(n<0)isneg = true ;
    n = abs(n) ;
    ll ans = 1;
    while(n>0){
        if(n&1){
            ans = ans*x ;
        }
        x = x*x ;
        n = n/2 ;
    }
    if(isneg){return 1/(ans);}
    return ans ;
    /*
    Time : O(logn)
    space : O(1)
    */
}
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
return 0;
}