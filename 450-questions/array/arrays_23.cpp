#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*
    finding maximum product subarray
*/
//if array doesnot contains negative elements then whole product would be maximum
long long method_1(vector<int> arr){
    //finding all sub arrays and finding max product 
    //and return maximum
    long long ans = INT_MIN ;
    int n = arr.size() ;
    if(n == 1){
        return (long long)arr[0] ;
    }

    for(int i = 0;i<n-1;i++){
        long long curr = 1 ;
        for(int j = i;j<n;j++){
            curr *=arr[j] ;
            ans = max(ans,curr) ;
        }
    }
    
    return ans ;
    /*
    Time : O(N^2)
    Space : O(1)
    */
}

long long method_2(vector<int> arr){
    long long ans ;
    int n = arr.size() ;
    if(n == 1){
        return (long long) arr[0] ;
    }
    //same as kadanes algo
    //we have to carry max and min values for all indexes
    long long max_curr_pro = arr[0] ;
    long long min_curr_pro = arr[0] ;
    ans = arr[0] ;
    for(int i = 1;i<n;i++){
        long long curr_1 = max_curr_pro*arr[i] ;
        long long curr_2 = min_curr_pro*arr[i] ;

        max_curr_pro = max(curr_2,max(curr_1,(long long)arr[i])) ;
        min_curr_pro = min(curr_1,min(curr_2,(long long)arr[i])) ;

        ans = max(ans,max_curr_pro) ;
    } 
    return ans ;
    /*
    Time : O(N)
    Space : O(1)
    */
}
int main() {
    vector<int> arr = {6, -3, -10, 0, 2} ;
    cout<<method_2(arr)<<endl;
    return 0;
}