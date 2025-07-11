#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*
    reversing given stack
*/
void display(stack<int> st){
    while(st.size()!=0){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

void method_1(stack<int>& st){
    vec temp ;
    while(st.size()!=0){
        temp.push_back(st.top()) ;
        st.pop() ;
    }
    for(int i: temp){
        st.push(i) ;
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

void method_2(stack<int>& st){
    if(st.size() <= 1){
        return ;
    }
    int temp = st.top() ;
    st.pop() ;
    method_2(st) ;
    insert_at_back(st,temp);
    /*
    Time : O(N^2)
    Space : O(N)
    */
}
int main() {
    stack<int> st ;
    st.push(2) ;
    st.push(3) ;
    st.push(4) ;
    st.push(5) ;
    display(st) ;
    method_2(st) ;
    display(st);
    return 0;
}