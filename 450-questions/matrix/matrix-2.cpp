#include <iostream>
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>&matrix, int target) {
        int i,j;
        
        for(i=0;i<matrix.size();i++)
        {
            int last_col = matrix[i].size() - 1 ;
            int row_max = matrix[i][last_col];
            if(target>row_max){
                continue ;
            }
            else{ 
            for(j=0;j<matrix[i].size();j++)
            {
                if(matrix[i][j]==target)
                {
                    return true;
                }
            }
            }
        }
        return false;
        
    }
};

int main(){
    vector<vector<int>> matrix ;
    matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    Solution s1 ;

    if(s1.searchMatrix(matrix,5)){
        cout<<"Element is there" ;
    }
    else{
        cout<<"No element is there" ;
    }

    return 0 ;
}

