#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
/*
    kth largest elements
    large = min_heap
*/
vec max_k_elements(vec arr,int k){
    sort(arr.begin(),arr.end()) ;
    int n = arr.size() ;
    vec ans ;
    for(int i = n-1;i>=0;i--){
        if(k){
            ans.push_back(arr[i]);
            k--;
        }
        else{
            break;
        }
    }
    return ans ;
    /*
    Time : O(N*logN)
    Space : O(k)
    */
}

vec method_2(vec arr,int k){
    priority_queue<int,vector<int>,greater<int>> pq ;
    int n =arr.size() ;
    for(int i = 0;i<n;i++){
        pq.push(arr[i]) ;
        if(pq.size()>k){
            pq.pop();
        }
    }
    vec ans ;
    while(pq.size()!=0){
        ans.push_back(pq.top()) ;
        pq.pop() ;
    }
    sort(ans.begin(),ans.end(),greater<int>()) ;

    return ans ;

    /*
    Time : O(N*logk) + O(K*logk)
    Space: O(k)
    */


}
int main() {
    vec arr = {12, 5, 787, 1, 23} ;
    vec ans = method_2(arr,2) ;
    for(int i: ans){
        cout<<i<<" ";
    }
    return 0;
}