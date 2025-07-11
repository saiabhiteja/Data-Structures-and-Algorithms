#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
/*
    Expression contains redundant bracket or not
    https://www.geeksforgeeks.org/expression-contains-redundant-bracket-not/
*/
bool reducatant_brackets(string s){
    stack<char> st ;
    for(char ch : s){
        if(ch == ')'){
            if(st.top() == '('){
                //cout<<"Yes"<<endl;
                return true ;
            }
            else{
                bool flag = true ;
                while( st.size()!=0 && st.top()!='('){
                    char c = st.top() ;
                    st.pop() ;
                    if(c == '+'||c == '-'||c == '*' || c=='/'){
                        flag = false ;
                    }
                }
                if(flag){
                    //cout<<"Yes"<<endl;
                    return true ;
                }
                else{
                    //st.top() == ')'
                    st.pop() ;
                }
            }

        }
        else{
            st.push(ch) ;
        }
    }
    return false;
    /*
    Time : O(N)
    Space : O(N)
    */
}
int main() {
    if(reducatant_brackets("(((a+b))+(c))")){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}