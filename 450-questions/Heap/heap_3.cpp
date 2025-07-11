#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
/*
    Sliding Window Maximum (Maximum of all subarrays of size k)
    https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/
*/
vec max_of_k(vec arr,int k){
    //using deque
    int i = 0,j = 0,n = arr.size() ;
    deque<int> dq ;
    vec ans ;
    while(j<n){

        while(dq.size()!=0 && dq.back()<=arr[j]){
            dq.pop_back();
        }

        dq.push_back(arr[j]);

        if((j-i+1) == k){
            ans.push_back(dq.front()) ;
            if(dq.front() == arr[i]) {
                dq.pop_front() ;
            }
            i++;
        }
        j++;
    }
    return ans ;
    /*
    Time : O(N)
    Space : O(N)
    */
}

vec method_2(vec arr, int k){
    //using priority_queue
    priority_queue<pair<int,int>> pq ;
    int i = 0,j= 0,n = arr.size();
    vec ans ;
    while(j<n){
        pq.push({arr[j],j}) ;
        if((j-i+1) == k){
            ans.push_back(pq.top().first) ;
            //poping
            while(pq.size()!=0 && pq.top().second<=i){
                pq.pop();
            }
            i++;
        }
        j++;
    }
    return ans ;
    /*
    Time : O(N*logN)
    Space : O(N)
    */
}
int main() {
    vec arr = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13} ;
    vec ans = method_2(arr,4) ;
    for(int i : ans){
        cout<<i<<" ";
    }
    return 0;
}