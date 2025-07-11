#include <bits/stdc++.h>
using namespace std ;
#define ll long long

/*
https://takeuforward.org/data-structure/search-element-in-a-rotated-sorted-array/
*/

int piviot(vector<int>& nums){
    int low = 0 ;
    int high = nums.size()-1 ;
    int n = nums.size() ;
    while(low<=high){
        int mid = low+(high-low)/2 ;
        if(mid == 0 && mid == n-1){
            if(mid == 0){
                return nums[0]<nums[1]?0:1 ;
            }
            else{
                return nums[n-1]<nums[n-2]?n-1:n-2 ;
            }
        }
        else{
            int prev = nums[mid-1] ;
            int next = nums[mid+1] ;
            int curr = nums[mid] ;
            if(curr<prev && curr<next){
                return mid ;
            }
            else if(curr>nums[high]){
                low = mid+1 ;
            }
            else{
                high = mid-1 ;
            }
        }
    }
    return -1 ;
}
int bs(vector<int>& nums,int low,int high,int target){
    while(low<=high){
        int mid = low+(high-low)/2 ;
        if(nums[mid] == target){
            return mid ;
        }
        else if(nums[mid]>target){
            high = mid-1 ;
        }
        else{
            low = mid+1 ;
        }
    }
    return -1 ;
}

int method1(vector<int>& nums,int target ){
    int n  = nums.size() ;
    int p = piviot(nums) ;
    if(p == -1 || nums[p] == target){
        return p ;
    }
    int left = bs(nums,0,p-1,target) ;
    int right = bs(nums,p,n-1,target) ;
    if(left == -1)return right ;
    if(right == -1)return left ;
    return -1 ;
    /*
    Time : o(LogN)
    space : O(1)
    */
}

int method2(vector<int>& nums,int target){
    int n = nums.size() ;
    int low = 0 ;
    int high = n-1 ;
    while(low<=high){
        int mid = low+(high-low)/2 ;
        if(nums[mid] == target){
            return mid ;
        }
        if(nums[low] <= nums[mid]  ){
            if(nums[low] <= target && nums[mid]>=target){
                high = mid-1 ;
            }
            else{
                low = mid+1 ;
            }
        }
        else{
            //nums[low]>nums[mid] 
            //checking wether our array bound from
            //mid to high or low to mid
            if(nums[mid]<= target && nums[high]>=target){
                low = mid+1 ;
            }
            else{
                high = mid-1 ;
            }
        }
    }
    return -1 ;
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