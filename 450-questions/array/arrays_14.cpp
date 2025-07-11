#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*
    merging intervals

*/
vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        if(intervals.size() == 0){
            return ans;
        }

        sort(intervals.begin(),intervals.end());

        stack<vector<int>> st;

        st.push(intervals[0]);

        for(int i = 1;i<intervals.size();i++){
            vector<int> temp = st.top();
            if(intervals[i][0]<= temp[1]){
                if(intervals[i][1]>=temp[1]){
                    temp[1] = intervals[i][1];
                }
                st.pop();
                st.push(temp);
                
            }
            else{
                st.push(intervals[i]);  
            }
        }

        while(st.size()!=0){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;

        /*
        Time : O(NlogN)+O(N) + O(N) +O(N)
        Space : O(N)
        */
        
    }
int main() {
    

    return 0;
}