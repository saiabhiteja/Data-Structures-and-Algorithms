#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int median(vector<vector<int>> &matrix, int r, int c){
       vector<int> temp ;
       for(int i = 0;i<matrix.size();i++){
           for(int j = 0;j<matrix[0].size();j++){
               temp.push_back(matrix[i][j]);
           }
       }
       sort(temp.begin(),temp.end());
       return (temp[(r*c)/2]);
       /*
       Time : O(R*C)
       Space : O(R*c)
       */
}
//Given row wise sorted matrix 

int helper(vector<vector<int>>& mat,int row,int key){
    //upper bound
    //finding number of elements which are less than are equal to that val
    int low = 0,high = mat[0].size()-1 ;

    while(low<=high){
        int mid = (low+high)/2 ;
        if(mat[row][mid]<=key){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }

    return low;
}
int methd_2(vector<vector<int>>& mat,int r,int c){
    //i have to find middle  = r*c/2 ;
    //using binary search
    int mini = mat[0][0] ;
    int maxi = mat[r-1][c-1] ;
    //finding minimum ans maximum
    for(int i = 0;i<r;i++){
        mini = min(mat[i][0],mini) ;
        maxi = max(mat[i][c-1],maxi) ;
    }

    while(mini<=maxi){
        int mid = (mini)+(maxi-mini)/2 ;
        //counting number of elements less than or equal to mid
        int cnt = 0;
        for(int i = 0;i<r;i++){
            cnt += helper(mat,i,mid);
        }
        if(cnt <= (r*c)/2){
            mini =mid+1;
        }
        else{
            maxi = mid-1;
        }
    }
    return mini;
    /*
    Time : O(log2(max-min)*r*log2(c))
    space : O(1)
    */
}


int main(){
    vector<vector<int>> arr = {{1,3,5},{2,6,9},{3,6,9}};
    cout<<methd_2(arr,3,3)<<endl;
    return 0;
}