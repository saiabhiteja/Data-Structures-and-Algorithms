#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*
    evaluvate given expression
    https://www.geeksforgeeks.org/arithmetic-expression-evalution/#:~:text=The%20stack%20organization%20is%20very,i.e.%2C%20A%20%2B%20B).
*/
int get_num(char ch){
    return (ch-'0');
}
bool isnum(char ch){
    return (ch>='0' && ch<='9');
}
int preference(char ch , bool instack){
    if(ch == '+' || ch == '-'){
        return instack == true? 2:1 ; //since associativity is left to right
    }
    else if(ch == '*'|| ch == '/'){
        return instack == true ? 4:3 ; //same left to right
    }
    else if(ch == '^'){
        return instack == true? 5:6 ; //since right to left
    }
    else if(ch == '('){
        return instack == true?0:7 ; //just for adjusting brackets
    }
    return 0 ; //closing bracket case
}
string infix_to_postfix(string s){
    string postfix = "" ;
    stack<char> st ;
    for(char ch: s){
        if(isnum(ch)){
            postfix.push_back(ch) ;
        }
        else{
            if(ch == ')'){
                while(st.size()!= 0 && st.top()!='('){
                    postfix.push_back(st.top()) ;
                    st.pop() ;
                }
                st.pop() ;
            }
            else{
                while(st.size()!=0 && preference(st.top(),true)>= preference(ch,false)){
                
                postfix.push_back(st.top()) ;
                st.pop() ;
            }
            st.push(ch) ;
            }
        }
    }
    while(st.size()!=0){
        
        postfix.push_back(st.top());
        st.pop();
    }
    return postfix ;
    /*
    Time : O(N)
    Space : O(N)
    */
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
    s = infix_to_postfix(s) ;
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
    string s = "(2+4)*(4+6)" ;
    cout<<value(s)<<endl;
    return 0;
}