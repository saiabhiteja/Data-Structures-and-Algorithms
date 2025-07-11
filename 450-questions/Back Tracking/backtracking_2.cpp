#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9
#define vec vector<int>
#define pp pair<int,int>
/*
    n queen problem
*/
bool isvalid(vector<vec>& brd ,int col,int row,int n){

    int curr_row = row,curr_col = col ;
     //row wise check
     while(row>=0 && col>=0){
         if(brd[row][col] == 1){
             return false ;
         }
         col-- ;
     }

     //left upper diagonal
     col = curr_col ;
     row = curr_row ;
     while(row>=0 && col>=0){
         if(brd[row][col] == 1){
             return false ;
         }
         row--;
         col--;
     }
    
    //left down diagonal
    col = curr_col ;
    row = curr_row ;

    while(col>=0 && row>=0 && row<n){
        if(brd[row][col] == 1){
            return false ;
        }
        row++;
        col--;
    } 
    return true ;

}
void helper(int col , int n ,vector<int> temp ,vector<vector<int>>& ans,vector<vec>& brd){
    if(col == n){
        ans.push_back(temp) ;
        return  ;
    }
    for(int row = 0;row<n;row++){
        if(isvalid(brd,col,row,n)){
            brd[row][col] = 1 ;
            temp.push_back(row+1) ;
            helper(col+1,n,temp,ans,brd) ;
            temp.pop_back();
            brd[row][col] = 0;
        }
    }
}


vector<vector<int>> nQueen(int n) {
    vector<vec> ans ;
    vector<vector<int>> brd(n,vector<int>(n,0)) ;
    vector<int> temp ;
    helper(0,n,temp,ans,brd);
    return ans ;

    /*
    Time : O(n^n)
    Space : O(N^2)
    */

}

//optimisation of isvalid function
bool isvalid_2(int row,int col,vec row_check,vec upper,vec lower,int n){
    return (!row_check[row] && !upper[n+col-row-1] && !lower[row+col]) ;

}
void helper_2(int col,int n,vector<int> temp ,vector<vec>& ans,vector<vec>&brd ,vec & upper,vec&lower,vec& row_check){

    if(col == n){
        ans.push_back(temp) ;
        return ;
    }
    for(int row = 0;row<4;row++){
        if(isvalid_2(row,col,row_check,upper,lower,n)){
            row_check[row] = 1 ;
            upper[n+col-row-1] = 1 ;
            brd[row][col] = 1 ;
            lower[row+col] = 1 ;
            temp.push_back(row+1);
            helper_2(col+1,n,temp,ans,brd,upper,lower,row_check);
            row_check[row] = 0;
            upper[n+col-row-1] = 0 ;
            brd[row][col] = 0 ;
            lower[row+col] = 0 ;
            temp.pop_back();

        }
    }

}
vector<vector<int>> nQueen_2(int n) {
    vector<vec> ans ;
    vector<vector<int>> brd(n,vector<int>(n,0)) ;
    vector<int> temp ;
    vector<int> row_check(n,0) ;
    vector<int> upper_diagonal(2*n-1,0);
    vector<int> lower_diagonal(2*n-1,0);
    helper_2(0,n,temp,ans,brd,upper_diagonal,lower_diagonal,row_check);
    return ans ;

    

}
int main() {
    vector<vec> ans = nQueen_2(4) ;
    for(auto it : ans){
        for(auto i: it){
            cout<<i<<" ";
        }
        cout<<endl;
    }

    return 0;
}