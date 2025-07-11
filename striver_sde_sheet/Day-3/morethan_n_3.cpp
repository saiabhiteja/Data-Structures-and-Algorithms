#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
#define nu NULL
/*
https://takeuforward.org/data-structure/majority-elementsn-3-times-find-the-elements-that-appears-more-than-n-3-times-in-the-array/
*/
vector<int> method1(vector<int> nums){
    unordered_map<int,int> mp ;
    int n = nums.size() ;
    vector<int> ans ;
    for(int i = 0;i<n;i++){
        mp[i]++ ;
    }
    for(auto it : mp){
        if(it.second>=(n/3)){
            ans.push_back(it.first) ;
        }
    }
    return ans ;
    /*
    Time : O(N)
    space : O(N)
    */
}
vector<int> method2(vector<int> nums){
    int ele1 = -1,ele2 = -1 ;
    int cnt1 = 0,cnt2 = 0 ;
    int n = nums.size() ;
    for(int i = 0;i<n;i++){
        if(nums[i] == ele1){
            cnt1++ ;
        }
        else if(nums[i] == ele2){
            cnt2++;
        }
        else if(cnt1 == 0){
            ele1 = nums[i] ;
            cnt1 = 1 ;
        }
        else if(cnt2 == 0){
            ele2 = nums[i] ;
            cnt2 = 1 ;
        }
        else{
            cnt1--;
            cnt2--;
        }
    }
    int c1 = 0;
    int c2 = 0;
    for(int i = 0;i<n;i++){
        if(ele1 == nums[i]){
            c1++ ;
        }
        if(ele2 == nums[i]){
            c2++;
        }
    }
    if(c1>(n/3) && c2>(n/3))
    return {ele1,ele2};
    return {} ;
    /*
    Time : O(N)
    space : O(1)
    */
}
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
return 0;
}