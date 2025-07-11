#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*
    next smaller element to the right
*/
vector<int> method_1(vec nums){
    vec ans ;
    int n = nums.size();
    for(int i = 0;i<n;i++){
        int curr = nums[i] ;
        for(int j = i+1;j<n;j++){
            if(nums[j]<curr){
                curr = nums[j];
                break ;
            }
        }
        if(curr == nums[i]){
            ans.push_back(-1);
        }
        else{
            ans.push_back(curr) ;
        }
    }
    return ans ;
    /*
    Time : O(N^2)
    Space : O(1)
    */
}
vector<int> method_2(vector<int> nums){
    vec ans ;
    stack<int> st ;
    int n = nums.size() ;
    for(int i = n-1;i>=0;i--){
        if(st.size() == 0){
            ans.push_back(-1);
        }
        else if(st.top()<nums[i]){
            ans.push_back(st.top());
        }
        else{
            while(st.size()!=0 && st.top()>=nums[i]){
                st.pop();
            }
            if(st.size() == 0){
                ans.push_back(-1);
            }
            else{
                ans.push_back(st.top());
            }
        }
        st.push(nums[i]);
    }
    reverse(ans.begin(),ans.end());
    return ans ;
    /*
    Time : O(N)
    Space : O(N)
    */
}
int main() {
    vec nums = {4, 8, 5, 2, 25} ;
    vec ans = method_2(nums) ;
    for(int i: ans){
        cout<<i<<" ";
    }
    return 0;
}