#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*
    finding next greater element to the right
    //standard
*/
vector<int> method_1(vector<int> nums){
    //brute force
    vector<int> ans ;
    int n = nums.size() ;
    for(int i = 0;i<n;i++){
        int curr = nums[i] ;
        for(int j = i+1;j<n;j++){
            if(nums[j]>curr){
                curr = nums[j];
                break ;
            }
        }
        if(curr == nums[i]){
            ans.push_back(-1);
        }
        else{
            ans.push_back(curr);
        }
    }
    return ans ;
    /*
    Time :O(N^2)
    Space : O(1)
    */
}
vector<int> next_greater_right(vector<int> nums){
    vector<int> ans ;
    stack<int> st ;
    int n = nums.size();
    for(int i = n-1;i>=0;i--){
        if(st.size() == 0){
            ans.push_back(-1);
        }
        else if(st.top()>nums[i]){
            ans.push_back(st.top());
        }
        else{
            while(st.size()!=0 && st.top()<nums[i]){
                st.pop();
            }
            if(st.empty()){
                ans.push_back(-1);
            }
            else{
                ans.push_back(st.top()) ;
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

    vector<int> nums = {6 ,8 ,0 ,1 ,3} ;
    vec ans = next_greater_right(nums) ;

    for(int i : ans){
        cout<<i<<" ";
    }

    return 0;
}