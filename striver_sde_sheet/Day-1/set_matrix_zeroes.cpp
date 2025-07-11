#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
#define nu NULL
/*
    setting matrix zeroes
    INTIAL APPROACH
    -- one traversal whole matrix get zeroes
    -- push them into queue
    -- make its respective columns and rows to zero


*/

void setZeroes(vector<vector<int>>& arr) {

        queue<pair<int,int>> q ;

        int r = arr.size() ;
        int c = arr[0].size() ;

        for(int i = 0;i<r;i++){
            for(int j = 0;j<c;j++){
                if(arr[i][j] == 0){
                    q.push({i,j}) ;
                }
            }
        }
        
        while(q.size()!=0){
            auto t = q.front() ;q.pop();
            int curr_r = t.first ;
            int curr_c = t.second ;
            for(int i = 0;i<c;i++){
                arr[curr_r][i] = 0;
            }
            for(int i = 0;i<r;i++){
                arr[i][curr_c] = 0 ;
            }
        }
        /*
        Time : O(R*C) + O(size_of_queue*max(r,c)) ~ O(N^2) 
        space : O(N^2)
        */
    }


 void setZeroes(vector<vector<int>>& arr) {
        bool frow = false,fcol = false ;
        //queue<pair<int,int>> q ;
        int r = arr.size() ;
        int c = arr[0].size() ;
        for(int i = 0;i<r;i++){
            for(int j = 0;j<c;j++){
                if(arr[i][j] == 0){
                    if(i == 0)frow = true ;
                    if(j == 0)fcol = true ;
                    arr[i][0] = 0 ;
                    arr[0][j] = 0 ;
                }
            }
        }
        
        for(int i = 1;i<r;i++){
            for(int j = 1;j<c;j++){
                if(arr[i][0] == 0 || arr[0][j] == 0){
                    arr[i][j] = 0 ;
                }
            }
        }
        if(frow){
            for(int i = 0;i<c;i++){
                arr[0][i] = 0;
            }
        }
        if(fcol){
            for(int i = 0;i<r;i++){
                arr[i][0] = 0;
            }
        }

        /*
        Time : O(N^2)
        space : O(1)
        */
}
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
return 0;
}