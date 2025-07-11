#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
#define nu NULL
/*
    https://takeuforward.org/data-structure/count-inversions-in-an-array/
*/
int method1(vector<int> nums){
    int cnt = 0 ;
    int n = nums.size() ;
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if(nums[j]<nums[i]){
                cnt++;
            }
        }
    }
    return cnt ;
    /*
    Time : o(N^2) 
    space : O(1)
    */
}

int merge(vector<int>& nums,vector<int> temp ,int left,int mid,int right){
    int inv_cnt = 0 ;
    int i = left,j = mid,k = left ;
    while((i<=(mid-1)) && (j<=right)){
        if(nums[i]<=nums[j]){
            temp[k++] = nums[i++] ;
        }
        else{
            temp[k++] = nums[j++] ;
            //inversions..
            inv_cnt = inv_cnt + (mid-i) ;
        }
    }

    while(i<=(mid-1)){
        temp[k++] = nums[i++] ;
    }

    while(j<=right){
        temp[k++] = nums[j++] ;
    }

    for(int i = left;i<=right;i++){
        nums[i] = temp[i] ;
    }

    return inv_cnt ;


}
int merge_sort(vector<int>& nums,vector<int> temp,int i,int j){
    int inv_cnt = 0 ;

    if(j>i){
        int mid = (j+i)/2 ;
        inv_cnt+=merge_sort(nums,temp,i,mid) ;
        inv_cnt+=merge_sort(nums,temp,mid+1,j) ;
        inv_cnt+=merge(nums,temp,i,mid+1,j) ;
    }

    return inv_cnt ;
}
int method2(vector<int> nums){
    //using merge sort
    int n = nums.size() ;
    vector<int> temp(n) ;
    return merge_sort(nums,temp,0,n-1) ;
    /*
    Time : O(n*logn)
    space : O(n)
    */
}
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
return 0;
}