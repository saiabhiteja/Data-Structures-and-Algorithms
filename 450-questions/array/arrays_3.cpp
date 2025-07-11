#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mod 1e9+7
/*
    finding kthsmallest and kth largest element in an array
*/
void method_1(vec arr,int k){
    //sorting
    sort(arr.begin(),arr.end()) ;
    //kth maximum
    int n = arr.size() ;
    cout<<"kth maximum : "<<arr[n-k]<<endl;
    cout<<"kth minimum : "<<arr[k-1]<<endl;

    /*
    Time : O(NlogN)
    Space : O(1)
    */

}

void method_2(vec arr,int k){
    //using priority_queue
    //largest -> min heap
    priority_queue<int,vector<int>,greater<int>> pq ;
    int n = arr.size();
    for(int i = 0;i<n;i++){
        pq.push(arr[i]);
        if(pq.size()>k){
            pq.pop();
        }
        
    }
    cout<<"Kth largest element : "<<pq.top()<<endl;

    //smallest -> max heap 
    priority_queue<int> pq_max ;
    for(int i = 0 ;i<n;i++){

        pq_max.push(arr[i]);

        if(pq_max.size()>k){
            pq_max.pop();
        }
    }
    cout<<"Kth smallest element : "<<pq_max.top()<<endl;

    /*
    Time : O(N*logk)
    Space : O(k)
    */
}

int main() {
    vec arr = {12,45,78,12,45,90,77,69,66,26,76,82};

    method_1(arr,2);

    return 0;
}