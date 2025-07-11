#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*
    first negative element in all subarrays of size k
    brute:
    finding all subarrays of size k (o(N^3)) and finding negative element O(N) so total O(N^4) 
    can be optimised to O(N^3)
    //using sliding window
*/
vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int k) {
    
    vector<long long> ans ;
    long long int i=0,j=0;
    queue<long long> q;
    while(j<N){
        if(A[j]<0){
            q.push(A[j]);
        }
        if((j-i+1)<k){
            j++;
        }
        else if((j-i+1)==k){
            if(q.size()==0){
                ans.push_back(0);
            }
            else{
                ans.push_back(q.front());
                if(A[i]==q.front()){
                    q.pop();
                }
            }
            i++;
            j++;
        }
    }
    /*
    Time: O(N)
    Space : O(N)
    */
    return ans;
                 
                                                 
 }
int main() {
    ll arr[5] = {-8, 2, 3, -6, 10} ;
    vector<ll> ans =  printFirstNegativeInteger(arr,5,2) ;
    for(auto i: ans){
        cout<<i<<" ";
    }
    return 0;
}