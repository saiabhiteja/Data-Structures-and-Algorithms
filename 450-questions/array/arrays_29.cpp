#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*
    trapping rain water
*/
int method_1(vector<int> arr){
    int n = arr.size() ;
    vector<int>mxl(n) ,mxr(n);
    mxl[0] = arr[0] ;
    for(int i = 1;i<n;i++){
        mxl[i] = arr[i] ;
        if(mxl[i-1]>mxl[i]){
            mxl[i] = mxl[i-1] ;
        }
    }
    mxr[n-1] = arr[n-1] ;
    for(int i = n-2;i>=0;i--){
        mxr[i] = arr[i] ;
        if(mxr[i+1]>mxr[i]){
            mxr[i] = mxr[i+1] ;
        }
    }
    int sum = 0;
    for(int i = 0;i<n;i++){
        sum+=(min(mxl[i],mxr[i])-arr[i]) ;
    }
    return sum ;
    /*
    Time : O(N)+O(N)+O(N)
    SPace: O(N)+O(N)
    */
}

int method_2(vector<int> arr){
    //two pointer approach
    int low = 0;
    int high = arr.size()-1 ;
    int left_max = 0;
    int right_max = 0;
    int ans = 0;
    while(low<=high){
        if(arr[low]<=arr[high]){
            if(arr[low]>left_max){
                left_max = arr[low];
            }
            else{
                ans+=(left_max-arr[low]);
            }
            low++;
        }
        else{

            if(arr[high]>right_max){
                right_max = arr[high];
            }
            else{
                ans+=(right_max-arr[high]);
            }
            high--;

        }
    }
    return ans;
    /*
    Time : O(N)
    Space:O(1)
    */
}
int main() {
    vector<int> arr = {3,0,0,2,0,4} ;
    cout<<method_2(arr)<<endl;

    return 0;
}