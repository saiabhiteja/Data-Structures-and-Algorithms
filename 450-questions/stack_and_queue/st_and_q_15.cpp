#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*
    sort a stack
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
    sort(temp.begin(),temp.end()) ;
    for(int i:temp){
        st.push(i);
    }
    /*
    Time : O(N)+O(N)+O(NlogN)
    Space : O(N)
    */
}

void insert_crct_pos(stack<int>& st,int data){
    if(st.size() == 0 || st.top()<data){
        st.push(data) ;
        return ;
    }
    int temp = st.top() ;
    st.pop();
    insert_crct_pos(st,data) ;
    st.push(temp) ;
}
void method_2(stack<int>& st){
    if(st.size()<=1){
        return ;
    }
    int temp = st.top() ;
    st.pop() ;
    method_2(st) ;
    insert_crct_pos(st,temp) ;
    /*
    Time : O(N^2)
    space : O(N) //recursive stack
    */

}
int main() {
    stack<int> st ;
    st.push(96) ;
    st.push(69) ;
    st.push(76) ;
    st.push(26) ;
    display(st) ;
    method_2(st) ;
    display(st);

    return 0;
}