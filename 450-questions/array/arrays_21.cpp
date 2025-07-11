#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*
    find wether we have a subarray of sum = 0 
*/
//method1 we can find all subarrays sum if we find we can return true
bool method_1(int arr[],int n){
    for(int i = 0;i<n-1;i++){
        int sum = 0;
        for(int j = i;j<n;j++){
            sum+=arr[j] ;
            if(sum == 0){
                return true;
            }
        }
    }
    return false;
    /*
    Time : O(N^2)
    Space : O(1)
    */
}
bool subArrayExists(int arr[], int n)
    {
        int sum = 0;
        unordered_map<int,int>mp ;
        for(int i=0;i<n;i++){
            sum = sum+arr[i];
            if(sum==0 || mp.find(sum)!=mp.end()){
                return true;
            }
            mp[sum]++;
            
        }
        return false;
        /*
        Time : O(N)
        Space : O(N)
        */
    }
int main() {
    int arr[5] = {4, 2, -3, 1, 6} ;
    if(method_1(arr,5)){
        cout<<"Yes"<<endl ;
    }
    else{
        cout<<"No"<<endl;
    }

    return 0;
}