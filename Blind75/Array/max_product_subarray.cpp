class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0] ;
        int mini = nums[0] ;
        int maxi = nums[0] ;
        int n = nums.size() ;
        for(int i = 1;i<n;i++){
            int ch1 = nums[i]*maxi ;
            int ch2 = nums[i]*mini ;
            mini = min(nums[i],min(ch1,ch2)) ;
            maxi = max(nums[i],max(ch1,ch2)) ;
            ans = max(ans,maxi) ;
        }
        return ans ;
    }
};