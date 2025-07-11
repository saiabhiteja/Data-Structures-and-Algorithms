#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*
    tug of war 
    https://www.geeksforgeeks.org/tug-of-war/
*/
void helper(vec arr,int ind,int size,int cur_sum,int total_sum,int& ans){
    if(ind == arr.size()){
        if(size == (arr.size())/2){
            ans = min(ans ,abs(total_sum-2*cur_sum));
        }
        return ;
    }
    //include
    helper(arr,ind+1,size+1,cur_sum+arr[ind],total_sum,ans);
    //not include
    helper(arr,ind+1,size,cur_sum,total_sum,ans);


}
int min_diff(vector<int> arr){
    int ans = INT_MAX ;
    int sum = 0;
    for(int i : arr){
        sum+=i;
    }
    helper(arr,0,0,0,sum,ans);
    return ans ;
    /*
    Time : O(2^N)
    Space : O(N)
    */
}


int main() {
    vec arr = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4} ;
    cout<<min_diff(arr);
    return 0;
}