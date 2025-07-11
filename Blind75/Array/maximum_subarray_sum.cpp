class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size() ;
        int curr = 0 ;
        int max_so_far = INT_MIN ;
        for(int i = 0;i<n;i++){
            curr+=nums[i] ;
            max_so_far = max(max_so_far,curr) ;
            curr = max(curr,0) ;
        }
        return max_so_far ;
    }
};