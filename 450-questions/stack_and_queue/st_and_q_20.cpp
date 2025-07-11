#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*
    implement stack using two queues 

*/
class stack_1{
    queue<int> q1,q2 ;
    public:
    void push_(int data){
        q1.push(data) ;
        cout<<data<<" : is inserted"<<endl;
    }

    void pop_(){
        if(q1.size() == 0){
            cout<<"empty"<<endl;
            return ;
        }
        while(q1.size()!=1){
            q2.push(q1.front()) ;
            q1.pop() ;
        }
        while(q2.size()!=0){
            q1.push(q2.front()) ;
            q2.pop() ;
        }
        int x = q1.front() ;
        cout<<x<<" : poped"<<endl;
        q1.pop() ;

    }

};
class stack_2{
    queue<int> q1,q2 ;
    public:
    void push_(int data){
        while(q1.size()!=0){
            q2.push(q1.front()) ;
            q1.pop() ;
        }
        q1.push(data) ;
        while(q2.size()!=0){
            q1.push(q2.front()) ;
            q2.pop() ;
        }
        cout<<data<<" : inserrted"<<endl;

    }

    void pop_(){
        if(q1.size() == 0){
            cout<<"empty"<<endl;
        }
        int x = q1.front() ;
        cout<<x<<" : poped"<<endl;
        q1.pop();
    }

};
int main() {

    stack_1 s1;
    s1.push_(1) ;
    s1.push_(2) ;
    s1.push_(3) ;
    s1.pop_() ;
    s1.pop_();

    stack_2 s2;
    s2.push_(1) ;
    s2.push_(2) ;
    s2.push_(3) ;
    s2.pop_() ;
    s2.pop_();

    return 0;
}