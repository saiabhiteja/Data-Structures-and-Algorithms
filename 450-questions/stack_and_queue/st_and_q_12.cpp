#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
/*
    evaluvating postfix expression
*/
int get_num(char ch){
    return (ch-'0');
}
bool isnum(char ch){
    return (ch>='0' && ch<='9');
}
int operation(int x1,int x2,char op){
    if(op == '+'){
        return (x1+x2) ;
    }
    else if(op == '-'){
        return (x1-x2);
    }
    else if(op == '*'){
        return (x1*x2) ;
    }
    else if (op == '^'){
        return pow(x1,x2);
    }
    else{
        return (x1/x2) ;
    }
}
int value(string s){
    stack<int> st ;
    cout<<s<<endl;
    for(char ch : s){
        if(isnum(ch)){
            st.push(get_num(ch)) ;
        }
        else{
            int x1 = st.top() ;
            st.pop() ;
            int x2 = st.top() ;
            st.pop() ;
            int ans = operation(x1,x2,ch) ;
            st.push(ans) ;
        }
    }
    return st.top() ;
    /*
    Time : O(N)
    Space : O(N)
    */

}

int main() {
    cout<<value("24+46+*");
    return 0;
}