#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*
    print elements in sorted order from row column wise sorted matrix
*/
vector<int> method_1(vector<vector<int>>& mat,int r,int c){
    vector<int> temp ;
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            temp.push_back(mat[i][j]);
        }
    }
    sort(temp.begin(),temp.end());
    return temp ;
    /*
    Time : O((m*n)log(m*n))
    space : O(n*m)
    */
}

int main() {
    vector<vector<int>> mat = { {10, 20, 30, 40},
                     {15, 25, 35, 45},
                     {27, 29, 37, 48},
                     {32, 33, 39, 50},
                   };
    vector<int> ans = method_1(mat,4,4);
    for(auto it : ans){
        cout<<it<<" ";
    }

    return 0;
}