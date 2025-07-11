#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
#define nu NULL
/*
https://takeuforward.org/data-structure/length-of-the-longest-subarray-with-zero-sum/
*/
int method1(vector<int> nums){
    int ans = INT_MIN ;
    int n = nums.size();
    for(int i =0;i<n;i++){
        int sum = 0;
        for(int j = i ; j<n;j++){
            sum+=nums[j];
            if(sum == 0)ans = max(ans,j-i+1);
        }
    }
    return ans==INT_MIN?0:ans ;
    /*
    Time : O(N^2)
    space: O(1)
    */
}

int method2(vector<int> nums){
    unordered_map<int,int> mp ;
    int curr_sum = 0;
    int n = nums.size() ;
    int ans = INT_MIN ;
    for(int i = 0;i<n;i++){
        curr_sum +=nums[i] ;
        if(curr_sum == 0){
            ans = max(ans,i+1) ;
        }
        else{
            if(mp.find(curr_sum)!= mp.end()){
                ans = max(ans,i-mp[curr_sum]);
            }
            else{
                mp[curr_sum] = i;
            }

        }

    }
    return ans == INT_MIN?0:ans ;
    /*
    Time :O(N)
    space :O(N)
    */
}
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
return 0;
}