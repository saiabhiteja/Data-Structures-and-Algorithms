#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
#define nu NULL
/*
https://takeuforward.org/data-structure/search-in-a-sorted-2d-matrix/
*/
bool method1(vector<vector<int>> m,int key){
    int r = m.size() ;
    int c = m[0].size() ;
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            if(m[i][j] == key ){
                return true;
            }
        }
    }
    return false ;
    /*
    Time : O(N^2)
    space : O(1)
    */
}
bool method2(mat m,int key){
    int j = m[0].size()-1 ;
    int i = 0;
    int r = m.size() ;
    int c = m[0].size() ;
    while(i>=0 && j>=0 && i<r && j<c){
        if(m[i][j] == key){
            return true;
        }
        else if(m[i][j]<key){
            i++ ;
        }
        else{
            j--;
        }
    }
    return false ;
    /*
    Time : O(r+c)
    space : O(1)
    */
}

bool method3(mat m,int key){
    int r = m.size() ;
    int c = m[0].size() ;
    int low = 0 ;
    int high = r*c -1 ;
    while(low<=high){
        int mid = low+(high-low)/2 ;
        if(m[mid/c][mid%c] == key){
            return true ;
        }
        else if(m[mid/c][mid%c]>key){
            high = mid-1;
        }
        else{
            low = mid+1 ;
        }
    }
    return false ;
    /*
    Time : O(Log(m*n))
    space : O(1)
    */
}
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
return 0;
}