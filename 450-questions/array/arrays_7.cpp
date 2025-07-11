#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mod 1e9+7
#define fo(i,n) for(i = 0;i<n;i++)
void display(vec arr){
    int i = 0;
    fo(i,arr.size()){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
/*
    Cyclically rotate an array by one
*/
void method_1(vec arr){
    int x = arr.back();
    arr.pop_back();
    arr.insert(arr.begin(),x) ;
    display(arr);
    /*
    Time : O(N)
    Space : O(1)
    */
}
void method_2(vec arr){
    int x = arr.back() ;
    int i = 0;
    int n = arr.size() ;
    for(int i = n-1;i>0 ;i--){
        arr[i] = arr[i-1] ;
    }
    arr[0] = x;
    display(arr);
    /*
    Time : O(N)
    space : O(1)
    */ 
}
void method_3(vec arr){
    //using reverse concept
    reverse(arr.begin(),arr.end()) ;
    reverse(arr.begin()+1,arr.end()) ;
    display(arr) ;
    /*
    Time : O(N)
    Space : O(1)
    */
}

void method_4(vec arr){
    //using stl rotate ;
    int n = arr.size();
    rotate(arr.begin(),arr.begin()+n-1,arr.end());
    display(arr);
}
int main() {
     vec arr = {1,2,3,4,5,6,7};
     method_4(arr);
return 0;
}