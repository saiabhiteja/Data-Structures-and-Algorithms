#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
/*
    sorting an array of 0,1,2
*/
void method_1(vector<int>& arr){
    sort(arr.begin(),arr.end());
    /*
    Time : O(N*logN)
    */
}
void method_2(vec& arr){
    int zero = 0,one =0,two =0;
    int n = arr.size();
    for(int i = 0;i<n;i++){
        if(arr[i] == 0){
            zero++;
        }
        else if(arr[i] == 1){
            one++;
        }
        else{
            two++;
        }
    }

    for(int i = 0;i<n;i++){
        if(zero){
            arr[i] = 0;
            zero--;
        }
        else if(one){
            arr[i] = 1;
            one--;
        }
        else{
            arr[i] = 2 ;
            two--;
        }

    }

    /*
    Time : O(N)
    Space : O(1)
    */

}

void method_3(vec& arr){
    //ducth national flag algo
    int low = 0;
    int mid = 0;
    int high = arr.size()-1;
    while(mid<=high){
        if(arr[mid] == 0){
            swap(arr[low++],arr[mid++]) ;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[high--],arr[mid]);
        }

    }
    /*
    Time : O(N)
    Space : O(1)
    */
}
void display(vec arr){
    for(int i:arr){
        cout<<i<<" ";
    }
    cout<<endl;
}
int main() {

    vec arr = {0,2,2,1,0,1,2,0,1,0,2};
    method_3(arr);
    display(arr);


    return 0;
}