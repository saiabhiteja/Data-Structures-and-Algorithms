#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*
    partioning givine array into three ranges
*/
void method_1(vector<int>& arr,int a,int b){
    sort(arr.begin(),arr.end()) ;
    /*
    Time : O(NlogN)
    Space : O(1)
    */
}
void method_2(vector<int>& arr,int a,int b){
    //using ducth national flag algo
    int low = 0;
        int high = arr.size()-1;
        int mid = 0;
        while(mid<=high){
            if(arr[mid]<a){
                swap(arr[low++],arr[mid++]);
            }
            else if(arr[mid]>b){
                swap(arr[mid],arr[high--]);
            }
            else{
                mid++;
            }
            
        }
        /*
        Time : O(N)
        SPace : O(1)
        */
}
int main() {
    vector<int> arr = {1,2,3,3,4} ;
    method_2(arr,1,2) ;
    for(int i: arr){
        cout<<i<<" ";
    }
    return 0;
}