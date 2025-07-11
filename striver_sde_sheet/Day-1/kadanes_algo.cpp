#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
#define nu NULL
/*
    kadanes algo 
    -- for finding maximum sum subarray 
    --genrating all subarrays sum takes o(N^2)
*/
int kadanes(vector<int> arr,int n){
    int max_ending_here = 0;
    int max_so_far = INT_MAX ;
    for(int i = 0;i<n;i++){
        max_ending_here+=arr[i] ;
        max_so_far= max(max_so_far,max_ending_here) ;
        if(max_ending_here<0){
            max_ending_here = 0 ;
        }
    }
    return max_so_far ;
    /*
    Time : O(N)
    space : O(1)
    */
}
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
return 0;
}