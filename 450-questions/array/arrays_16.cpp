#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*
    inversion count of an array
*/
int method_1(int arr[],int n){
    int cnt = 0;
    for(int i = 0;i<n-1;i++){
        for(int j = i+1;j<n;j++){
            if(arr[i]>arr[j]){
                cnt++;
            }
        }
    }
    return cnt ;
    /*
    Time : O(N^2)
    Space : O(1)
    */
}
int method_2(int arr[],int n){
    int cnt = 0 ;
    //using multiset
    multiset<int> s1 ;
    for(int i = 0;i<n;i++){
        s1.insert(arr[i]) ;
        cnt+= distance(s1.upper_bound(arr[i]),s1.end()) ;
    }
    return cnt ;
    /*
    Time : O(N^2) //distance = O(N)
    Space : O(N)
    */
}

int merge(int arr[],int low,int mid,int high,int n){

    int temp[n] ;
    int i = low ;
    int j=mid+1;
    //left arr = low to mid-1
    //right arr = mid-high 
    int cnt = 0;
    int k = low ;
    while(i<=mid && j<=high){
        if(arr[i]<=arr[j]){
            temp[k++] = arr[i++] ;
        }
        else if(arr[j]<arr[i]){
            temp[k++] = arr[j++] ;
            cnt+=(mid-i+1) ;
        }
    
    }
    while(i<=mid){
        temp[k++] = arr[i++] ;
    }
    while(j<=high){
        temp[k++] = arr[j++];
    }

    for(int i = low;i<=high;i++){
        arr[i] = temp[i] ;
    }
    return cnt ;
}
int merge_sort(int arr[],int low,int high,int n){
    int cnt = 0;
    if(low<high){
        int mid = (low+high)/2 ;
        cnt+=merge_sort(arr,low,mid,n);
        cnt+=merge_sort(arr,mid+1,high,n) ;
        cnt+=merge(arr,low,mid,high,n) ;
    }
    return cnt ;
}

int method_3(int arr[],int n){
    //using merge sort
    return merge_sort(arr,0,n-1,n) ;
    /*
    Time : O(NlogN)
    Space : O(N)
    */
}

int main() {
    int arr[5] = {5,4,3,2,1} ;
    cout<<method_3(arr,5);
    return 0;
}