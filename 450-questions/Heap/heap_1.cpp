#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
/*
    build heap from given array 
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
 void buildheap(vec& arr){
     int n = arr.size() ;
     int startidx = (n/2)-1 ;
     for(int i = startidx ;i>=0;i--){
         max_heapify(arr,i) ;
     }
     /*
     Time : O(N*logn)
     */
 }

 void display(vec arr){
     for(int i: arr){
         cout<<i<<" ";
     }
     cout<<endl;
 }
int main() {
    vec arr = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17} ;
    display(arr) ;
    buildheap(arr);
    display(arr) ;

    return 0;
}