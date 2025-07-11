class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0,i=0;
        while(n!=0){
            int x = n&1;
            if(x==1){
                x = x<<(31-i);
                ans = ans|x;
            }
            i++;
            n=n>>1;
        }
        return ans;
    }
};