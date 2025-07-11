#include <bits/stdc++.h>
using namespace std ;
#define ll long long

/*
https://takeuforward.org/data-structure/k-th-element-of-two-sorted-arrays/
*/

//finding kth element in merged array
int method1(vector<int>& nums1,vector<int>& nums2,int k){
    int n = nums1.size() ;
    int m = nums2.size() ;
    if(n>m){
        swap(nums1,nums2) ;
        swap(n,m) ;
    }
    int low = 0 ;
    int high = n ;
    while(low<=high){
        int mid = low+(high-low)/2 ;
        int mid2 = k-mid ;
        int left1 = mid == 0?INT_MIN:nums1[mid] ;
        int right1 = mid == n?INT_MAX:nums1[mid+1] ;
        int left2 = mid2 == 0?INT_MIN:nums2[mid2] ;
        int right2 = mid2 == m?INT_MAX:nums2[mid2+1];

        if(left1<=right2 && left2<=right1){
            return max(left1,left2) ;
        }
        else if(left1>right2){
            high = mid-1 ;
        }
        else{
            low = mid+1 ;
        }
    }
    return -1 ;
    /*
    Time : O(LogN)
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