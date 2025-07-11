#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
#define nu NULL
/*
https://takeuforward.org/data-structure/count-the-number-of-subarrays-with-given-xor-k/
*/
int method1(vector<int> nums,int tar){
    int n = nums.size();
    int cnt = 0;
    for(int i =0 ;i<n;i++){
        int curr_xor = 0 ;
        for(int j = i;j<n;j++){
            curr_xor = curr_xor^nums[i];
            if(curr_xor == tar)cnt++;
        }
    }
    return cnt ;
    /*
    Time : O(N^2)
    space : O(1)
    */
}
int method2(vector<int> nums,int tar){
    int n = nums.size() ;
    unordered_map<int,int>mp ;
    int curr_xor = 0 ;
    int ans = 0 ;
    for(int i = 0;i<n;i++){
        curr_xor = curr_xor^nums[i] ;
        if(curr_xor == tar)ans++;
        if(mp.find(tar^curr_xor)!= mp.end()){
            ans+=mp[tar^curr_xor] ;
        }
        mp[curr_xor]++;
    }
    return ans ;
    /*
    Time : O(N)
    space : O(N)
    */
}
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
return 0;
}