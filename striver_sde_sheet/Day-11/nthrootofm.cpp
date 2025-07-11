#include <bits/stdc++.h>
using namespace std ;
#define ll long long

/*
https://takeuforward.org/data-structure/nth-root-of-a-number-using-binary-search/
*/
ll get(ll mid,ll power){
    ll ans = 1 ;
    for(int i = 0;i<power;i++){
        ans*=(mid) ;
    }
    return ans ;
}

ll binary_exponentaion(ll num,ll power){
    ll ans = 1 ;
    while(power>0){
            if(power&1){
                ans = ans*num ;
            }
        num = num*num ;
        power>>=1 ;
    }
    return ans ;
    /*
    Time log(power)
    */
}
ll bs(ll num,ll power){
    ll low = 1 ;
    ll high = num ;
    while(low<=high){
        ll mid = low+(high-low)/2 ;
        ll ans = binary_exponentaion(mid,power) ;
        if(ans == num){
            return mid ;
        }
        else if(ans>num){
            high = mid-1 ;
        }
        else{
            low = mid+1 ;
        }
    }
    return -1 ;
    /*
    Time : O(power*log(num))[using get function]
    Time : O(log(power)*log(num))[using binary exponetation]
    space : O(1)
    */
}
void solve(){
    ll n,num ;
    cin>>n>>num ;

    cout<<bs(num,n)<<endl ;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
    #endif

    int t ;
    cin>>t ;
    while(t){
        solve() ;
        t--;
    }

    return 0 ;
}