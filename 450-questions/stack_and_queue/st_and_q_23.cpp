#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*
    implement queue using stack
    https://practice.geeksforgeeks.org/problems/queue-using-two-stacks/1
*/
class queue_1{
    stack<int> s1,s2 ;
    public: 
    void push_(int data){
        cout<<data<<" : inserted"<<endl;
        s1.push(data) ;
    }

    void pop_(){
        if(s1.size() == 0){
            cout<<"queue is empty"<<endl;
        }
        while(s1.size()!=1){
            s2.push(s1.top()) ;
            s1.pop() ;
        }
        int x = s1.top() ;
        s1.pop() ;
        while(s2.size()!=0){
            s1.push(s2.top()) ;
            s2.pop() ;
        }
        cout<<x<<" : poped"<<endl;
    }

};
class queue_2{
    stack<int> s1,s2 ;
    public:
    void push_(int data){
        while(s1.size() != 0){
            s2.push(s1.top()) ;
            s1.pop() ;
        }
        s1.push(data) ;
        cout<<data<<": inserted"<<endl;

        while(s2.size()!=0){
            s1.push(s2.top());
            s2.pop() ;
        }

    }

    void pop_(){

        if(s1.size() == 0){
            cout<<"stack is empty"<<endl;
            return ;
        }
        int x = s1.top() ;
        cout<<x<<": poped"<<endl;
        s1.pop();

    }

};
int main() {

    queue_1 q ;
    q.push_(12) ;
    q.push_(13) ;
    q.push_(14) ;
    q.pop_() ;
    q.pop_() ;

    cout<<"----"<<endl ;
    queue_2 q2 ;
    q2.push_(12) ;
    q2.push_(13) ;
    q2.push_(14) ;
    q2.pop_() ;
    q2.pop_();

    return 0;
}