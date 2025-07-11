#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*
    distribute choclates among m students
*/
long long method_1(vector<int> arr,int m){
    /*
        let us find maximum and minimum of m window size and find minimum value in that difference
    */
   long long ans = LONG_LONG_MAX ;
   sort(arr.begin(),arr.end());
   int n = arr.size() ;
   for(int i = 0;i<(n-m+1);i++){
        ans = min(ans,(long long)arr[m+i-1]-arr[i]) ;
   }
   return ans ;
   /*
   Time : O(NlogN) + O(N-M)
   Space : O(1)
   */
}
int main() {
    vector<int> arr = {3, 4, 1, 9, 56, 7, 9, 12} ;
    cout<<method_1(arr,5);

    return 0;
}