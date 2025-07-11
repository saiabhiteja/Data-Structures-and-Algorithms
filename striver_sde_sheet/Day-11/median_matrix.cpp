#include <bits/stdc++.h>
using namespace std ;
#define ll long long

/*
https://www.codingninjas.com/codestudio/problems/873378?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
*/
int count(vector<vector<int>>& arr,int mid){
    int r = arr.size() ;
    int cnt = 0 ;
    for(int i = 0;i<r;i++){
        auto it = upper_bound(arr[i].begin(),arr[i].end(),mid) ;
        cnt+=(it-arr[i].begin()) ;
    }
    return cnt ;
}
int method1(vector<vector<int>>& arr){
    int r = arr.size() ;
    int c = arr[0].size() ;
    int k = r*c ;
    int low = 0 ;
    int high = 100000 ;
    while(low<=high){
        int mid = low+(high-low)/2 ;
        if(count(arr,mid)<=(k/2)){
            low = mid+1 ;
        }
        else{
            high = mid-1 ;
        }
    }
    return low ;

}
void solve(){
    int n ; 
    cin>>n ;
    vector<int> arr(n,0) ;
    for(int i = 0;i<n;i++){
        cin>>arr[i] ;
    }
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
    #endif

    int t ;
    cin>>t ;
    while(t){
        solve() ;
        t--;
    }

    return 0 ;
}