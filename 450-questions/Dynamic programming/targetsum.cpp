#include <iostream>
using namespace std;
#include "bits/stdc++.h"
int subset(vector<int>nums,int sum){
        int n=nums.size();
        int dp[n+1][sum+1];
        for(int i=0;i<=n;i++)
            dp[i][0]=1;


        for(int j=1;j<=sum;j++)
            dp[0][j]=0;

            
        for(int i=1;i<=n;i++){
            for(int j=0;j<=sum;j++){
                dp[i][j]=dp[i-1][j];
                if(nums[i-1]<=j)
                    dp[i][j]=dp[i][j]+dp[i-1][j-nums[i-1]];
            }
        }
        return dp[n][sum];        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int s=0;
        s=accumulate(nums.begin(),nums.end(),s);
        int p=(target+s)/2;
        if(s < target || (s + target) % 2 != 0)
            return 0;
        return subset(nums,abs(p));   
    }
int main(){
    vector <int> arr = {1,1,1,1,1};
    cout<<findTargetSumWays(arr,3) ;
    return 0 ;


}