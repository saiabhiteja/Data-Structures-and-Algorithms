#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*
    combination sum
*/
void helper(int ind,int tar,vector<int>temp,vector<int>arr,vector<vector<int>>& ans){
        if(ind == arr.size()){
            if(tar == 0){
                ans.push_back(temp);
            }
            return;
        }
        if(tar == 0){
            ans.push_back(temp);
            return;
        }
        for(int i = ind;i<arr.size();i++){
            if(arr[i]>tar) break;
            if(arr[i] == arr[i-1] && i!=ind) continue;
            temp.push_back(arr[i]);
            helper(i,tar-arr[i],temp,arr,ans);
            temp.pop_back();
        }
        
    }

vector<vector<int> > combinationSum(vector<int> &A, int tar) {
        //sorting
        sort(A.begin(),A.end());
        vector<vector<int>> ans;
        vector<int> temp;
        helper(0,tar,temp,A,ans);
        return ans;
        /*
        Time : O(N*2^N)
        Space : O(2^N)
        */
    }
int main(){
        vector<int> arr = {2,1,2,1,1};
        vector<vector<int>> ans = combinationSum(arr,4);
    for(auto it : ans){
        for(auto i :it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
        return 0;
}