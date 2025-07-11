#include <bits/stdc++.h>
using namespace std ;
#define ll long long

/*
https://takeuforward.org/data-structure/allocate-minimum-number-of-pages/
*/

//search space
bool candistribute(vector<int>& nums,ll maxi,int k){
    ll curr = 0 ;
    int cnt = 1 ;
    int n = nums.size() ;
    for(int i = 0;i<n;i++){
        curr+=nums[i] ;
        if(curr>maxi){
            cnt++ ;
            curr = nums[i] ;
        }
    }
    return cnt<=k ;
 }
ll method1(vector<int>& nums,int k){
    ll low = INT_MIN ,high =0 ; 
    for(int i : nums){
        low = max(low,(ll)i) ;
        high+=i ;
    }
    ll ans = -1 ;
    while(low<=high){
        ll mid = low+(high-low)/2 ;
        //here mid says this is maximum amount of pages we will give it each student
        // so now we have to check wether we can give to these students or not
        if(candistribute(nums,mid,k)){
            ans = mid ;
            high = mid-1 ;
        }
        else{
            low = mid+1 ;
        }
    }
    return ans ;

    /*
    Time : O(N*log(sum))
    space : O(1)
    */

}

  

void solve(){
    int n ; 
    cin>>n ;
    vector<int> arr(n,0) ;
    for(int i = 0;i<n;i++){
        cin>>arr[i] ;
    }
    
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