#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*
    valid expression
    https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1
*/
bool isvalid(string exp){
    stack<char> st ;
    int len = exp.size();
    for(int i = 0;i<len;i++){
        char ch = exp[i];
        if(ch == '(' || ch == '[' || ch == '{'){
            st.push(ch);
        }
        else{
            if(st.empty()) return false;
            else if(ch == '}'){
                if(st.top() == '{'){
                    st.pop();
                }
                else return false;
            }
            else if(ch == ']'){
                if(st.top() == '['){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else{
                if(st.top() == '('){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
    }
    if(st.empty()) return true;
    return false;
}
int main() {
    string exp = "{([])}";
    if(isvalid(exp)){
        cout<<"expression is valid"<<endl;
    }
    else{
        cout<<"No not valid!";
    }
    return 0;
}