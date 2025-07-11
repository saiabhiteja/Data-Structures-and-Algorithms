class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int iszero = 0 ;
        int prod = 1 ;
        int n = nums.size() ;
        vector<int> ans(n,0) ;
        for(int i = 0 ;i<n;i++){
            if(nums[i] == 0){
                iszero++ ;
            }
            else{
                prod*=nums[i] ;
            }
        }
        if(iszero>=2)return ans ;
        for(int i = 0 ;i<n;i++){
            if(iszero  && nums[i]!=0){
                continue ;
            }
            else{
                int curr = nums[i] == 0?prod:prod/nums[i] ;
                ans[i] = (curr) ;
            }
        }
        return ans ;
    }
};