#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
#define nu NULL
/*
https://takeuforward.org/data-structure/4-sum-find-quads-that-add-up-to-a-target-value/
*/
int method1(vector<int> nums,int target){
    int n = nums.size() ;
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            for(int k = j+1;k<n;k++){
                for(int l = k+1;l<n;l++){
                    if(nums[i]+nums[j]+nums[k]+nums[l] == target){
                        return true ;
                    }
                }
            }
        }
    }
    return false ;
    /*
    Time : O(N^4)
    space : O(1)
    */
}
int method2(vector<int> nums,int target){
    sort(nums.begin(),nums.end()) ;
    int n = nums.size() ;
    for(int i = 0;i<n;i++){
        int sum = 0 ;
        sum+=nums[i];
        for(int j = i+1;j<n;j++){
            sum+=nums[j];
            int k = j+1 ;
            int l = n-1 ;
            while(k<l){
                sum+=(nums[k]+nums[l]) ;
                if(sum == target) return true ;
                else if(sum>target){
                    l--;
                }
                else{
                    k++ ;
                }
            }
        }
    }
    return false ;
    /*
    Time  : O(N^3)
    space : O(1)
    */
}
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
return 0;
}