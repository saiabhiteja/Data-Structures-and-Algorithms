#include <iostream>
#include "bits/stdc++.h"
using namespace std ;

void spiralPrint(vector<vector<int>>& matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    int right,left,top,bottom ;
    //right pointing on last column
    right = cols-1;
    //bottom pointing on last row
    bottom = rows - 1;
    //both top and left points on first row and first column
    top = 0;
    left = 0 ;
    //dir variable decides the direction of elemnets to print 
    //dir = 0 : path is left to right (top row)
    //dir = 1 : path top to bottom (right col)
    //dir = 2 : path right to left (bottom row)
    //dir = 3 : path bottom to top (left col)
    int dir = 0;

    while(left<=right && top<=bottom ){
        if(dir == 0){
            for(int i = left;i<=right;i++){
                cout<<matrix[top][i]<<" ";
            }
            top++ ;

        }
        else if (dir == 1){
            for(int i =top;i<=bottom;i++){
                cout<<matrix[i][right]<<" ";
            }
            right-- ;

        }
        else if (dir==2){
            for(int i = right;i>=left;i--){
                cout<<matrix[bottom][i]<<" ";
            }
            bottom--;

        }
        else if (dir == 3){
            for(int i = bottom;i>=top;i--){
                cout<<matrix[i][left]<<" ";
            }
            left++ ;

        }
        dir = (dir+1)%4 ;
    }

    
}

int main(){
   
    vector<vector<int>> matrix ;
    matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    //output 1,2,3,6,9,8,7,4,5
    spiralPrint(matrix);
    return 0 ;
}