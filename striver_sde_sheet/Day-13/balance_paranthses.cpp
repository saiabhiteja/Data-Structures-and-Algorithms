#include <bits/stdc++.h>
using namespace std ;
#define ll long long

/*
https://takeuforward.org/data-structure/check-for-balanced-parentheses/
*/
bool check(string s){
    stack<char> st ;
    vector<char> open = {'(','{','['} ;
    vector<char> close = {')','}',']'} ;
    for(int i = 0 ;i<s.size();i++){
        if(s[i] == open[0] || s[i] == open[1] || s[i] == open[2]){
            st.push(s[i]) ;
        }
        else{
            if(s[i] == close[0] && st.size() && st.top()!=open[0])return false;
            if(s[i] == close[1] && st.size() && st.top()!=open[1])return false;
            if(s[i] == close[2] && st.size() && st.top()!=open[2])return false;
            st.pop() ;
        }
    }
    return st.size() == 0;
    /*
    Time : O(N)
    space : O(N)
    */
}
void solve(){
    int n ; 
    cin>>n ;
    vector<int> arr(n,0) ;
    for(int i = 0;i<n;i++){
        cin>>arr[i] ;
    }
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
    #endif

    int t ;
    cin>>t ;
    while(t){
        solve() ;
        t--;
    }

    return 0 ;
}