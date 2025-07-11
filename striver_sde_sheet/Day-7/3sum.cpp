#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
#define nu NULL
/*
https://takeuforward.org/data-structure/3-sum-find-triplets-that-add-up-to-a-zero/
*/
bool method1(vector<int> arr){
    int n = arr.size() ;
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            for(int k = j+1;k<n;k++){
                if(arr[i]+arr[j]+arr[k] == 0){
                    return true ;
                }
            }
        }
    }
    return false ;
    /*
    Time : O(N^3)
    space : O(1)
    */
}

bool method2(vector<int> arr){
    sort(arr.begin(),arr.end()) ;
    int n = arr.size()-1 ;
    for(int i = 0;i<n;i++){
        int j = i+1 ;
        int k = n-1 ;
        while(j<k){
            int sum = arr[i]+arr[j]+arr[k] ;
            if(sum == 0){
                return true ;
            }
            else if(sum>0){
                k--;
            }
            else{
                j++ ;
            }
        }
    }
    return false ;
    /*
    Time : O(N^2)+O(Nlogn)
    space : O(1)
    */
}
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
return 0;
}