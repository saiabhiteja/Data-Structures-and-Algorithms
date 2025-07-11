#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define mat vector<vector<int>>
#define ll long long
/*
    print all paths from top left to bottom right
    https://www.geeksforgeeks.org/print-all-possible-paths-from-top-left-to-bottom-right-of-a-mxn-matrix/
*/
bool isvalid(int i,int j,int n,int m,mat& vis){
    return (i>=0 && j>=0 && i<n && j<m && !vis[i][j]) ;
}
void helper(int i,int j,vec temp,mat& ans,int n,int m,mat& arr,mat& vis){

    if(i == n-1 && j == m-1){
        temp.push_back(arr[i][j]);
        ans.push_back(temp);
        return;
    }

    if(isvalid(i+1,j,n,m,vis)){
        vis[i][j] = 1;
        temp.push_back(arr[i][j]);
        helper(i+1,j,temp,ans,n,m,arr,vis);
        vis[i][j] = 0;
        temp.pop_back();
    }

    if(isvalid(i,j+1,n,m,vis)){
        vis[i][j] = 1;
        temp.push_back(arr[i][j]) ;
        helper(i,j+1,temp,ans,n,m,arr,vis) ;
        vis[i][j] = 0;
        temp.pop_back();
    }
    
    
}
void all_paths(mat arr){
    mat ans ;
    int n = arr.size();
    int m = arr[0].size();
    vector<vector<int>> vis(n,vector<int>(m,0));
    helper(0,0,{},ans,arr.size(),arr[0].size(),arr,vis);
    for(auto it: ans){
        for(auto i: it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    /*
    Time : O(2^n*m)
    space : O(n+m)
    */
}
int main() {
    mat arr = { { 1, 2, 3 },{ 4, 5, 6 },{ 7, 8, 9 } } ;
    all_paths(arr);
    return 0;
}