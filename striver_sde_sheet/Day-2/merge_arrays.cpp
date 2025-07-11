#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
#define nu NULL
/*
    merging two sorted arrays without using extra space
    approaches
    1. pushing all elements into one vector and sorting all elements then dividing n and m elements
    2. without using extra space
    As we know that first array contains elements which are first n elements and second array contains last m elements
    so which says all elements in first array should be smaller than first element of second array

*/
void merge(vector<int> arr1,vector<int> arr2){
    int n = arr1.size() ;
    int m = arr2.size() ;
    int i = n-1 ,j =0 ;
    while(i>=0 && j<m){
        if(arr2[j]<arr1[i]){
            swap(arr1[i],arr2[j]) ;
            i--;
            j++;
        }
        else{
            break ;
        }
    }
    sort(arr1.begin(),arr1.end()) ;
    sort(arr2.begin(),arr2.end()) ;
    /*
    Time : o((n1logn1 + n2logn2)
    space : O(1)
    */
}
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
return 0;
}