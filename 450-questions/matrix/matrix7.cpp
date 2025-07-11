#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*
    find a specfic pair in a matrix such that max(mat(c,d)-mat(a,b))
    c>a,d>b 
    https://www.geeksforgeeks.org/find-a-specific-pair-in-matrix/
*/
//brute force

int method_1(vector<vector<int>>mat,int n,int m){

    int ans = INT_MIN ;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){

            for(int k = i+1;k<n;k++){
                for(int l = j+1;l<m;l++){
                    ans = max(ans,mat[k][l]-mat[i][j]);
                }
            }
        }
    }
    /*
    Time : O(N^4)
    Space : O(1)
    */
   return ans ;
}

int method_2(vector<vector<int>>mat,int n,int m){
    int ans = INT_MIN ;
    int maxarr[n][m] ;
    //preprocessing for last row and last column
    int maxval = mat[n-1][m-1] ;
    for(int i = m-2;i>=0;i--){
        if(mat[n-1][i]>maxval){
            maxval = mat[n-1][i];
        }
        maxarr[n-1][i] = maxval;
    }
    maxval = mat[n-1][m-1];
    for(int j = n-2;j>=0;j--){
        if(mat[j][m-1]>maxval){
            maxval = mat[j][m-1];
        }
        maxarr[j][m-1] = maxval ;
    }

    for(int i = n-2;i>=0;i--){
        for(int j = m-2;j>=0;j--){
            ans = max(ans,maxarr[i+1][j+1]-mat[i][j]) ;
            maxarr[i][j] = max(mat[i][j],max(maxarr[i][j+1],maxarr[i+1][j]));
        }
    }
    return ans ;
}
int main() {
    vector<vector<int>> mat ={
                      { 1, 2, -1, -4, -20 },
                      { -8, -3, 4, 2, 1 },
                      { 3, 8, 6, 1, 3 },
                      { -4, -1, 1, 7, -6 },
                      { 0, -4, 10, -5, 1 }
                    };
    cout<<method_1(mat,5,5)<<endl;
    return 0;
}