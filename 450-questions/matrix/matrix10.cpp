#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*
    finding common elements in all rows of a given matrix
*/
void common_elelmenrts(vector<vector<int>>& mat,int n,int m){
    //using unordered_map
    unordered_map<int,int> mp ;
    //storing all elements of first row
    for(int i = 0;i<m;i++){
        if(!mp[mat[0][i]]){
            mp[mat[0][i]]++;
        }
    }

    for(int i = 1;i<n;i++){
        for(int j = 0;j<m;j++){
            if(mp[mat[i][j]] == i){
                mp[mat[i][j]] = i+1;
                if(i == n-1 && mp[mat[i][j]] == n){
                    cout<<mat[i][j]<<" ";
                }
            }
        }
    }
    /*
    Time : O(N*M)
    space : O(M)
    */
}
int main() {
    vector<vector<int>> mat ={
        {1, 2, 1, 4, 8},
        {3, 7, 8, 5, 1},
        {8, 7, 7, 3, 1},
        {8, 1, 2, 7, 9},
    };
    common_elelmenrts(mat,4,5);

    return 0;
}