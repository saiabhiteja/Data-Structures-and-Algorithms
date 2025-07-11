#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*
    inserting at bottom of a stack
*/

void display(stack<int> st){
    while(st.size()!=0){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

void method_1(stack<int>& st,int data){
    stack<int> st1 ;
    while(st.size()!=0){
        int x = st.top();
        st.pop() ;
        st1.push(x) ;
    }
    st.push(data) ;
    while(st1.size()!=0){
        int x = st1.top() ;
        st1.pop() ;
        st.push(x) ;
    }
    /*
    Time : O(N)
    Space : O(N)
    */
}
void insert_at_back(stack<int>& st,int data){
    if(st.size() == 0){
        st.push(data) ;
        return ;
    }
    int temp = st.top() ;
    st.pop() ;
    insert_at_back(st,data) ;
    st.push(temp) ;
    /*
    Time : O(N)
    Space : O(N) //recursive stack
    */
}
int main() {

    stack<int> st ;
    st.push(5) ;
    st.push(4) ;
    st.push(3) ;
    display(st) ;

    insert_at_back(st,1) ;
    display(st);


    return 0;
}