#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mod 1e9+7
#define fo(i,n) for(i = 0;i<n;i++)
/*
-- move all negative numbers to front and postive numbers to back---
*/
void display(vec arr){
    int i = 0;
    fo(i,arr.size()){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void method_1(vec& arr){
    sort(arr.begin(),arr.end());
    display(arr);
    /*
    Time : O(NlogN)
    */
}

void method_2(vec arr){
    //using selction sort
    //modification
    //assumption no zeroes
    int i = 0;
    int n = arr.size() ;
    while(i<n && arr[i]>0){
        i++;
    }
    if(i == n){
        return ;//no negative number
    }
    swap(arr[i],arr[0]) ;
    if(n == 2){
        return ;
    }
    i = 1 ;
    int j = i+1 ;
    while(i<n && j<n){
        while(j<n && arr[j]>0){
            j++ ;
        }
        if(j!=n){
            swap(arr[i++],arr[j]);
        }
    }
    display(arr);

    /*
    Time : O(N)
    Space : O(1)
    */

}

void method_3(vec arr){
    //two pointer tecnique
    int low = 0;
    int high = arr.size()-1;
    while(low<=high){
        if(arr[low]<0 && arr[high]<0){
            low++;
        }
        else if(arr[low]>0 && arr[high]>0){
            high--;
        }
        else if (arr[low]>0 && arr[high]<0){
            swap(arr[low++],arr[high--]);
        }
        else{
            //low<0 && high>0
            low++;
            high--;
        }
    }
    display(arr);
    /*
    Time : O(N)
    Space : O(1)
    */
}

int main() {
    vec arr = {1,2,3,4,5,6,7,8,-1,3,-69,-81,-46,-26};
    method_3(arr);
    
return 0;
}