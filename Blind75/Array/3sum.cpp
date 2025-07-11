class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans ;
        int n = nums.size() ;
        sort(nums.begin(),nums.end()) ;
        int prev ;
        for(int i = 0;i<n;){
            int curr = -nums[i] ;
          
            int j = i+1 ;
            int k = n-1 ;
            while(j<k){
                int sum = nums[j]+nums[k] ;
                if(sum == curr){
                    ans.push_back({nums[i],nums[j],nums[k]}) ;
                    prev = nums[j] ;
                    while(j<k && prev == nums[j])j++;
                    prev = nums[k] ;
                    while(j<k && prev == nums[k])k--;
                }
                else if(sum>curr){
                    k--;
                }
                else{
                    j++;
                }
            }
              prev = nums[i] ;
            while(i<n && prev == nums[i])i++;
        }
        return ans ;
    }
};