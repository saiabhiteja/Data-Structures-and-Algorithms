class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curr = prices[0] ;
        int ans = INT_MIN ;
        for(int i = 1;i<prices.size();i++){
            ans = max(ans,prices[i]-curr) ;
            curr = min(curr,prices[i]) ;
        }
        return ans == INT_MIN || ans<0?0:ans ;
    }
};