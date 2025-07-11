#include <bits/stdc++.h>
using namespace std ;
#define ll long long

/*
https://takeuforward.org/data-structure/search-single-element-in-a-sorted-array/
*/

int method1(vector<int>& nums){
    //only one element is repeating once in given sorted array
    int n = nums.size() ;
    int xor_value = 0 ;
    for(int i = 0;i<n;i++){
        xor_value ^=nums[i] ;
    }
    return xor_value ;
    /*
    Time : O(N)
    space : O(1)
    */
}

int method2(vector<int>& nums){
    int n = nums.size() ;
    int low = 0 ; 
    int high = n-2 ;
    while(low<=high){
        int mid = low+(high-low)/2 ;
        if(mid%2 == 0){
            //mid even index
            if(nums[mid] == nums[mid+1]){
                low = mid+1 ;
            }
            else{
                high = mid-1 ;
            }
        }
        else{
            //mid odd index 
            if(nums[mid] == nums[mid+1]){
                high = mid-1;
            }
            else{
                low = mid+1 ;
            }
        }
    }
    return nums[low] ;
    /*
    Time : O(Log(n))
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
    cout<<method2(arr)<<endl ;

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