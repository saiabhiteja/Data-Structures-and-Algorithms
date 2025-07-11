#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*
    rotating matrix of size n*n
*/
//clock wise
void method_1_clock(int arr[3][3],int n){
    //using extra space
    int temp[3][3] ;
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            temp[j][n-i-1] = arr[i][j] ;
        }
    }

    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            arr[i][j] = temp[i][j] ;
        }
    }

    /*
    Time : O(N^2)
    space : O(N^2)
    */

}

void method_2_colck(int arr[3][3],int n){
    //without using extra space
    //finding transpose
    for(int i = 0;i<3;i++){
        for(int j = 0;j<i;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }

    int first ,last ;
    first = 0;
    last = n-1 ;
    while(first<last){
        for(int i = 0;i<n;i++){
        swap(arr[i][first],arr[i][last]) ;
        }
    first++;
    last--;

     }
}


void method_1_anti(int arr[3][3],int n){
    //using extra space
    int temp[n][n] ;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            temp[n-j-1][i] = arr[i][j];
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            arr[i][j] = temp[i][j] ;
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    /*
    Time : O(N*N)
    Space : O(N*N)
    */
}

void method_2_anti(int arr[3][3],int n){
    //without using extra space
    //find transpose
    for(int i = 0;i<n;i++){
        for(int j = 0;j<i;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
    int first ,last ;
    first = 0;
    last = n-1 ;
    while(first<last){
        swap(arr[first],arr[last]) ;
        first++;
        last--;

        }
        /*
        Time : O(N*N)
        Space : O(1)
        */
    }



int main() {

    return 0;
}