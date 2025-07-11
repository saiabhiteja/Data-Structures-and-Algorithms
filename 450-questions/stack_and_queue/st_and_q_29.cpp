#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*
interleaving queue
https://www.geeksforgeeks.org/interleave-first-half-queue-second-half/
*/
void display(queue<int> q ){
    while(q.size()!=0){
        cout<<q.front()<<" ";
        q.pop() ;
    }
    cout<<endl;
}
void method_1(queue<int>& q){
    vec temp ;
    while(q.size()!=0){
        temp.push_back(q.front()) ;
        q.pop() ;
    }
    reverse(temp.begin(),temp.end());
    int n = temp.size() ;
    vec first_half,second_half ;
    for(int i = 0;i<n;i++){
        if(i<(n/2)){
            first_half.push_back(temp[i]);
        }
        else{
            second_half.push_back(temp[i]) ;
        }
    }
    reverse(second_half.begin(),second_half.end());
    vec ans ;
    for(int i = 0;i<(n/2);i++){
        ans.push_back(first_half[i]) ;
        ans.push_back(second_half[i]);
    }
    reverse(ans.begin(),ans.end()) ;
    for(int i: ans){
        q.push(i);
    }

    /*
    Time : O(N)
    Space : O(N)
    */

}
void method_2(queue<int>& q){
    //using stack
    stack<int> st ;
    int n = q.size() ;
    //step-1 push first half back 
    for(int i = 0;i<(n/2);i++){
        q.push(q.front()) ;
        q.pop() ;
    }

    //second half into stack
    for(int i = 0;i<(n/2);i++){
        st.push(q.front()) ;
        q.pop() ;
    }

    //empty stack
    while(st.size()!=0){
        q.push(st.top()) ;
        st.pop() ;
    }
    //first half back side again
    for(int i = 0;i<(n/2);i++){
        q.push(q.front()) ;
        q.pop() ;
    }

    //second half again into stack
    for(int i = 0;i<(n/2);i++){
        st.push(q.front()) ;
        q.pop() ;
    }

    //interleave now
    while(st.size()!= 0){
        q.push(q.front()) ;
        q.pop() ;
        q.push(st.top()) ;
        st.pop() ;
    }


}
int main() {
    queue<int> q ;
    q.push(11) ;
    q.push(12) ;
    q.push(13) ;
    q.push(14) ;
    q.push(15) ;
    q.push(16) ;
    q.push(17) ;
    q.push(18);
    q.push(19) ;
    q.push(20) ;
    display(q) ;
    method_2(q) ;
    display(q);
    return 0;
}