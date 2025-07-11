#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*
    finding max area in histogram
*/
vector<int>next_smaller_left(vector<ll> nums){
    //function to return indexes which are next left smaller element
    stack<pair<ll,int>> st ;
    vec ans ;
    int n = nums.size();
    for(int i = 0;i<n;i++){
        if(st.empty()){
            ans.push_back(-1) ;
        }
        else if(st.top().first<nums[i]){
            ans.push_back(st.top().second) ;
        }
        else{
            while(st.size()!=0 && st.top().first>=nums[i]){
                st.pop();
            }
            if(st.size() ==0){
                ans.push_back(-1) ;
            }
            else{
                ans.push_back(st.top().second) ;
            }
        }
        st.push({nums[i],i});
    }
    /*
    Time : O(N)
    Space : O(N)
    */
    return ans ;

}
vector<int> next_smaller_right(vector<ll>nums){
    stack<pair<ll,int>> st ;
    vec ans ;
    int n = nums.size() ;
    for(int i = n-1;i>=0;i--){
        if(st.size()==0){
            ans.push_back(n);
        }
        else if(st.top().first<nums[i]){
            ans.push_back(st.top().second);
        }
        else{
            while(st.size()!=0 && st.top().first>=nums[i]){
                st.pop();
            }
            if(st.size() == 0){
                ans.push_back(n);
            }
            else{
                ans.push_back(st.top().second);
            }
        }
        st.push({nums[i],i});
    }
    reverse(ans.begin(),ans.end());
    return ans ;
    /*
    Time : O(N)
    Space : O(N)
    */

}

ll max_area(vector<ll> heights){
    int n = heights.size() ;
    vec left = next_smaller_left(heights) ;
    vec right = next_smaller_right(heights) ;
    ll ans =  0;
    for(int i = 0;i<n;i++){
        ans = max(ans,heights[i]*((right[i]-left[i]-1)*1LL)) ;
    }
    return ans ;
    /*
    Time : O(N)
    Space : O(N)
    */

}
int main() {
    vector<ll> nums = {6,2,5,4,5,1,6} ;
    cout<<max_area(nums)<<endl;
    return 0 ;
}