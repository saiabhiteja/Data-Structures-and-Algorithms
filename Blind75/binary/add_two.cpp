class Solution {
public:
    int getSum(int a, int b) {
        if(b == 0)return a ;
        if(a == 0)return b ;
        unsigned int c = 0 ;
        while(b){
            c = (a&b) ;
            a = a^b ;
            b = c<<1 ;
        }
        return a ;
    }
};