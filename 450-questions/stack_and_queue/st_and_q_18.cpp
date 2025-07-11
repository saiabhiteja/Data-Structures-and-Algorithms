#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*
    valid substring
    https://practice.geeksforgeeks.org/problems/valid-substring0624/1
*/
int method_1(string s){
    //using single stack
    stack<int> st ;
        st.push(-1) ; //for getting length of substring
        int ans = 0;
        int n = s.size() ;
        for(int i = 0;i<n;i++){
            if(s[i] == '('){
                st.push(i);
            }
            else{
                st.pop() ;
                if(st.empty()){
                    st.push(i) ;
                }
                else{
                    ans = max(ans,i-st.top()) ;
                }
            }
        }
        return ans ;
        /*
        Time : O(N)
        Space : O(N)
        */
}
int method_2(string s){
    //two passes
        int ans = 0 ;
        int open = 0;
        int close = 0;
        for(int i = 0;i<s.length();i++){
            if(s[i] == '(') {
                open++;
            }
            else if(s[i] == ')'){
                close++;
            }
            
            if(open == close){
                ans = max(ans,2*open);
            }
            
            if(close>open){
                close = 0;
                open = 0;
            }
            
        }
        
        close = 0;
        open = 0;
        for(int i = s.length()-1;i>=0;i--){
            if(s[i] == '(') {
                open++;
            }
            else if(s[i] == ')'){
                close++;
            }
            
            if(open == close){
                ans = max(ans,2*open);
            }
            
            if(close<open){
                close = 0;
                open = 0;
            }
            
        }
        return ans ;
        /*
        Time : O(N)
        Space : O(1)
        */
}
int main() {
    string s = "((())))()()" ;
    cout<<method_2(s)<<endl;
    return 0;
}