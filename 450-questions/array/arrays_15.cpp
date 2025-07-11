#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*
    find next permutation
*/
// method_1 genrate all permutaions and find next one
vector<int> method_2(vector<int> arr){
    //using stl next_permutation 
    bool isthere = next_permutation(arr.begin(),arr.end()) ;
    return arr ;

}
vector<int> method_3(vector<int>& nums) {
        
        int i = nums.size()-2 ;
        while(i>=0 && nums[i]>=nums[i+1])i--;
        
        if(i == -1){
            sort(nums.begin(),nums.end());
            
        }
        else{
            int j = nums.size()-1;
            while(j>=0 && nums[j]<=nums[i]) j-- ;
            swap(nums[i],nums[j]) ;
            reverse((nums.begin()+(i+1)),nums.end());
        }

        return nums;
        /*
        Time : O(N)
        Space : O(1)
        */
        
    }
int main() {
    vector<int> arr = {5,4,3,2,1} ;
    arr = method_3(arr) ;
    for(int i:arr){
        cout<<i<<" ";
    }
    return 0;
}