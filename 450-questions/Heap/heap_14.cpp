#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
/*
    connecting n ropes
*/
long long minCost(long long arr[], long long n) {
       long long cost = 0;
     priority_queue <long long, vector<long long >, greater<long long> > pq;
     for(long long i = 0;i<n;i++){
         pq.push(arr[i]);
     }
     while(pq.size()!=1){
         long long x = pq.top();
         pq.pop();
         long long y = pq.top();
         pq.pop();
         cost = cost+ x + y;
         pq.push(x+y);
     }
     
     return cost;
     /*
     Time : O(nlogn)
     Space : O(n)
     */
 }
int main() {

    return 0;
}