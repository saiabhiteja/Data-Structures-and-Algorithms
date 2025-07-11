#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
/*
    finding kth smallest element and kth largest element
    smallest == maxheap (after sorting return (k-1)index element)
    largest == minheap (after sorting return (n-k-1) index element)

*/
int keth_smallest(vec arr,int k){
    priority_queue<int> pq ;
    for(int i: arr){
        pq.push(i);
        if(pq.size()>k){
            pq.pop();
        }
    }
    return pq.top() ;
    /*
    Time : O(N*logk)
    space : O(k)
    */
}

int kth_largest(vec arr,int k){
    priority_queue<int,vector<int>,greater<int>> pq ;
    for(int i: arr){
        pq.push(i);
        if(pq.size()>k){
            pq.pop();
        }
    }
    return pq.top() ;
    /*
    Time : O(N*logk)
    space : O(k)
    */
}
int main() {
    vec arr = {7, 10, 4, 3, 20, 15} ;
    cout<<kth_largest(arr,2)<<endl ;
    cout<<keth_smallest(arr,2)<<endl;
    return 0;
}