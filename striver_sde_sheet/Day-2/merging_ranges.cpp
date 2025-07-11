#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
#define nu NULL
/*
    merging intervals which are overlapping
    Approach
    1.sorting whole intervals according to first element if first element is equal then with second element 
    2. using stack we will find the overlapping intervals
    3. overlapping condition 
    [low1,high1] [low2,high2] 
    ---> low2 is in between low1 and high1
*/
bool cmp(pair<int,int> p1,pair<int,int> p2){
    if(p1.first == p2.first){
        return p1.second<p2.second ;
    }
    return p1.first<p2.first ;
}
vector<pair<int,int>> merge(vector<pair<int,int>> arr){
    
    //sorting 
    sort(arr.begin(),arr.end(),cmp) ;
    stack<pair<int,int>> st ;
    st.push(arr[0]) ;
    for(int i = 1;i<arr.size();i++){
        auto t = st.top() ;
        if(t.first<=arr[i].second){
            pair<int,int> tmp ;
            tmp.first = t.first ;
            tmp.second = max(arr[i].second,tmp.second) ;
            st.pop() ;
            st.push(tmp) ;
        }
        else{
            st.push(arr[i]) ;
        }
    }
    int n = st.size() ;
    vector<pair<int,int>> ans(n) ;
    int i = n-1;
    while(st.size()!=0){
        ans[i] = st.top() ;
        st.pop() ;
        i--;
    }

    return ans ;
    /*
    Time : O(N*log(N))+O(N)+O(N)
    space : O(N)
    */
}
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
return 0;
}