#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*
    implementing stack using deque
    https://www.geeksforgeeks.org/implement-stack-queue-using-deque/
*/
class stack_1{
    deque<int> dq ;
    public:
    void push_(int data){
        cout<<data<<": inserted"<<endl;
        dq.push_back(data);
    }

    void pop_(){
        if(dq.size() == 0){
            cout<<"stack is emty"<<endl;
        }
        int x = dq.back() ;
        dq.pop_back() ;
        cout<<x<<" : deleted"<<endl;

    }

};
class queue_1{
    deque<int> dq ;
    public:
    void push_(int data){
        dq.push_back(data) ;
        cout<<data<<" : inserted"<<endl;
    }

    void pop_(){
        if(dq.size() == 0){
            cout<<"queue is empty"<<endl;
        }
        int x = dq.front() ;
        dq.pop_front() ;
        cout<<x<<" : poped"<<endl;
    }

};
int main() {

    cout<<"stack"<<endl;
    stack_1 s1 ;
    s1.push_(1) ;
    s1.push_(2) ;
    s1.pop_() ;

    cout<<"queue"<<endl ;
    queue_1 q1 ;
    q1.push_(1) ;
    q1.push_(2) ;
    q1.pop_();

    return 0;
}