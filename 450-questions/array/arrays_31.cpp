#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*
    find minimum size subarray with sum greater than equal to x
*/
int method_1(vector<int> arr,int x){
    int n = arr.size() ;
    int ans = INT_MAX ;
    for(int i = 0;i<n-1;i++){
        int sum = 0;
        for(int j = i;j<n;j++){
            sum+=arr[j] ;
            if(sum>x){
                ans = min(ans,j-i+1);
            }
        }
    }
    return ans ;
    /*
    Time : O(N^2)
    Space : O(1)
    */
}
int method_2(vector<int> arr,int x){
    //using sliding window technique
    //assumpition all elements are postive
    int i = 0,j=0;
    int n = arr.size() ;
    int sum = 0;
    int ans = INT_MAX ;
    while(j<n){
        sum+=arr[j] ;
        if(sum>x){
            while(i<j && sum>x){
    
                if(sum>x){
                    ans = min(ans,j-i+1);
                }
                 sum = sum -arr[i++];
            }
        }
        j++;
    }
    return ans ;
    /*
    Time : O(N)
    Space : O(1)
    */
}
int main() {
    vector<int> arr =  { 1, 4, 45, 6, 10, 19 } ;
    cout<<method_2(arr,51)<<endl;
    return 0;
}