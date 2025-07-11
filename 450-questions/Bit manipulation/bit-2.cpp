#include <iostream>
#include "bits/stdc++.h"
using namespace std;
vector<int> singleNumber(vector<int> nums) 
    {
        int res = 0;
        for(int i = 0;i<nums.size();i++){
            res = res^nums[i];
        }
        vector<int> ans;
        int a = res;
        int b = res;
        int set_bit = (res)&(~(res-1));
        for(int i =0;i<nums.size();i++){
            if(nums[i] & set_bit){
                a = a^nums[i];
            }
            else{
                b = b^nums[i];
            }
        }
        ans.push_back(a);
        ans.push_back(b);
        sort(ans.begin(),ans.end());
        return ans;
    }

int main(){
    vector<int> arr = {1, 2, 3, 2, 1, 4};
    vector<int> ans = singleNumber(arr);
    cout<<ans[0]<<"  "<<ans[1]<<endl;
    return 0;
}