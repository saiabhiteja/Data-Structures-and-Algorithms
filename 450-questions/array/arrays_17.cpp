#include <iostream>
#include "bits/stdc++.h"
using namespace std;

/*
Buy sell stock

*/

//brute force 
int method_1(vector<int> A){
    //from index 0 to index n-1  we can buy the stock and after buying
    //only we can sell and we need to find maximum profit from that
    int ans = INT_MIN ;
    int n = A.size() ;
    for(int i = 0;i<n-1;i++){
        for(int j = i+1;j<n;j++){
            ans = max(ans,A[j]-A[i]) ;
        }
    }
    return ans ;
    /*
    Time : O(N^2)
    Space : O(1)
    */
}

int method_2(vector<int> A){
    //as of now problem boils down into finding maximum value to right of particular index
    //so let us find maximum from right side
    int n = A.size();
    int maxi = A[n-1] ;
    vector<int> right_max(n) ;
    for(int i = n-1;i>=0;i--){
        right_max[i] = maxi ;
        maxi = max(maxi,A[i]) ;
    }
    //for finding max profit
    int ans = INT_MIN ;
    for(int i = 0;i<n;i++){
        ans = max(ans,right_max[i]-A[i]) ;
    }
    return ans ;
    /*
    Time : O(N)+O(N)
    Space : O(N)
    */
}
int maxProfit(vector<int>& A) {

        //for every day finding less price and finding maximum profit
        int n = A.size();
        
        int ans = 0;
        
        int min_price = INT_MAX ;
        
        for(int i = 0;i<n;i++){
            
            min_price = min(min_price,A[i]);
            
        ans = max(ans,A[i]-min_price);
        }
        
        return ans ;
        /*
        Time : O(N)
        Space : O(1)
        */
        
    }
int main(){
    vector<int> prices = {7,1,5,3,6,4};
    cout<<maxProfit(prices)<<endl;

    return 0;
}