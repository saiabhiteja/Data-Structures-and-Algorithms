#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
/*
    K-th Largest Sum Contiguous Subarray
*/
int method_1(vec arr,int k){
    vec temp ;
    int n = arr.size() ;
    priority_queue<int,vector<int>,greater<int>> pq ;
    for(int i = 0;i<n;i++){
        int sum = 0 ;
        for(int j=i;j<n;j++){
            sum+=arr[j] ;
            pq.push(sum) ;
            if(pq.size()>k){
                pq.pop() ;
            }
        }
    }
    return pq.top() ;
    /*
    Time : O(n*n logk)
    space : O(k)
    */
}
int main() {
    vec arr = { 10, -10, 20, -40 } ;
    cout<<method_1(arr,6)<<endl ;
    return 0;
}