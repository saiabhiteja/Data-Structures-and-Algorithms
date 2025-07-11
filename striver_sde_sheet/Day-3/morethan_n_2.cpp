#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
#define nu NULL
/*
    https://takeuforward.org/data-structure/find-the-majority-element-that-occurs-more-than-n-2-times/
*/
int method1(vector<int> nums){
    unordered_map<int ,int> mp ;
    int n = nums.size() ;
    for(int i = 0;i<n;i++){
        mp[nums[i]]++;
    }
    for(auto it: mp){
        if(it.second>(n/2)){
            return it.first ;
        }
    }
    return -1;
    /*
    Time : O(N)
    space : O(N)
    */
}
int method2(vector<int> nums){
    /*
    Boyers mores voting algo
    */
    int n = nums.size() ;
    int ele = -1 ;
    int cnt = 0 ;
    for(int i = 0;i<n;i++){
        if(cnt == 0){
            ele = nums[i] ;
        }
        
        if(nums[i] == ele)cnt++;
        else cnt-- ;
        
    }
    return ele ;
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