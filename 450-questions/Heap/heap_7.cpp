#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
/*
    Merge two binary Max heaps 
    https://practice.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1
*/
void max_heapify(vec& arr,int ind){
    int large = ind ;
    int left = 2*ind+1 ;
    int right = 2*ind+2 ;
    int n = arr.size() ;
    if(left<n && arr[left]>arr[large]){
        large = left ;
    }
    if(right<n && arr[right]>arr[large]){ 
        large = right ;
    }


    if(large != ind){
        swap(arr[large],arr[ind]) ;
        max_heapify(arr,large) ;
    }
    /*
    same for min heap as well just changing operators 
    Time : O(logn)
    */
 }

 vec merger(vec arr1,vec arr2){
     vec ans ;
     for(int i: arr1){
         ans.push_back(i) ;
     }
     for(int i: arr2){
         ans.push_back(i) ;
     }
     int n = ans.size() ;
     int startidx = (n/2)-1 ;
     for(int i = startidx;i>=0;i--){
         max_heapify(ans,i) ;
     }
     return ans ;
     /*
     Time : O((n+m)log(n+m)) + O(n) + o(m)
     space : O(n+m)
     */
 }

 

int main() {
    vec arr1 = {10, 5, 6, 2} ;
    vec arr2 = {12, 7, 9} ;
    vec ans = merger(arr1,arr2) ;
    for(int i: ans){
        cout<<i<<" ";
    }
    return 0;
}