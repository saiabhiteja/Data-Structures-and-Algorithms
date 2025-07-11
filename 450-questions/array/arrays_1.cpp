#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
/*
    ---Reversing an array ----
*/
void reverse_1(int arr[10]){
    int temp[10] = {0};
    for(int i = 0;i<10;i++){
        temp[10-i-1] = arr[i] ;
    }
    for(int i = 0;i<10;i++){
        arr[i] = temp[i] ;
    }
    /*
    Time : O(N)
    Space : O(N)
    */
}
void display(int arr[10]){
    for(int i = 0;i<10;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void reverse_2(int arr[10]){
    int first = 0;
    int last = 10-1 ;//last index
    while(first<=last){
        int temp = arr[first] ;
        arr[first] = arr[last] ;
        arr[last] = temp ;
        first++;
        last--;
    }
    /*
    Time : O(N)
    Space : O(1)
    */
}
int main() {

    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    display(arr);
    reverse_1(arr);
    display(arr);
    reverse_2(arr);
    display(arr);
    //stl
    reverse(arr,arr+10);
    display(arr);

    return 0;
}