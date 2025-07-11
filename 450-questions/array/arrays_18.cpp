#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*
    finding pairs whose sum is equal to given value
*/
int method_1(int arr[],int n,int k){
    int cnt = 0;
    for(int i = 0;i<n-1;i++){
        for(int j = i+1;j<n;j++){
            if(arr[i] +arr[j] == k){
                cnt++;
            }
        }
    }
    return cnt ;
    /*
    Time : O(N^2)
    Space : O(N)
    */
}
int getPairsCount(int arr[], int n, int k) {
        unordered_map<int,int> mp ;
        int cnt = 0;
        for(int i = 0;i<n;i++){
            if(mp.find(k-arr[i])!=mp.end()){
                cnt+=mp[k-arr[i]];
            }
            mp[arr[i]]++;
        }
        return cnt;
        /*
        Time : O(N)
        Space : O(N)
        */
}
int main() {
/**/
return 0;
}