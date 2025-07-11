#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
#define nu NULL
/*
---finding next permutation
--finding a index from last which cuts descending order condition
--find an element from right which just greater than current element
-- swap it 
--reverse all element s from break point to last so that we get lexicographically small vector 
--Lexicographically small vector means next permutation

// we can also use next_permutation function
in built function

*/
 void nextPermutation(vector<int>& nums) {
       int n = nums.size(), k, l;
    	for (k = n - 2; k >= 0; k--) {
            //finding break point
            if (nums[k] < nums[k + 1]) {
                break;
            }
        }
    	if (k < 0) {
            //which says vector is in descending order
    	    reverse(nums.begin(), nums.end());
    	} else {
    	    for (l = n - 1; l > k; l--) {
                //from last finding an element which is greater than kth indexed element 
                if (nums[l] > nums[k]) {
                    break;
                }
            } 
    	    swap(nums[k], nums[l]);//swapping
            //reversing so that we get lexico graphically small array
    	    reverse(nums.begin() + k + 1, nums.end());
        }
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