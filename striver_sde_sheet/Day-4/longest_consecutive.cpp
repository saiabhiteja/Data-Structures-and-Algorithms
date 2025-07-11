#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
#define nu NULL
/*
https://takeuforward.org/data-structure/longest-consecutive-sequence-in-an-array/
*/
int method1(vector<int> nums){
    int ans = INT_MIN ;
    sort(nums.begin(),nums.end()) ;
    int cnt = 1 ;
    int n = nums.size() ;
    int prev = nums[0] ;
    for(int i = 1;i<n;i++){
        if(prev == nums[i]){
            cnt++ ;
        }
        else{
            ans = max(ans,cnt);
            cnt = 1 ;
        }
        prev = nums[i] ;
    }
    return ans == INT_MIN?0:ans;
    /*
    Time : O(NlogN)
    space : O(1)
    */
}

int method2(vector<int> nums){
    int hsh[1001] ;
    memset(hsh,0,sizeof(hsh));
    int n = nums.size();
    for(int i =0;i<n;i++){
        hsh[nums[i]]++;
    }
    int cnt = 0;
    int ans = INT_MIN ;
    for(int i = 0;i<=1000;i++){
        if(hsh[i]){
            cnt++;
        }
        else{
            ans = max(ans,cnt);
            cnt = 1;
        }
        
    }
    return ans ;
    /*
    Time : O(N)
    space :O(N)
    */
}
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
return 0;
}