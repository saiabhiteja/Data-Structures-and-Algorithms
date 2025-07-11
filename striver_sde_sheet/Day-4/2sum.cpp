#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
#define nu NULL
/*
    https://takeuforward.org/data-structure/two-sum-check-if-a-pair-with-given-sum-exists-in-array/
*/
bool method1(vector<int>nums,int target){
    int n = nums.size() ;
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if(nums[i]+nums[j] == target){
                return true;
            }
        }
    }
    return false ;
    /*
    Time : O(N^2)
    space : O(1)
    */
}
bool method2(vector<int> nums,int target){
    sort(nums.begin(),nums.end()) ;
    int i = 0,j = nums.size()-1 ;
    while(i<j){
        int sum = nums[i]+nums[j] ;
        if(sum == target){
            return true ;
        }
        else if(sum>target){
            j-- ;
        } 
        else{
            i++;
        }
    }
    return false ;
    /*
    Time : O(Nlogn)
    space : O(1)
    */
}
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
return 0;
}