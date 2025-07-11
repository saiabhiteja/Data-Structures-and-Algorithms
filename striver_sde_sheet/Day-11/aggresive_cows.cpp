#include <bits/stdc++.h>
using namespace std ;
#define ll long long

/*
https://takeuforward.org/data-structure/aggressive-cows-detailed-solution/
*/

//search space
bool candistribute(vector<int>& nums,ll maxi,int k){
    ll cnt = 1 ;
    ll prev = nums[0] ;
    int n = nums.size() ;
    for(int i = 1;i<n;i++){
        if(nums[i]-prev >= (maxi)){
            cnt++;
            prev = nums[i] ;
        }
    }
    return cnt>=k ;
 }
ll method1(vector<int>& nums,int k){
    ll low = INT_MIN ,high =0 ; 
    for(int i : nums){
        low = max(low,(ll)i) ;
        high+=i ;
    }
    ll ans = -1 ;
    int n = nums.size();
   sort(nums.begin(),nums.end());
   ll maxid = nums[n-1]-nums[0];
   ll low = 0 ;
   ll high = maxid ;
   while(low<=high){
        ll mid = low+(high-low)/2 ;
        if(candistribute(nums,mid,k)){
            ans =  mid ;
            high = mid-1 ;
        }
        else{
            low =mid+1 ;
        }
   }
   return ans ;
   /*
   Time : O(nlogn)+ O(n*log(maxid))
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