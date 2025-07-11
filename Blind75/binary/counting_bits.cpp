class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans ;
        for(int i = 0;i<=n;i++){
            int curr = i ;
            int ans_ = 0 ;
            while(curr){
                curr = curr&(curr-1) ;
                ans_++ ;
            }
            ans.push_back(ans_) ;
        }
        return ans ;
    }
};

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans(n+1,0) ;
        for(int i = 1;i<=n;i++){
            ans[i] = ans[(i&(i-1))]+1 ;
        }
        return ans ;
    }
};