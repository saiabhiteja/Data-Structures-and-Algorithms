#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*
    finding row with maximum number of ones
*/
//brute froce
int method_1(vector<vector<int>>& mat,int row,int col){
    int ans = INT_MIN ;
    int ind = -1;
    for(int i = 0;i<row;i++){
        int cnt = 0;
        for(int j = 0;j<col;j++){
            if(mat[i][j] == 1){cnt++;}
        }
        if(ans<cnt){
            ans = cnt;
            ind = i;
        }
    }
    
    return ind ;
    /*
    Time : O(R*c)
    Space : O(1)
    */
}

int helper(vector<vector<int>>& mat,int row,int key){
    int low = 0;
    int high = mat[row].size()-1;
    int ans = -1;
    while(low<=high){
        int mid = (low+high)/2 ;
        if(mat[row][mid] == key){
            ans = mid;
            high = mid-1;
        }
        else if(mat[row][mid]<key){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return ans ;
}

int method_2(vector<vector<int>>& mat,int r,int c){
    //given every row is sorted
    //so we can use binary search
    //find first occurence of 1 
    //count = last_col - first_occ_of_one
    int ans = 0;
    int ind = -1;
    for(int i = 0;i<r;i++){
        int cnt = helper(mat,i,1) ;
        cnt = cnt == -1? 0:c-cnt ;
        if(ans<cnt){
            ans = cnt;
            ind = i;
        }
    }
    return ind;
    /*
    Time : O(r*log(c))
    Space:O(1)
    */
}


int method_3(vector<vector<int>>& mat,int r,int c){
    int ind = -1;
    int left_most_1 = -1 ;
    for(int i = 0;i<c;i++){
        if(mat[0][i] == 1){
            left_most_1 = i;
            ind = 0;
            break;
        }
    }
    left_most_1 = left_most_1 == -1? c:left_most_1 ;
    for(int i = 1;i<r;i++){
        for(int j = 0;j<left_most_1;j++){
            if(mat[i][j] == 1){
                left_most_1 = j ;
                ind = i ;
                break;
            }
        }
    }
    /*
    Time : O(N+M)
    Space : O(1)
    */
    return ind ;
}
int main() {
    vector<vector<int>> arr = {
            {0, 1, 1, 1},
           {0, 0, 1, 1},
           {1, 1, 1, 1},
           {0, 0, 0, 0}} ;

    cout<<method_3(arr,4,4);
    return 0;
}