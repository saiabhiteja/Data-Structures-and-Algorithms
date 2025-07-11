#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
#define nu NULL
/*
    rotate matrix 
    1. clockwise 90
    2. anti clock wise 90
*/
void rotate(vector<vector<int>>& arr){
    
    int r = arr.size() ;
    int c = arr[0].size() ;

    //finding the transpose of  the given matrix
    for(int i = 0;i<r;i++){
        for(int j = 0;j<i;j++){
            swap(arr[i][j],arr[j][i]) ;
        }
    }

    //for clock wise rotation
    for(int i = 0;i<r;i++){
        reverse(arr[i].begin(),arr[i].end()) ;
    }
    /*
    Time : O(r*c)
    space : O(1) inplace
    */
}

void rotate(vector<vector<int>>& arr){
    
    int r = arr.size() ;
    int c = arr[0].size() ;

    //finding the transpose of  the given matrix
    for(int i = 0;i<r;i++){
        for(int j = 0;j<i;j++){
            swap(arr[i][j],arr[j][i]) ;
        }
    }

    //for anti clock wise rotation
    int first = 0 ,last = c-1 ;
    while(first<last){
        swap(arr[first++],arr[last--]) ;
    }
    /*
    Time : O(r*c)
    space : O(1) inplace
    */
}
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
return 0;
}