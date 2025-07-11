#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
#define nu NULL
/*
    https://takeuforward.org/data-structure/find-the-repeating-and-missing-numbers/
    1. using map
*/
vector<int> method1(vector<int> nums,int n){
    unordered_map<int,int> mp ;
    vector<int> ans(2,0); 
    for(int i: nums){
        if(mp.find(i) != mp.end()){
            ans[0] = i;
        }
        mp[i]++ ;
    }
    for(int i = 1;i<=n;i++){
        if(mp.find(i) == mp.end()){
            ans[1] = i ;
        }
    }
    return ans ;
    /*
    Time : O(N)
    space : O(N)
    */
}

vector<int> method2(vector<int> nums,int n){
    //sort 
    sort(nums.begin(),nums.end()) ;
    vector<int> ans(2,0) ;
    for(int i = 0;i<n-1;i++){
        if(nums[i] == nums[i+1]){
            ans[0] = nums[i] ;
        }
    }
    for(int i = 1;i<=n;i++){
        if(!binary_search(nums.begin(),nums.end(),i)){
            ans[1] = i ;
        }
    }
    return ans ;
    /*
    Time : O(Nlogn)
    Space : O(1)
    */

}

vector<int> method3(vector<int> nums,int n){
    //using formulas
    //sum of n elements
    long sum_n = 0 ,sum_2n = 0 ;
    for(int i = 1;i<=n;i++){
        sum_n+=i ;
        sum_2n+=(i*i) ;
    }
    long sumr_n = 0,sumr_2n = 0 ;
    for(int i :nums){
        sumr_n+=i ;
        sumr_2n+=(i*i) ;
    }
    long y = sum_n-sumr_n ;
    long z = sum_2n -sumr_2n ;
    z = z/y ;
    vector<int> ans(2,0) ;
    ans[0] = (z+y)/2 ;
    ans[1] = (z-y)/2 ;
    return ans ;
    /*
    Time : O(N)
    space : O(1)
    */
}

vector<int> method4(vector<int> nums,int n){
    //using bits
    //xor concepts
    int xor1 = 0 ,x1 =0,x2=0 ;
    for(int i =0 ;i<n;i++){
        xor1 = xor1^nums[i] ;
    }
    for(int i = 1;i<=n;i++){
        xor1 = xor1^i ;
    }
    //right most set bit
    int set_bit_num = xor1&~(xor1-1) ;
    for(int i = 1;i<=n;i++){
        if(set_bit_num & i){
            x1 = x1^i ;
        }
        else{
            x2 = x2^i ;
        }
    }
    for(int i = 0;i<n;i++){
        if(nums[i]&set_bit_num){
            x1 = x1^nums[i] ;
        }
        else{
            x2 = x2^nums[i] ;
        }
    }
    int x_cnt =0 ;
    for(int i = 0;i<n;i++){
        if(nums[i] == x1){
            x_cnt++;
        }
    }
    if(x_cnt) return {x2,x1} ;
    return {x1,x2} ;
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