#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
#define nu NULL
/*
finding duplicates in n+1 integers
Approaches
1. using map
2. making  negative number
3. using floyds cycle detection algo
*/
int repeated_number(vector<int> arr){
    int n = arr.size() ;
    for(int i = 0;i<n;i++){
        if(arr[abs(arr[i])-1] > 0){
            arr[abs(arr[i])-1] *=(-1) ;
        }
        else{
            return arr[i] ;
        }
    }
    return -1 ;
}

int method_2(vector<int> nums){
    int slow = nums[0],fast = nums[0] ;
    //int n = arr.size() ;
    do {
    slow = nums[slow];
    fast = nums[nums[fast]];
     } 
     while (slow != fast);
    fast = nums[0];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
     }
    return slow;
}
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
return 0;
}