#include <iostream>
#include "bits/stdc++.h"
using namespace std;
void merge(int arr1[],int arr2[],int arr1_size,int arr2_size){
    /*we have to merge two sorted arrays without using extra space
    let us assume we 5 elments in both arr1 and arr2 so total elements are 10 
    let arr3 = sorted array of (arr1+arr2)
    but we should not use extra space so if we manage to get first 5 smallest elements in arr1 and then next 5 elements in arr2
    we should manipulate arr1 with first 5 smallest elements and arr2 with next 5 elements
    */
   int i1 = arr1_size - 1 ;//arr1 itreator reference
   int i2 = 0 ; //arr2 itreator reference
   while(i1>=0 && i2<arr2_size){
       // base : checking last element of arr1 with first element 
       if(arr1[i1]>arr2[i2]){
           //if arr1[i1] is greater then we have to swap
           swap(arr1[i1],arr2[i2]) ;
       }
       i1 -- ;
       i2++ ;
   }
   sort(arr1,arr1+arr1_size);
   sort(arr2,arr2+arr2_size);
}
int main(){
    int arr1[]={0,2,4,6};
    int arr2[] = {1,3,5,7,9};
    merge(arr1,arr2,4,5);
    for(int i = 0;i<4;i++){
        cout<<arr1[i]<<" ";
    }
    for(int i =0;i<5;i++)
    {
        cout<<arr2[i]<<" ";
    }
    return 0 ;
}
