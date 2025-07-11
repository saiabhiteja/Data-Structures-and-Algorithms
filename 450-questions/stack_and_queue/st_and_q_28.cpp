#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*
    reverse first k elements in a queue
*/
void display(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}
void method_1(queue<int>& q,int k){
    vec temp ;
    while( !q.empty()){
        temp.push_back(q.front()) ;
        q.pop() ;
    }
    reverse(temp.begin(),temp.begin()+k) ;
    for(int i : temp){
        q.push(i);
    }
    /*
    Time : O(k)
    Space : O(K)
    */
}

void method(queue<int>& q){
    if(q.size() <= 1){
        return ;
    }
    int temp = q.front();
    q.pop() ;
    method(q);
    q.push(temp);
    /*
    Time : O(N)
    Space : O(N)
    */
}
void method_2(queue<int>& q,int k){
    queue<int>q_temp ,ans;
    for(int i = 0;i<k;i++){
        q_temp.push(q.front()) ;
        q.pop() ;
    }
    method(q_temp) ;
    for(int i = 0;i<k;i++){
        ans.push(q_temp.front());
        q_temp.pop() ;
    }
    while(q.size()!=0){
        ans.push(q.front());
        q.pop() ;
    }
    q = ans ;
    /*
    Time : O(N)
    Space : O(N)
    */
}
int main() {
    queue<int> q ;
    q.push(1) ;
    q.push(2) ;
    q.push(3) ;
    q.push(4) ;
    q.push(5) ;
    display(q) ;
    method_2(q,3) ;
    display(q);
    return 0;
}