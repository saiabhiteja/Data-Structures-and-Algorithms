#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mod 1e9+7
#define fo(i,n) for(i = 0;i<n;i++)
void display(vec arr){
    int i = 0;
    fo(i,arr.size()){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
/*
    maximum sum subarray 
*/
void method_1(vec arr){
    //forming subarrays
    int n = arr.size() ;
    int ans = INT_MIN ;
    for(int i = 0;i<n-1;i++){
        for(int j = i;j<n;j++){
            int sum = 0;
            for(int k = i;k<=j;k++){
                sum+=arr[k] ;
            }
            ans = max(ans,sum);
        }
    }
    cout<<" maximum sum possible is : "<<ans<<endl ;
    /*
    Time : O(N^3)
    Space : O(1)
    */
}
void method_2(vec arr){
    //using subarray formation concept
    int n = arr.size() ;
    int ans = INT_MIN ;
    for(int i = 0;i<n-1;i++){
        int sum = 0;
        for(int j = i;j<n;j++){
            sum += arr[j];
            ans = max(sum,ans);
        }
    }
    cout<<" maximum sum possible is : "<<ans<<endl ;
    /*
    Time : O(N^2)
    space : O(1)
    */

}
void method_3(vec arr){
    //kadanes algorithm
    int n = arr.size();
    int max_so_far = INT_MIN ,max_ending_here = 0 ;//max_so_far maximumvalue
    //max_ending here = current sum 
    for(int i = 0;i<n;i++){
        max_ending_here+=arr[i] ;
        max_so_far = max(max_so_far,max_ending_here) ;
        if(max_ending_here<0){
            max_ending_here = 0;
        }
    }
    cout<<" maximum sum possible is : "<<max_so_far<<endl ;
    /*
    Time : O(N)
    Space : O(1)
    */
}
int main() {
    vec arr = {12,-67,89,-103,45,34,78,-1000} ;
    method_3(arr);
return 0;
}