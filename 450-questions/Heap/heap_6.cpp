#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
/*
    merge k sorted arrays
*/
vec method_1(mat arr){
    vec temp ;
    int r = arr.size() ;
    int c = arr[0].size() ;
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            temp.push_back(arr[i][j]) ;
        }
    }
    sort(temp.begin(),temp.end()) ;
    return temp ;
    /*
    Time : let k = N*M  O(k)+O(k*logk)
    space : O(k)
    */
}
vec method_2(mat arr){
    vec ans ;
    int r = arr.size() ;
    int c = arr[0].size() ;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq ;
    for(int i = 0;i<r;i++){
        pq.push({arr[i][0],{i,0}});
    }

    while(pq.size()!=0){
        auto t = pq.top() ;
        pq.pop() ;
        ans.push_back(t.first) ;
        int x = t.second.second ;
        int r = t.second.first ;
        x++ ;
        if(x<c){
            pq.push({arr[r][x],{r,x}}) ;
        }
    }

    return ans ;
    /*
    Time : O(N*Mlog(M))
    space : O(M)
    */
}
int main() {
    mat arr = {{1,2,3,4},{2,2,3,4},
         {5,5,6,6},{7,8,9,9}} ;
    vec ans = method_2(arr) ;
    for(int i: ans){
        cout<<i<<" ";
    }
    return 0;
}