class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = nums.size();
        for(int i = 0;i<nums.size();i++){
            ans = ans^i ;
            ans = ans^nums[i] ;
        }
        return ans ;
    }
};