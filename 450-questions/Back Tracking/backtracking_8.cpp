#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*
    find wether we can partion given array into two equal subsets
*/
//finding subsets sum 
bool helper(vector<int> arr,int ind,int curr_set,int target){
    if(ind == arr.size()){
        if(curr_set == target){
            return true;
        }
        return false;
    }

    //include 
    bool include = helper(arr,ind+1,curr_set+arr[ind],target);
    //not include
    bool not_include = helper(arr,ind+1,curr_set,target);

    return (include || not_include);
}
bool can_partion(vector<int> arr){
    int sum = 0;
    for(int i:arr){
        sum+=i;
    }
    if(sum%2){ //if odd
        return false;
    }
    int target = sum/2;
    return (helper(arr,0,0,target));
    /*
    Time : O(2^N)
    Space : O(N)
    */

}
int main() {
    vector<int> arr = {1,5,11,5};
    if(can_partion(arr)){
        cout<<"can be partioned"<<endl;
    }
    else{
        cout<<"can not be partioned"<<endl;
    }
return 0;
}