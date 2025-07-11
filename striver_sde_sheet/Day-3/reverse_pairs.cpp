#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
#define nu NULL
/*
https://takeuforward.org/data-structure/count-reverse-pairs/
*/
int method1(vector<int> nums){
    int cnt = 0 ;
    int n = nums.size() ;
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if(nums[i]>(2*nums[j])){
                cnt++ ;
            }
        }
    }
    return cnt ;
    /*
    Time : O(N^2)
    space : O(1)
    */
}

int merge(vector<int> nums,int low,int mid,int high,int n){
    int i = low ,j = mid+1 ;
    vector<int> temp(n,0) ;
    int k = low ;
    /*
    Here we will count reverse pairs
    */
   int cnt = 0 ;
   for(int i = low;i<=mid;i++){
       while (j <= high && nums[i] > 2 * nums[j]) {
      j++;
    }
        cnt += (j - (mid + 1));
   }
   i = low;
   j = mid+1 ;
    while(i<=mid && j<=high){
        if(nums[i]<=nums[j]){
            temp[k++] = nums[i++] ;
        }
        else{
            temp[k++]=nums[j++] ;
        }
    }
    while(i<=mid){
        temp[k++] = nums[i++] ;
    }

    while(j<=high){
        temp[k++] = nums[j++] ;
    }

    for(int i = low;i<=high;i++){
        nums[i] = temp[i] ;
    }
    return cnt ;
    /*
    Time : O(NlogN)
    space : O(N)
    */
}
int merge_sort(vector<int> nums,int left,int right,int n){
    int cnt = 0 ;
    if(right>left){
        int mid = left+(right-left)/2 ;
        cnt+=(merge_sort(nums,left,mid,n)) ;
        cnt+=(merge_sort(nums,mid+1,right,n)) ;
        cnt+=merge(nums,left,mid,right,n) ;
    }
    return cnt ;
}
int method2(vector<int> nums){
    return merge_sort(nums,0,nums.size()-1,nums.size()) ;

}
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
return 0;
}