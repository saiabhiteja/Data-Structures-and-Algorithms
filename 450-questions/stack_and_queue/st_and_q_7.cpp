#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*
reversing a string using stack
*/
string rev_str(string s){
    string ans = "";
    stack<char> st ;
    for(char ch: s){
        st.push(ch);
    }
    while(st.size()!=0){
        char ch = st.top();
        ans.push_back(ch);
        st.pop();
    }
    return ans;
    /*
    Time : O(N)
    Space : O(N)
    */
}

int main() {
    cout<<rev_str("saiabhitejA")<<endl;
    return 0;
}